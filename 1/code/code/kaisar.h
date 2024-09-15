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
    int current_index;
    int size;

} LinkedList;

int count = 0;

void init_linkedlist(LinkedList *list)
{
    // printf("implement init_linkedlist\n");
    // initialize head, tail with null
    list->head = NULL;
    list->tail = NULL;
    list->current_position = 0;
    list->current_index = 0;
    list->size = 0;
}

void clear(LinkedList *list)
{
    printf("cleared list\n");
    // traverse the list and free each node
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->next = list->head;
    while (ptr != NULL)
    {
        free(ptr);
        ptr = ptr->next;
    }
    // set head and tail to null
    list->head = NULL;
    list->tail = NULL;
    list->current_position = 0;
    list->current_index = 0;
    list->size = 0;
}

int get_size(LinkedList *list)
{
    int size = 0;
    Node *curr = (Node *)malloc(sizeof(Node));
    curr = list->head;
    while (curr != NULL)
    {
        size++;
        curr = curr->next;
    }
    printf("size is %d\n", size);
    return size;
}

void append(LinkedList *list, int value)
{
    // printf("Implement append\n");
    // create a new node and set its value
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (list->head == NULL)
    {
        new_node->prev = NULL;
        list->head = list->tail = new_node;
    }
    else
    {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
    // consider the case when the list is empty and when it isnt
}

void insert(LinkedList *list, int value)
{
    printf("Inserted %d\n", value);

    // Create a new node and set its value
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    // place it at the current position (check order of operations)
    // Case 1: Inserting at the head
    if (list->current_index == 0)
    {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
    // Case 2: Inserting at the tail
    else if (list->current_index == list->size)
    {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }
    // Case 3: Inserting at mid
    else
    {
        Node *ptr = list->head;
        for (int i = 0; i < list->current_index - 1; i++)
        {
            ptr = ptr->next;
        }

        new_node->next = ptr->next;
        new_node->prev = ptr;
        if (ptr->next != NULL)
        {
            ptr->next->prev = new_node;
        }
        ptr->next = new_node;
    }
    // consider the case when the list is empty and when it isnt
    if (list->size == 0)
    {
        list->head = new_node;
        list->tail = new_node;
        list->size = 1;
        return;
    }
    list->size++;
}

int remove_at_current(LinkedList *list)
{

    if (list->size == 0)
    {
        printf("empty list");
        return -1;
    }
    // printf("removed %d\n",list->current_position->data);

    // consider the case when current code is at the begining or at the end
    int element = list->current_position->data;
    if (list->current_position == list->head)
    {
        list->current_position->next->prev = NULL;
        list->head = list->current_position->next;
        list->current_position = list->head;
    }
    list->current_position = list->current_position->next;

    list->size--;
    printf("removed %d\n", element);
    return -1;
}

int find(LinkedList *list, int value)
{
    // traverse the list and return the position of the value
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->next = list->head;
    int i;
    for (i = 0; ptr != NULL; i++)
    {
        if (ptr->data == value)
        {
            printf("found %d at %d\n", value, i);
            return value;
        }
        ptr = ptr->next;
    }
    printf("did not find %d in the list\n", value);
    return -1;
}

void move_to_start(LinkedList *list)
{
    printf("moved current position to start\n");
    list->current_index = 0;
}

void move_to_end(LinkedList *list)
{
    printf("moved current postion to end\n");
    list->current_index = get_size(list) - 1;
}

void prev(LinkedList *list)
{
    if (list->current_index != 0)
    {
        printf("moved current position from %d to %d\n", list->current_index, list->current_index - 1);
        list->current_index--;
    }
    else
    {
        printf("can not move prev from the start\n");
    }
}

void next(LinkedList *list)
{
    if (list->current_index != get_size(list) - 1)
    {
        printf("moved current position from %d to %d\n", list->current_index, list->current_index + 1);
        list->current_index++;
    }
    else
    {
        printf("can not move next from the end\n");
    }
}

void move_to_position(LinkedList *list, int position)
{
    printf("moved current position from %d to %d\n", list->current_index, position);
    // traverse the list and stop at the given position
    list->current_index = position;
}

int get_current_position(LinkedList *list)
{
    printf("current position is %d\n", list->current_index);
    // traverse the list and stop when you are at the current position
    // return the position (integer)
    return list->current_index;
}

int get_current_element(LinkedList *list)
{
    // return the value at the current position
    int element;
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->next = list->head;
    ptr = ptr->next;
    for (int i = 0; i != list->current_index; i++)
    {
        ptr = ptr->next;
    }
    element = ptr->data;
    printf("current element is %d\n", element);
    return element;
}

void print_list(LinkedList *list)
{
    if (list->size != 0)
        printf("<");
    else
        printf("< ");
    Node *ptr = list->head;
    for (int i = 0; ptr != NULL; i++)
    {
        if (list->current_index == i)
        {
            printf(" |");
            printf("%d ", ptr->data);
        }
        else
            printf(" %d ", ptr->data);

        ptr = ptr->next;
    }
    if (list->size != 0)
        printf(">\n");
    else
        printf(" >\n");
}

void free_list(LinkedList *list)
{
    // printf("Implement free_list\n");
    // free each node in the list
}