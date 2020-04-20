#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;  
};
struct node* head;
void insert(int x){ 
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if(head == NULL){
        temp->next = head;
        head = temp;
        return;
    }   
    struct node* temp1 = head;
    while(temp1->next != NULL){
        temp1 = temp1->next;
    }   
    temp1->next = temp;
}
void deletefromposition(int x){ 
    struct node* temp1 = head;
    if(head == NULL){
        printf("List is empty");
        return;
    }   
    int i;
    for(i = 0; i < x-2; i++){
        temp1 = temp1->next;
    }   
    struct node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}
void deletefrombegin(){
    struct node* temp = head;
    head = temp->next;
    free(temp);
}
void deletefromend(){
    struct node* temp1, *temp = head;
    while(temp->next != NULL){
        temp1 = temp;
        temp = temp->next;
    }   
    temp1->next = NULL;
    free(temp);
}
void display(){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }   
}
int main(){
    int n, i, x, y, j = 0, k;
    printf("Enter number of elements: "); 
