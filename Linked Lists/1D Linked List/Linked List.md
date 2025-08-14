# Singly Linked List

 - Simplest form of linked list.
 - Each node contains data and a pointer to the next node.
 - Each node in a singly linked list is connected to the next node through a pointer and the last node points to null.
 - The first node is called the head, and the last node is called the tail.

 # Singly Linked List Representation

 - A singly linked list can be represented using a class or a structure.
 - Each node contains two fields: data and a pointer to the next node.
 - The head points to the first node, and the last node points to null.

```C++
struct Node{
    // data field
    int data;

    // pointer to the next node
    Node* next;

};
```

# Basic operation for Singly Linked List


| Operation | Operation Type | Description | Time Complexity | Space Complexity |
|-----------|---------------|-------------|-----------------|------------------|
| **Insertion** | At Beginning | Insert a new node at the start of a linked list. | O (1) | O (1) |
| | At the End | Insert a new node at the end of the linked list. | O (N) | O (1) |
| | At Specific Position | Insert a new node at a specific position in a linked list. | O (N) | O (1) |
| **Deletion** | From Beginning | Delete a node from the start of a linked list | O (1) | O (1) |
| | From the End | Delete a node at the end of a linked list. | O (N) | O (1) |
| | A Specific Node | Delete a node from a specific position of a linked list. | O (N) | O (1) |
| **Traversal** | | Traverse the linked list from start to end. | O (N) | O (1) |


