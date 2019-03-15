/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
*
* val: value to store in the node.
* next: pointer to the next node
*
* returns: pointer to a new node
*/
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
*
* list: pointer to pointer to Node
*/
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
*
* list: pointer to pointer to Node
*
* returns: int or -1 if the list is empty
*/
int pop(Node **list) {

    Node* first_node = *list;

    // If the first element of the list is NULL, return -1
    if (first_node == NULL) return -1;

    // Otherwise, fetch the first element and change list to point to second.
    *list = first_node -> next;
    return first_node -> val;

}


/* Adds a new element to the beginning of the list.
*
* list: pointer to pointer to Node
* val: value to add
*/
void push(Node **list, int val) {

    Node* new_node;
    new_node = make_node(val, *list);
    *list = new_node;

}


/* Removes the first element with the given value
*
* Frees the removed node. TODO
*
* list: pointer to pointer to Node
* val: value to remove
*
* returns: number of nodes removed
*/
int remove_by_value(Node **list, int val) {

    Node* current = *list;
    Node* last = NULL;
    int num_removed = 0;

    while (current != NULL) {

      if (current -> val == val) {

        // Remove the current node from list if it matches
        last -> next = current -> next;
        num_removed++;
        //TODO free current

      }

      // Iterate along list
      last = current;
      current = current -> next;

    }

    return num_removed;
}


/* Reverses the elements of the list.
*
* Does not allocate or free nodes.
*
* list: pointer to pointer to Node
*/
void reverse(Node **list) {

    Node* last = NULL;
    Node* current = *list;
    Node* next;

    while (current != NULL) {

      next = current -> next;
      current -> next = last;

      // Move along list
      last = current;
      current = next;

    }

    // Return pointer to last non-null node
    *list = last;

}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    // Expect [ 1 2 3 4 ]
    Node **list = &head;
    print_list(list);

    // Expect [ 2 3 4 ]
    int retval = pop(list);
    print_list(list);

    // Expect [ 11 2 3 4 ]
    push(list, retval+10);
    print_list(list);

    // Expect [ 11 2 4 ]
    remove_by_value(list, 3);
    print_list(list);

    // Expect [ 11 2 4 ]
    remove_by_value(list, 7);
    print_list(list);

    // Expect [ 4 2 11 ]
    reverse(list);
    print_list(list);
}
