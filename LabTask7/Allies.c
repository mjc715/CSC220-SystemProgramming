#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char String[128];
typedef struct {
	String name;
	struct Node *next;
	struct Node *ally;
} Node;

typedef Node *NodePointer;
//--------------------------------------
void * Malloc(size_t Size) {

	void * Memory;
	
	if ((Memory = malloc(Size)) == NULL) {
		perror("Cannot malloc");
		exit(EXIT_FAILURE);
	} else {
		return Memory;
	}
}
//--------------------------------------
void Free(void ** Memory) {

	free(*Memory);
	*Memory = NULL;
}
//--------------------------------------
void PrintOut (NodePointer head) {
	while (head->next != NULL) {
		NodePointer ally = head->ally;
		printf("The best ally of %s is %s \n", head->name, ally->name);
		head = head->next;
	}
	printf("\n");
}
//-------------------------------------
NodePointer FindNode (NodePointer head, String word) {

	while (head->next != NULL && strcmp(head->name, word)) {
		head = head->next;
	}
	if (head != NULL)
		return head;
	else {
		printf("Didnt find nation");
		return NULL;
	}	
}
//-------------------------------------
void FreeMem (NodePointer *head) {
	NodePointer current;
	while(*head != NULL) {
		current = *head;
		head = &((*head)->next);
		Free((void **)&current);
	}
}
//-------------------------------------
int main(void) {
	NodePointer Head;
	NodePointer NewNode;
	String Input;
	int Size = 0;
	
	printf("Enter nation name('!' to continue): ");
	scanf("%s", Input);

	while(strcmp(Input, "!")) {
		NewNode =(NodePointer)malloc(sizeof(Node));
		strcpy(NewNode->name, Input);
		NewNode->next = Head;
		Head = NewNode;
		++Size;
		printf("Enter nation name: ");
		scanf("%s", Input);
	}
	printf("\n");
	NodePointer ANode = Head;
	while (ANode != NULL) {
		printf("Enter %s's best ally: ", (ANode->name));
		scanf("%s", Input);
		NodePointer Helper = Head;
		ANode->ally = FindNode(Helper, Input);
		ANode = ANode->next;
	}
	printf("\n");
	PrintOut(Head);
	FreeMem(&Head);
	FreeMem(&ANode);
	
}
//---------------------------------
