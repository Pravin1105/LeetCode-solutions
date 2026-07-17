<h2><a href="https://leetcode.com/problems/maximum-depth-of-binary-tree">104. Maximum Depth of Binary Tree</a></h2><h3>Easy</h3><hr><p>Given the <code>root</code> of a binary tree, return <em>its maximum depth</em>.</p>

<p>A binary tree&#39;s <strong>maximum depth</strong>&nbsp;is the number of nodes along the longest path from the root node down to the farthest leaf node.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg" style="width: 400px; height: 277px;" />
<pre>
<strong>Input:</strong> root = [3,9,20,null,null,15,7]
<strong>Output:</strong> 3
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [1,null,2]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

## Approach

The solution uses **Depth-First Search (DFS)** with recursion to compute the maximum depth of the binary tree.

The maximum depth of a tree is defined as the number of nodes along the **longest path** from the root node to any leaf node.

For every node:

- Recursively compute the maximum depth of its left subtree.
- Recursively compute the maximum depth of its right subtree.
- The depth of the current node is:

```text
1 + max(leftDepth, rightDepth)
```

The recursion terminates when a `NULL` node is reached, which contributes a depth of `0`.

### Example

Input:

```
        3
       / \
      9   20
         /  \
        15   7
```

Depth calculation:

```
Node 15 → 1
Node 7  → 1

Node 20 → 1 + max(1, 1) = 2

Node 9  → 1

Node 3  → 1 + max(1, 2) = 3
```

Output:

```
3
```

---

## Algorithm

1. If the current node is `NULL`, return `0`.
2. Recursively compute the maximum depth of the left subtree.
3. Recursively compute the maximum depth of the right subtree.
4. Return:
   ```
   1 + max(leftDepth, rightDepth)
   ```

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - Every node is visited exactly once.

- **Space Complexity:** `O(h)`
  - `h` is the height of the tree due to the recursion stack.
  - Worst case: `O(n)` for a skewed tree.
  - Best case (balanced tree): `O(log n)`.

---

## Key Idea

The depth of a node depends only on the maximum depth of its left and right subtrees. By recursively computing these depths and adding one for the current node, the algorithm efficiently determines the maximum depth of the entire binary tree.
