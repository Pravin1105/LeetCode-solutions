<h2><a href="https://leetcode.com/problems/search-in-a-binary-search-tree/">783. Search in a Binary Search Tree</a></h2><h3>Easy</h3><hr><p>You are given the <code>root</code> of a binary search tree (BST) and an integer <code>val</code>.</p>

<p>Find the node in the BST that the node&#39;s value equals <code>val</code> and return the subtree rooted with that node. If such a node does not exist, return <code>null</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/12/tree1.jpg" style="width: 422px; height: 302px;" />
<pre>
<strong>Input:</strong> root = [4,2,7,1,3], val = 2
<strong>Output:</strong> [2,1,3]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/12/tree2.jpg" style="width: 422px; height: 302px;" />
<pre>
<strong>Input:</strong> root = [4,2,7,1,3], val = 5
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 5000]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>7</sup></code></li>
	<li><code>root</code> is a binary search tree.</li>
	<li><code>1 &lt;= val &lt;= 10<sup>7</sup></code></li>
</ul>

## Approach

A **Binary Search Tree (BST)** has the following property:

- All values in the **left subtree** are smaller than the current node.
- All values in the **right subtree** are larger than the current node.

Using this property, the search can ignore half of the remaining tree at each step.

For the current node:

- If its value is equal to the target, the required node has been found.
- If the target is smaller, recursively search the left subtree.
- If the target is larger, recursively search the right subtree.

If the traversal reaches a `NULL` node, the target does not exist in the tree.

### Example

Input:

```
        4
       / \
      2   7
     / \
    1   3

Target = 2
```

Search path:

```
4

↓

2
```

Output:

```
      2
     / \
    1   3
```

---

## Algorithm

1. If the current node is `NULL`, return `NULL`.
2. Compare the current node's value with the target:
   - If equal, return the current node.
   - If the target is smaller, recursively search the left subtree.
   - If the target is larger, recursively search the right subtree.
3. Return the result of the recursive search.

---

## Complexity Analysis

- **Time Complexity:** `O(h)`
  - `h` is the height of the tree.
  - Best/Average case (balanced BST): `O(log n)`
  - Worst case (skewed BST): `O(n)`

- **Space Complexity:** `O(h)`
  - Due to the recursion stack.
  - Best/Average case: `O(log n)`
  - Worst case: `O(n)`

---

## Key Idea

The Binary Search Tree property allows the search to eliminate one entire subtree at every step. Instead of traversing all nodes, the algorithm follows only the path where the target can exist, making the search significantly more efficient than a general binary tree traversal.
