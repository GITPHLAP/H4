#include "Models.h"
#pragma once
void oneLinkedList_Insert(OneLinkedList** head, int newValue);
void oneLinkedList_DeleteThisNode(OneLinkedList** head, OneLinkedList* node);
OneLinkedList* oneLinkedList_SearchForKey(OneLinkedList** head, int key);
void oneLinkedList_Insert_Cycle(OneLinkedList** head, int newValue);