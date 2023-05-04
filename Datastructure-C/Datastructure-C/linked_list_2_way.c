#include "linked_list_2_way.h"
#include <stdio.h>
#include <stdlib.h>

#pragma region TwoLinkedList - NonCycle 
// TwoLinkedList_Insert Is only used for nonCycle oneway linked list
// Insert at the end of list 
void TwoWayLinkedList_Insert(TwoLinkedList** head, int newValue) {
	TwoLinkedList* nextNode = (TwoLinkedList*)malloc(sizeof(TwoLinkedList)); // Allocate memory to the new struct
	TwoLinkedList* last = *head;

	nextNode->val = newValue;
	nextNode->next = NULL;
	nextNode->prev = NULL;


	if (*head == NULL) {
		*head = nextNode;
		return;
	}

	// Find the last element in list
	while (last->next != NULL) {
		last = last->next;
	}
	nextNode->prev = last;
	last->next = nextNode;
	return;
}

// Can be used for both cycle and non-cycled oneways linked lists
void TwoWayLinkedList_DeleteThisNode(TwoLinkedList** head, TwoLinkedList* node) {
	TwoLinkedList* tmp = *head;

	// Find the element before the searched node
	while (tmp->next != node) {
		// If the node does not exist
		if (tmp->next == NULL) {
			return NULL;
		}
		tmp = tmp->next;
	}
	node->next->prev = tmp;
	tmp->next = node->next;
	free(node);
}
// Can be used for both cycle and non-cycled oneways linked lists
TwoLinkedList* TwoWayLinkedList_SearchForKey(TwoLinkedList** head, int key) {
	TwoLinkedList* node = *head;

	// Search for the key
	while (node->val != key) {
		if (node->next == NULL || node->next->val == NULL) {
			return NULL;
		}
		node = node->next;
	}
	return node;
}

#pragma endregion

#pragma region TwoWayLinkedList - Cycle
// TwoLinkedList_Insert_Cycle - Will insert a new node new as cycle 
// Insert at the end of list
void TwoWayLinkedList_Insert_Cycle(TwoLinkedList** head, int newValue) {
	TwoLinkedList* nextNode = (TwoLinkedList*)malloc(sizeof(TwoLinkedList)); // Allocate memory to the new struct
	TwoLinkedList* last = *head;

	nextNode->val = newValue;

	if (*head == NULL) {
		*head = (TwoLinkedList*)malloc(sizeof(TwoLinkedList));
		(*head)->val = NULL;

		// Set the new node's next and prev
		nextNode->next = *head;
		nextNode->prev = *head;

		// Set the head's next and prev
		(*head)->next = nextNode;
		(*head)->prev = nextNode;
		return;
	}

	// Find the last element in list
	while (last->next != *head) {
		last = last->next;
	}

	nextNode->next = *head; // The newNode's next is the head
	nextNode->prev = last; // NewNode's prev is the last element 
	last->next = nextNode; // The last elemen's next is the new element 
	(*head)->prev = nextNode; // The head's prev is the new node 
	return;
}

#pragma endregion
