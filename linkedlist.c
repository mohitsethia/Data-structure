#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head;
void insertatbegin(int x){ 
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    head = temp;
}
void insertatend(int x){ 
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
void insertatposition(int a, int b){ 
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->data = a;
    temp1->next = NULL;
    if(b == 1){ 
        temp1->next = head;
        head = temp1;
        return;
    }   
    struct node* temp2 = head;
    for(int i = 0; i < b - 2; i++){
        temp2 = temp2->next;
    }   
    temp1->next = temp2->next;
    temp2->next = temp1;
}
void display(){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }   
}
int main(){
    int n, i = 0, x, y, j, k;
    printf("Enter Number of elements: "); 
    scanf("%d", &n);
    printf("\nEnter the first number: "); 
    scanf("%d", &x);
    insertatend(x);
    while(i < 5){ 
        printf("Enter 1. Insert at beginning, 2. Insert at end, 3. Insert at particular position, 4. Display, 5. Exit");
        scanf("%d", &y);
        switch(y){
            case 1:
                printf("\nEnter the value: ");
                scanf("%d", &j);
                insertatbegin(j);
                break;
            case 2:
                printf("\nEnter the value: ");
                scanf("%d", &j);
                insertatend(j);
                break;
            case 3:
                printf("Enter the value and position: ");
                scanf("%d%d", &j, &k);
                insertatposition(j, k);
                break;
            case 4:
                display();
                break;
            default:
                i = 5;
                break;
        }
    }
    return 0;
}
