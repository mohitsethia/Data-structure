#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
struct Node* Reverse(struct Node* head){
	struct Node *current, *prev, *next;
		current = head;
		prev = NULL;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
}
	head = prev;
	return head;
}

struct Node* Insert(struct Node* head, int data){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = data;
		temp->next = NULL;
	if(head == NULL)
		head = temp;
	else{
		struct Node* temp1 = head;
	while(temp1->next != NULL)
		temp1 = temp1->next;
		temp1->next = temp;
}
	return head;
}

void Print(struct Node* head){
	while(head != NULL){
		printf("%d ", head->data);
	head = head->next;
}
}

int main(){
	struct Node* head =NULL;
	int n;
	printf("How many elements you want to enter? ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the elements : ");
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		head = Insert(head, arr[i]);
	}

			printf("\n");
	head = Reverse(head);
		Print(head);
}
