//#include "Models.c"
#include "linked_list_2_way.h"
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
		if (tmp->next == NULL) {
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


	// Find the last element in list
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
		*head = (OneLinkedList*)malloc(sizeof(OneLinkedList));
		(*head)->val = NULL;

		nextNode->next = *head; // Reassign the new node next value to head

		(*head)->next = nextNode;
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


void main() {
	//OneLinkedList* head = NULL;

	//oneLinkedList_Insert(&head, 4);
	//oneLinkedList_Insert(&head, 5);
	//oneLinkedList_Insert(&head, 6);
	//oneLinkedList_Insert(&head, 1);
	//oneLinkedList_Insert(&head, 9);

	//OneLinkedList* searched = oneLinkedList_SearchForKey(&head, 6);
	//oneLinkedList_DeleteThisNode(&head, searched);

	//#pragma region OneLinkedList - Cycled test
	//OneLinkedList* head_c = NULL;

	//oneLinkedList_Insert_Cycle(&head_c, 4);
	//oneLinkedList_Insert_Cycle(&head_c, 5);
	//oneLinkedList_Insert_Cycle(&head_c, 6);
	//oneLinkedList_Insert_Cycle(&head_c, 1);
	//oneLinkedList_Insert_Cycle(&head_c, 9);

	//OneLinkedList* searched_c = oneLinkedList_SearchForKey(&head_c, 6);
	//oneLinkedList_DeleteThisNode(&head_c, searched_c);
	//#pragma endregion

	TwoLinkedList* t = NULL;

	TwoWayLinkedList_Insert_Cycle(&t, 2);
	TwoWayLinkedList_Insert_Cycle(&t, 6);
	TwoWayLinkedList_Insert_Cycle(&t, 1);
	TwoWayLinkedList_Insert_Cycle(&t, 4);
	TwoWayLinkedList_Insert_Cycle(&t, 9);

	TwoLinkedList* t1 = TwoWayLinkedList_SearchForKey(&t, 1);
	TwoWayLinkedList_DeleteThisNode(&t, t1);



}