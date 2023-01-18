#include <stdio.h>
#include <stdlib.h>
struct node {
struct node *prev;
struct node *next;
int data;
};
struct node *new=NULL,*ptr=NULL,*head=NULL, *nextptr=NULL, *prevptr=NULL;
void insertion_last();
void delete_last();
void insertion_beginning();
void delete_beginning();
void display();
void insert_after_key();
void delete();
void create_node();
void main()
{
int opt;
do {
printf("\nchoose the operation number : \n");
printf("1.insertion last \n2.delete last \n3.insertion beginning \n4.delete beginning \n5.insert after key \n6.delete \n7.display \n0.exit : ");
scanf("%d",&opt);
switch(opt) {
case 1: insertion_last();
break;
case 2: delete_last();
break;
case 3: insertion_beginning();
break;
case 4: delete_beginning();
break;
case 5: insert_after_key();
break;
case 6: delete();
break;
case 7: display();
break;
case 0:
default:break;
}
} while(opt!=0);
}
void create_node() 
{
new = (struct node*)malloc(sizeof(struct node));
printf("enter the data to be inserted : ");
scanf("%d",&new->data);
new->next = NULL;
new->prev = NULL;
}
void insertion_last() 
{
create_node();
if(head == NULL) 
{
head = new;
}
else 
{
ptr=head;
while(ptr->next!=NULL)
{
ptr = ptr->next;
}
ptr->next = new;
new->prev = ptr;
}
}
void insertion_beginning() 
{
create_node();
if(head == NULL)
{
head = new;
} 
else 
{
head->prev=new;
new->next = head;
head = new;
}
}
void insert_after_key() 
{
int key;
create_node();
printf("enter the key where the node to be inserted : ");
scanf("%d",&key);
ptr=head;
while(ptr->data != key && ptr->next != NULL)
{
ptr = ptr->next;
}
if(ptr->data == key){
new->next = ptr->next;
new->prev = ptr;
ptr->next = new;
ptr->next->prev = new;
}
else 
{
printf("the key is not found");
}
}
void delete_beginning() 
{
if(head == NULL){
printf("empty list");
}
else if(head->next == NULL) 
{
head = NULL;
free(head);
printf("node deleted");
}
else  
{
ptr=head;
head = head->next;
head->prev = NULL;
free(ptr);
printf("node deleted");
}
}
void delete_last()
{
if(head == NULL) 
{
printf("empty list \n");
} 
else if(head->next == NULL) 
{
head = NULL;
free(head);
printf("\nnode deleted\n");  
}
else 
{
ptr = head;
while(ptr->next!=NULL)
{
ptr = ptr->next;
}
ptr->prev->next = NULL;
free(ptr);
printf("\nnode deleted\n");  
}
}
void delete() 
{
int key;
printf("enter the key where the node to be deleted : ");
scanf("%d",&key);
if(head->data == key)
{
delete_beginning();
}
else 
{
ptr=head;
while(ptr->data != key && ptr->next != NULL)
{
ptr = ptr->next;
}
if(ptr->data != key) 
{
printf("no data found");
}
else if(ptr->next == NULL) 
{
ptr->prev->next = NULL;
free(ptr);
printf("node deleted");
}
else 
{
ptr->prev->next=ptr->next;
ptr->next->prev=ptr->prev;
free(ptr);
printf("node deleted");
}
}
}
void display() 
{
if(head == NULL)
 {
printf("empty list \n");
} else {
ptr = head;
while(ptr!=NULL)
{
printf("%d ",ptr->data);
ptr = ptr->next;
}
printf("\n");
}
}


















