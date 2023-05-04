#include "linked_list_2_way.h"
#include "linked_list_1_way.h"
#include <stdio.h>
#include <stdlib.h>

void main() {
	OneLinkedList* head = NULL;

	oneLinkedList_Insert(&head, 4);
	oneLinkedList_Insert(&head, 5);
	oneLinkedList_Insert(&head, 6);
	oneLinkedList_Insert(&head, 1);
	oneLinkedList_Insert(&head, 9);

	OneLinkedList* searched = oneLinkedList_SearchForKey(&head, 6);
	oneLinkedList_DeleteThisNode(&head, searched);

	#pragma region OneLinkedList - Cycled test
	OneLinkedList* head_c = NULL;

	oneLinkedList_Insert_Cycle(&head_c, 4);
	oneLinkedList_Insert_Cycle(&head_c, 5);
	oneLinkedList_Insert_Cycle(&head_c, 6);
	oneLinkedList_Insert_Cycle(&head_c, 1);
	oneLinkedList_Insert_Cycle(&head_c, 9);

	OneLinkedList* searched_c = oneLinkedList_SearchForKey(&head_c, 6);
	oneLinkedList_DeleteThisNode(&head_c, searched_c);
	#pragma endregion

	TwoLinkedList* t = NULL;

	TwoWayLinkedList_Insert_Cycle(&t, 2);
	TwoWayLinkedList_Insert_Cycle(&t, 6);
	TwoWayLinkedList_Insert_Cycle(&t, 1);
	TwoWayLinkedList_Insert_Cycle(&t, 4);
	TwoWayLinkedList_Insert_Cycle(&t, 9);

	TwoLinkedList* t1 = TwoWayLinkedList_SearchForKey(&t, 1);
	TwoWayLinkedList_DeleteThisNode(&t, t1);



}