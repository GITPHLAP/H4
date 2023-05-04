#pragma once
typedef struct OneLinkedList {
	int val;
	struct OneLinkedList* next;
} OneLinkedList;

typedef struct TwoLinkedList {
	int val;
	struct TwoLinkedList* next;
	struct TwoLinkedList* prev;
} TwoLinkedList;