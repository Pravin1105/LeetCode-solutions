import os
from pathlib import Path
from openai import OpenAI

# -------------------------------------------------
# Configuration
# -------------------------------------------------

REPO_ROOT = Path.cwd()

client = OpenAI(
    api_key=os.environ["OPENAI_API_KEY"]
)

# Only C++ solutions in your repository
CPP_EXTENSION = ".cpp"

# -------------------------------------------------
# Find all problem folders
# -------------------------------------------------

def get_problem_folders():
    folders = []

    for item in REPO_ROOT.iterdir():

        if not item.is_dir():
            continue

        if item.name.startswith("."):
            continue

        readme = item / "README.md"

        if readme.exists():
            folders.append(item)

    return folders


# -------------------------------------------------
# Find solution.cpp
# -------------------------------------------------

def get_solution(folder: Path):

    for file in folder.iterdir():

        if file.suffix == CPP_EXTENSION:
            return file

    return None


# -------------------------------------------------
# Skip already processed folders
# -------------------------------------------------

def already_has_approach(readme_path: Path):

    text = readme_path.read_text(
        encoding="utf-8"
    )

    return "# My Approach" in text


# -------------------------------------------------
# Generate Approach
# -------------------------------------------------

def generate(problem_name, solution_code):

    prompt = f"""
You are an expert competitive programmer.

Problem:

{problem_name}

Solution:

{solution_code}

Generate ONLY markdown.

Start with

---

# My Approach

Then generate

## Intuition

Explain the thought process.

## Algorithm

Explain the algorithm in numbered steps.

## Complexity

Time Complexity:

Space Complexity:

Do NOT include the code.

Do NOT repeat the problem statement.

Do NOT use markdown code blocks.
"""

    response = client.responses.create(
        model="gpt-5-mini",
        input=prompt,
    )

    return response.output_text.strip()


# -------------------------------------------------
# Append README
# -------------------------------------------------

def append(folder, text):

    readme = folder / "README.md"

    with open(
        readme,
        "a",
        encoding="utf-8"
    ) as f:

        f.write("\n\n")
        f.write(text)
        f.write("\n")


# -------------------------------------------------
# Main
# -------------------------------------------------

def main():

    folders = get_problem_folders()

    print(f"Found {len(folders)} folders")

    updated = 0

    for folder in folders:

        readme = folder / "README.md"

        if already_has_approach(readme):
            continue

        solution = get_solution(folder)

        if solution is None:
            continue

        code = solution.read_text(
            encoding="utf-8"
        )

        print(f"Generating: {folder.name}")

        approach = generate(
            folder.name,
            code,
        )

        append(folder, approach)

        updated += 1

    print(f"\nUpdated {updated} README files.")


if __name__ == "__main__":
    main()
