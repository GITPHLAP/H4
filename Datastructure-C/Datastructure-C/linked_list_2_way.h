#include "Models.h"
#pragma once
void TwoWayLinkedList_Insert(TwoLinkedList** head, int newValue);
void TwoWayLinkedList_DeleteThisNode(TwoLinkedList** head, TwoLinkedList* node);
TwoLinkedList* TwoWayLinkedList_SearchForKey(TwoLinkedList** head, int key);
void TwoWayLinkedList_Insert_Cycle(TwoLinkedList** head, int newValue);