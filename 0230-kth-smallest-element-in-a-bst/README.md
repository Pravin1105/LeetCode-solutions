<h2><a href="https://leetcode.com/problems/kth-smallest-element-in-a-bst">230. Kth Smallest Element in a BST</a></h2><h3>Medium</h3><hr><p>Given the <code>root</code> of a binary search tree, and an integer <code>k</code>, return <em>the</em> <code>k<sup>th</sup></code> <em>smallest value (<strong>1-indexed</strong>) of all the values of the nodes in the tree</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/28/kthtree1.jpg" style="width: 212px; height: 301px;" />
<pre>
<strong>Input:</strong> root = [3,1,4,null,2], k = 1
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/28/kthtree2.jpg" style="width: 382px; height: 302px;" />
<pre>
<strong>Input:</strong> root = [5,3,6,2,4,null,null,1], k = 3
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is <code>n</code>.</li>
	<li><code>1 &lt;= k &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?</p>

## Approach

A **Binary Search Tree (BST)** has the property that:

- All values in the left subtree are smaller than the current node.
- All values in the right subtree are larger than the current node.

Because of this property, performing an **inorder traversal (Left → Root → Right)** visits the nodes in **ascending order**.

The solution performs an inorder traversal of the BST and stores the visited node values in a vector. Since the vector is sorted, the **kth smallest element** is simply the element at index `k - 1`.

### Example

Input:

```
        5
       / \
      3   6
     / \
    2   4
   /
  1

k = 3
```

Inorder Traversal:

```
1 → 2 → 3 → 4 → 5 → 6
```

The 3rd smallest element is:

```
3
```

---

## Algorithm

1. Create an empty vector.
2. Perform an inorder traversal of the BST:
   - Traverse the left subtree.
   - Store the current node's value.
   - Traverse the right subtree.
3. After traversal, the vector contains all node values in sorted order.
4. Return the element at index `k - 1`.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - Every node is visited exactly once during the inorder traversal.

- **Space Complexity:** `O(n)`
  - The vector stores all `n` node values.
  - The recursion stack requires `O(h)` space, where `h` is the height of the tree.

---

## Key Idea

An inorder traversal of a Binary Search Tree always produces the node values in **sorted order**. By storing this traversal in a vector, the kth smallest element can be directly accessed using its index, making the implementation simple and intuitive.
