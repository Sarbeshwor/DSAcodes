#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    // add *next and *prev here
    struct Node *next;
    struct Node *prev;

} Node;

typedef struct
{
    // add Node* head, tail, current_position and other necessary fields here
    Node *head;
    Node *tail;
    Node *current_position;
    int current;
    int size;
} LinkedList;

void init_linkedlist(LinkedList *list)
{
    // printf("implement init_linkedlist\n");
    // initialize head, tail with null
    list->head = NULL;
    list->tail = NULL;
    list->current_position = NULL;
    list->size = 0;
    list->current = 0;
}

void clear(LinkedList *list)
{
    // printf("Implement clear\n");
    // traverse the list and free each node
    Node *active_node = list->head;
    while (active_node != NULL)
    {
        Node *freenode = active_node;
        active_node = active_node->next;
        free(freenode);
    }

    // set head and tail to null
    list->head = NULL;
    list->tail = NULL;
    list->current_position = NULL;
    list->size = 0;
}

int get_size(LinkedList *list)
{
    // printf("Implement get_size\n");
    printf("size is %d\n", list->size);
    return list->size;
}

void append(LinkedList *list, int value)
{
    // create a new node and set its value
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    // consider the case when the list is empty and when it isnt
    // if (list->tail == NULL)
    // {
    //     list->head = new_node;
    // }
    // else
    // {
    //     list->tail->next = new_node;
    // }
    // list->tail = new_node;
    // list->size++;

    // if (list->current_position == NULL)
    // {
    //     list->current_position = new_node;
    // }
    // jaba list empty huncha ra hudaina
    // printf("appended %d\n",value);
    if (list->size == 0)
    {

        list->head = new_node;
        list->tail = new_node;
        list->current_position = new_node;
    }
    else
    {
         list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
            // printf("appended %d \n",value);

    }
    list->size++;
}

void insert(LinkedList *list, int value)
{
    // printf("Implement insert\n");
    if (list->size==0)
    {
        append(list, value);
        printf("inserted %d\n", value);
        return;
    }
    

    // create a new node and set its value
    Node *new_node = (Node *)malloc(sizeof(Node));
    // place it at the current position (check order of operations)
    new_node->data = value;
    new_node->next=NULL;
    new_node->prev=NULL;
    if (list->current_position == list->head)
    {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
    else
    {
        new_node->next = list->current_position;
        new_node->prev = list->current_position->prev;
        list->current_position->prev->next = new_node;
        list->current_position->prev = new_node;
    }
    list->current_position = new_node;
    list->size++;
        printf("inserted %d\n", value);

    // consider the case when the list is empty and when it isnt
}

int remove_at_current(LinkedList *list)
{
    // printf("Implement remove_at_current\n");
    if (list->size == 0)
    {
        printf("empty list\n");
        return -1;
    }
    Node *removing_value = list->current_position;
    int value = list->current_position->data;
    if (removing_value== list->head)
    {
        removing_value->next->prev=NULL;
        list->head = removing_value->next;
        // removing_value=list->head;
    }
    else if (list->size==1)
    {
        list->head=NULL;
        list->tail=NULL;
        list->current_position=NULL;
    }


    else{
        list->current_position->prev->next = list->current_position->next;
        list->current_position->next->prev = list->current_position->prev;
        // list->current_position = list->current_position->next;
    }
    list->current_position = list->current_position->next;
    free(removing_value);
    list->size--;

    printf("removed %d\n", value);
    return -1;

    // consider the case when current code is at the begining or at the end

    // else if
    // {
    //     remove_value->prev->next = remove_value->next;
    // }
    // else if (removing_value->next == list->tail)
    // {
    //     removing_value->prev->next=NULL;
    //     list->tail = removing_value->prev;
    //     removing_value=list->tail;
    // }
    // else
    // {
    //     remove_value->next->prev = remove_value->prev;
    // }

    // current node ko value agadi wa pichadi sarauna
    // if (remove_value->prev != NULL)
    // {
    //     list->current_position = remove_value->next;
    // }
    // else
    // {
    //     list->current_position = remove_value->prev;
    // }
}

int find(LinkedList *list, int value)
{
    // printf("Implement find\n");
    // traverse the list and return the position of the value
    Node *current_value = list->head;
    // head bata suru garera
    int position = 0;
    while (current_value != NULL)
    {
        if (current_value->data == value)
        {
            printf("found %d at %d\n", value, position);
            return position;
        }
        current_value = current_value->next;
        position++;
    }
    printf("didnt find %d in the list\n", value);
    return value;
}

void move_to_start(LinkedList *list)
{
    // printf("Implement move_to_start\n");
    list->current_position = list->head;
    list->current=0;
    printf("moved current position to 0\n");
}

void move_to_end(LinkedList *list)
{
    // printf("Implement move_to_end\n");
    list->current=list->size-1;
    list->current_position = list->tail;
    printf("moved current position to end\n");
}

void prev(LinkedList *list)
{
    // printf("Implement prev\n");
    if (list->current_position->prev != NULL)
    {
        printf("moved current position from %d to %d\n",
list->current, list->current- 1);

        list->current_position = list->current_position->prev;
        list->current--;
    }
    else{
            printf("current position is at start\n");

    }

}

void next(LinkedList *list)
{
    // printf("Implement next\n");
    if (list->current_position->next != NULL)
    {
        printf("moved from %d to %d", list->current, list->current + 1);
        list->current_position = list->current_position->next;
        list->current++;
    }
    printf("Current position is at end\n");
}

void move_to_position(LinkedList *list, int position)
{
    // printf("Implement move_to_position\n");
    // traverse the list and stop at the given position
    int temp = 0;
    Node *current = list->head;

    if (position <= 0 || position >= list->size)
    {
        printf("invalid posisiton \n");
        return;
    }
    while (temp != position)
    {
        temp++;
        current = current->next;
    }
    list->current_position=current;
    printf("moved from %d to %d\n", list->current, position);

    list->current=position;
    // list->current_position = current;
}

int get_current_position(LinkedList *list)
{
    // printf("Implement get_current_position\n");
    // traverse the list and stop when you are at the current position

    Node *temp = list->head;
    int i = 0;
    while (temp != list->current_position)
    {
        temp = temp->next;
        i++;
    }
    printf("Current position is %d\n", i);
    // return the position (integer)
    return i;
}

int get_current_element(LinkedList *list)
{
    // printf("Implement get_current_element\n");
    // return the value at the current position
    printf("current element is %d\n", list->current_position->data);
    return -1;
}

void print_list(LinkedList *list)
{
    // printf("< list elements here >");
    Node *temp = list->head;
    if (list->size == 0)
    {
        printf("<  >\n");
        return;
    }
    else{
        printf("<");
         while (temp != NULL)
    {
        if (temp == list->current_position)
        {
            // printf("current position");
            printf(" |%d ", temp->data);
        }
        else
            printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf(">\n");
    }

}

void free_list(LinkedList *list)
{
   // printf("Implement free_list\n");
    // free each node in the list

    Node *temp = list->head;
    while ((temp != NULL))
    {
        Node *temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
    list->head = NULL;
    list->tail = NULL;
    list->current_position = NULL;
    list->size = 0;
}