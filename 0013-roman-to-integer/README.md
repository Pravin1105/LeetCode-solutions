<h2><a href="https://leetcode.com/problems/roman-to-integer">13. Roman to Integer</a></h2><h3>Easy</h3><hr><p>Roman numerals are represented by seven different symbols:&nbsp;<code>I</code>, <code>V</code>, <code>X</code>, <code>L</code>, <code>C</code>, <code>D</code> and <code>M</code>.</p>

<pre>
<strong>Symbol</strong>       <strong>Value</strong>
I             1
V             5
X             10
L             50
C             100
D             500
M             1000</pre>

<p>For example,&nbsp;<code>2</code> is written as <code>II</code>&nbsp;in Roman numeral, just two ones added together. <code>12</code> is written as&nbsp;<code>XII</code>, which is simply <code>X + II</code>. The number <code>27</code> is written as <code>XXVII</code>, which is <code>XX + V + II</code>.</p>

<p>Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not <code>IIII</code>. Instead, the number four is written as <code>IV</code>. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as <code>IX</code>. There are six instances where subtraction is used:</p>

<ul>
	<li><code>I</code> can be placed before <code>V</code> (5) and <code>X</code> (10) to make 4 and 9.&nbsp;</li>
	<li><code>X</code> can be placed before <code>L</code> (50) and <code>C</code> (100) to make 40 and 90.&nbsp;</li>
	<li><code>C</code> can be placed before <code>D</code> (500) and <code>M</code> (1000) to make 400 and 900.</li>
</ul>

<p>Given a roman numeral, convert it to an integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;III&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong> III = 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;LVIII&quot;
<strong>Output:</strong> 58
<strong>Explanation:</strong> L = 50, V= 5, III = 3.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;MCMXCIV&quot;
<strong>Output:</strong> 1994
<strong>Explanation:</strong> M = 1000, CM = 900, XC = 90 and IV = 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 15</code></li>
	<li><code>s</code> contains only&nbsp;the characters <code>(&#39;I&#39;, &#39;V&#39;, &#39;X&#39;, &#39;L&#39;, &#39;C&#39;, &#39;D&#39;, &#39;M&#39;)</code>.</li>
	<li>It is <strong>guaranteed</strong>&nbsp;that <code>s</code> is a valid roman numeral in the range <code>[1, 3999]</code>.</li>
</ul>

## Approach

Each Roman numeral has a fixed integer value:

| Symbol | Value |
|:------:|------:|
| I | 1 |
| V | 5 |
| X | 10 |
| L | 50 |
| C | 100 |
| D | 500 |
| M | 1000 |

The solution first stores these mappings in a hash map for constant-time lookup.

The string is then traversed **from right to left**.

### Key Observation

In Roman numerals:

- If a symbol is **greater than or equal to** the symbol on its right, it is **added**.
- If a symbol is **smaller** than the symbol on its right, it is **subtracted**.

Examples:

```
VI

5 + 1 = 6
```

```
IV

5 - 1 = 4
```

Since we traverse from right to left, the value of the symbol to the right is already known, making it easy to determine whether to add or subtract the current symbol.

---

## Example

Input:

```
"MCMXCIV"
```

Traversal:

| Symbol | Operation | Total |
|:------:|:---------:|------:|
| V | +5 | 5 |
| I | -1 | 4 |
| C | +100 | 104 |
| X | -10 | 94 |
| M | +1000 | 1094 |
| C | -100 | 994 |
| M | +1000 | 1994 |

Output:

```
1994
```

---

## Algorithm

1. Store the value of each Roman numeral in a hash map.
2. Initialize the answer with the value of the last character.
3. Traverse the string from right to left.
4. For each character:
   - If its value is smaller than the value of the character to its right:
     - Subtract it from the answer.
   - Otherwise:
     - Add it to the answer.
5. Return the final answer.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - Each Roman numeral is processed exactly once.

- **Space Complexity:** `O(1)`
  - The hash map contains only the seven Roman numeral symbols, requiring constant extra space.

---

## Key Idea

Roman numerals use **subtractive notation**, where a smaller numeral placed before a larger one indicates subtraction. By traversing the string from right to left, the algorithm can determine whether each symbol should be added or subtracted by simply comparing it with its immediate right neighbor, resulting in a clean linear-time solution.
