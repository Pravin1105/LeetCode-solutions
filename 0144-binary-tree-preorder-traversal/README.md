<h2><a href="https://leetcode.com/problems/binary-tree-preorder-traversal/">144. Binary Tree Preorder Traversal</a></h2><h3>Easy</h3><hr><p>Given the <code>root</code> of a binary tree, return <em>the preorder traversal of its nodes&#39; values</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [1,null,2,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">[1,2,3]</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/08/29/screenshot-2024-08-29-202743.png" style="width: 200px; height: 264px;" /></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [1,2,3,4,5,null,8,null,null,6,7,9]</span></p>

<p><strong>Output:</strong> <span class="example-io">[1,2,4,5,6,7,3,8,9]</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/08/29/tree_2.png" style="width: 350px; height: 286px;" /></p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = []</span></p>

<p><strong>Output:</strong> <span class="example-io">[]</span></p>
</div>

<p><strong class="example">Example 4:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [1]</span></p>

<p><strong>Output:</strong> <span class="example-io">[1]</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 100]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Recursive solution is trivial, could you do it iteratively?</p>

## Approach

The solution performs a **Preorder Traversal** of the binary tree using **recursion**.

In a preorder traversal, the nodes are visited in the following order:

1. Visit the current node.
2. Traverse the left subtree.
3. Traverse the right subtree.

A helper function recursively processes each node and stores the visited values in a vector.

### Example

Input:

```
      1
       \
        2
       /
      3
```

Traversal order:

```
Visit 1

↓

Visit 2

↓

Visit 3
```

Output:

```
[1,2,3]
```

---

## Algorithm

1. Create an empty vector to store the traversal.
2. Define a recursive helper function:
   - If the current node is `NULL`, return.
   - Add the current node's value to the vector.
   - Traverse the left subtree.
   - Traverse the right subtree.
3. Call the helper function starting from the root.
4. Return the resulting vector.

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

Preorder traversal follows the **Root → Left → Right** order. By visiting the current node before recursively traversing its left and right subtrees, the algorithm generates the preorder sequence while visiting each node exactly once.
