<h2><a href="https://leetcode.com/problems/intersection-of-two-linked-lists">160. Intersection of Two Linked Lists</a></h2><h3>Easy</h3><hr><p>Given the heads of two singly linked-lists <code>headA</code> and <code>headB</code>, return <em>the node at which the two lists intersect</em>. If the two linked lists have no intersection at all, return <code>null</code>.</p>

<p>For example, the following two linked lists begin to intersect at node <code>c1</code>:</p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/05/160_statement.png" style="width: 500px; height: 162px;" />
<p>The test cases are generated such that there are no cycles anywhere in the entire linked structure.</p>

<p><strong>Note</strong> that the linked lists must <strong>retain their original structure</strong> after the function returns.</p>

<p><strong>Custom Judge:</strong></p>

<p>The inputs to the <strong>judge</strong> are given as follows (your program is <strong>not</strong> given these inputs):</p>

<ul>
	<li><code>intersectVal</code> - The value of the node where the intersection occurs. This is <code>0</code> if there is no intersected node.</li>
	<li><code>listA</code> - The first linked list.</li>
	<li><code>listB</code> - The second linked list.</li>
	<li><code>skipA</code> - The number of nodes to skip ahead in <code>listA</code> (starting from the head) to get to the intersected node.</li>
	<li><code>skipB</code> - The number of nodes to skip ahead in <code>listB</code> (starting from the head) to get to the intersected node.</li>
</ul>

<p>The judge will then create the linked structure based on these inputs and pass the two heads, <code>headA</code> and <code>headB</code> to your program. If you correctly return the intersected node, then your solution will be <strong>accepted</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/05/160_example_1_1.png" style="width: 500px; height: 162px;" />
<pre>
<strong>Input:</strong> intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
<strong>Output:</strong> Intersected at &#39;8&#39;
<strong>Explanation:</strong> The intersected node&#39;s value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
- Note that the intersected node&#39;s value is not 1 because the nodes with value 1 in A and B (2<sup>nd</sup> node in A and 3<sup>rd</sup> node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3<sup>rd</sup> node in A and 4<sup>th</sup> node in B) point to the same location in memory.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/05/160_example_2.png" style="width: 500px; height: 194px;" />
<pre>
<strong>Input:</strong> intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
<strong>Output:</strong> Intersected at &#39;2&#39;
<strong>Explanation:</strong> The intersected node&#39;s value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/05/160_example_3.png" style="width: 300px; height: 189px;" />
<pre>
<strong>Input:</strong> intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
<strong>Output:</strong> No intersection
<strong>Explanation:</strong> From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes of <code>listA</code> is in the <code>m</code>.</li>
	<li>The number of nodes of <code>listB</code> is in the <code>n</code>.</li>
	<li><code>1 &lt;= m, n &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= skipA &lt;= m</code></li>
	<li><code>0 &lt;= skipB &lt;= n</code></li>
	<li><code>intersectVal</code> is <code>0</code> if <code>listA</code> and <code>listB</code> do not intersect.</li>
	<li><code>intersectVal == listA[skipA] == listB[skipB]</code> if <code>listA</code> and <code>listB</code> intersect.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you write a solution that runs in <code>O(m + n)</code> time and use only <code>O(1)</code> memory?


## Approach

This solution transforms the problem into a **Linked List Cycle Detection** problem using **Floyd's Tortoise and Hare Algorithm**.

The key observation is:

- If the two linked lists intersect, they share all nodes after the intersection point.
- By connecting the tail of the first list to the head of the second list, an intersection creates a **cycle**.
- If the lists do not intersect, no cycle is formed.

The algorithm consists of three steps:

1. Traverse the first list to find its last node.
2. Connect the last node of the first list to the head of the second list.
3. Use Floyd's Cycle Detection algorithm to determine whether a cycle exists.
   - If a cycle is found, locate its entry point.
   - The entry point is exactly the intersection node.
4. Restore the original linked list by removing the temporary connection.

### Example

Input:

```
List A:

4 → 1
      \
       8 → 4 → 5

List B:

5 → 6 → 1
          \
           8 → 4 → 5
```

Temporarily connect the tail of List A to the head of List B:

```
4 → 1
      \
       8 → 4 → 5
                |
                v
5 → 6 → 1 ------┘
```

A cycle is formed.

Using Floyd's algorithm:

- The fast and slow pointers meet inside the cycle.
- Reset one pointer to the beginning.
- Move both pointers one step at a time.
- Their meeting point is the intersection node.

Output:

```
8
```

---

## Algorithm

1. Traverse List A to find its last node.
2. Connect the last node to the head of List B.
3. Initialize:
   - `slow = headA`
   - `fast = headA`
4. Run Floyd's Cycle Detection:
   - Move `slow` one step.
   - Move `fast` two steps.
5. If the pointers meet:
   - Reset `fast` to `headA`.
   - Move both pointers one step at a time.
   - Their meeting point is the intersection node.
6. Restore the original list by setting the last node's `next` pointer to `NULL`.
7. Return the intersection node if found; otherwise return `NULL`.

---

## Complexity Analysis

- **Time Complexity:** `O(m + n)`
  - One traversal to find the tail of List A and one traversal using Floyd's algorithm.

- **Space Complexity:** `O(1)`
  - Only a constant number of pointers are used.

---

## Key Idea

By temporarily linking the tail of the first list to the head of the second list, the intersection problem is converted into a cycle detection problem. If the lists intersect, the shared nodes form a cycle, and Floyd's Cycle Detection algorithm efficiently identifies the cycle's entry point, which is precisely the intersection node. The temporary modification is undone before returning, preserving the original structure of both linked lists.
