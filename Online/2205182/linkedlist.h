#include <stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

} Node;

typedef struct
{
    Node *head;
    Node *tail;
    Node *current_position;
    int current;
    int size;
} LinkedList;

void skip(LinkedList *list)
{
   
    int temp = 0;
    
    list->current_position=list->current_position->next;
    return;
    
}
void move_and_shift(LinkedList *list, int position)
{
    
    int temp = 0;

    Node *curretnvalue=list->current_position->next->prev;
    Node *temp=list->head;
    
    
}
