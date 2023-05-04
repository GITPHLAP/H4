#include "linked_list_1_way.h"
#include <stdio.h>
#include <stdlib.h>

#pragma region OneLinkedList - NonCycle

// oneLinkedList_Insert Is only used for nonCycle oneway linked list
// Insert at the end of list 
void oneLinkedList_Insert(OneLinkedList** head, int newValue) {
	OneLinkedList* nextNode = (OneLinkedList*)malloc(sizeof(OneLinkedList)); // Allocate memory to the new struct
	OneLinkedList* last = *head;

	nextNode->val = newValue;
	nextNode->next = NULL;

	if (*head == NULL) {
		*head = nextNode;
		return;
	}

	// Find the last element in list
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = nextNode;
	return;
}

// Can be used for both cycle and non-cycled oneways linked lists
void oneLinkedList_DeleteThisNode(OneLinkedList** head, OneLinkedList* node) {
	OneLinkedList* tmp = *head;

	// Find the element before the searched node
	while (tmp->next != node) {
		// If the node does not exist
		// The or condition is for cycled list and it will be true when all elements has been looped through
		if (tmp->next == NULL || tmp->next == *head) { 
			return NULL;
		}
		tmp = tmp->next;
	}

	tmp->next = node->next;
	free(node);
}

// Can be used for both cycle and non-cycled oneways linked lists
OneLinkedList* oneLinkedList_SearchForKey(OneLinkedList** head, int key) {
	OneLinkedList* node = *head;


	// Find the searched key in linked list
	while (node->val != key) {
		if (node->next == NULL || node->next->val == NULL) {
			return NULL;
		}
		node = node->next;
	}
	return node;
}

#pragma endregion

#pragma region OneLinkedList - Cycle

// oneLinkedList_Insert_Cycle - Will insert a new node new as cycle 
// Insert at the end of list
void oneLinkedList_Insert_Cycle(OneLinkedList** head, int newValue) {
	OneLinkedList* nextNode = (OneLinkedList*)malloc(sizeof(OneLinkedList)); // Allocate memory to the new struct
	OneLinkedList* last = *head;

	nextNode->val = newValue;
	nextNode->next = *head;

	if (*head == NULL) {
		*head = (OneLinkedList*)malloc(sizeof(OneLinkedList)); // Initialize the head
		(*head)->val = NULL;

		nextNode->next = *head; // Reassign the new node next value to head

		(*head)->next = nextNode; // Set the heads next to the new node
		return;
	}

	// Find the last element in list
	while (last->next != *head) {
		last = last->next;
	}
	last->next = nextNode;
	return;
}

#pragma endregion
