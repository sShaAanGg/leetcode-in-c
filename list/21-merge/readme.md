# Merge Two Sorted Lists
- **Use a temp/dummy node to avoid handling the exception of the head node**.
- Use a pointer to the tail/current node to trace the last node of the merged list.
- Then simply traverse the two lists using list1, list2 pointers.
- When the loop ends, it means one or both of the lists are empty.
  - Append the rest of the non-empty list to the merged list by checking the pointer respectively.
- Return the temp/dummy node's next node as the head of the merged list.
