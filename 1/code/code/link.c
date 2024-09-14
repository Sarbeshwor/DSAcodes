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
    int size;
} LinkedList;

void init_linkedlist(LinkedList *list)
{
    printf("implement init_linkedlist\n");
    // initialize head, tail with null
    list->head = NULL;
    list->tail = NULL;
    list->current_position = NULL;
    list->size = 0;
}

void clear(LinkedList *list)
{
    printf("Implement clear\n");
    // traverse the list and free each node
    // set head and tail to null
    Node *current_node = list->head;
    while (current_node != NULL)
    {
        Node *for_free = current_node;
        current_node = current_node->next;
        free(for_free);
    }
    list->head = list->tail = list->current_position = NULL;
    list->size = 0;
}

int get_size(LinkedList *list) // need to check
{
    printf("Implement get_size\n");

    return list->size;
}

void append(LinkedList *list, int value)
{
    printf("Implement append\n");
    // create a new node and set its value
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = list->tail;

    // consider the case when the list is empty and when it isnt
    if (list->tail != NULL)
    {
        list->tail->next = new_node;
    }
    else
    {
        list->head = new_node;
    }

    list->tail = new_node;
    list->size++;
    //  list->current_position = new_node;
    if (list->current_position == NULL) // check
    {
        list->current_position = new_node;
    }
}

void insert(LinkedList *list, int value)
{
    printf("Implement insert\n");
    // create a new node and set its value
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Memory allocation falied!");
        exit(1);
    }
    new_node->data = value;
    // place it at the current position (check order of operations)
    if (list->current_position == NULL)
    {

        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else
    {
        new_node->next = list->current_position;
        if (list->current_position->prev == NULL)
        {

            new_node->prev = NULL;
            list->head = new_node;
        }
        else
        {
            new_node->prev = list->current_position->prev;
        }
    }
    // list->current_position->prev->next=new_node;
    // list->current_position->prev = new_node;

    // Node *currentNode = list->current_position;
    // new_node->data = value;
    // new_node->next = currentNode;
    // new_node->prev = currentNode->prev;
    // // consider the case when the list is empty and when it isnt
    // if (list->tail != NULL)
    // {
    //     list->current_position->prev = new_node;
    //     currentNode->prev->next = new_node;
    // }
    // else
    // {
    //     list->head = list->tail = list->current_position = new_node;
    // }
    list->current_position = new_node;
    list->size++;
}

int remove_at_current(LinkedList *list)
{
    printf("Implement remove_at_current\n");
    if (list->current_position == NULL)
    {
        return -1;
    }
    // consider the case when current code is at the begining or at the end
    Node *to_be_removed = (Node *)malloc(sizeof(Node));
    to_be_removed = list->current_position;
    int value = to_be_removed->data;
    if (to_be_removed->prev == NULL)
    {
        list->head = list->current_position->next;
        list->current_position = list->current_position->next;
    }
    else if (to_be_removed->next == NULL)
    {
        list->tail = list->current_position->prev;
        list->current_position = list->current_position->prev;
    }
    else
    {
        list->current_position->prev->next = list->current_position->next;
        list->current_position->next->prev = list->current_position->prev;
    }
    free(to_be_removed);
    list->size--;
    return value;
}

int find(LinkedList *list, int value)
{
    printf("Implement find\n");
    // traverse the list and return the position of the value
    Node *temp = (Node *)malloc(sizeof(Node));
    temp = list->head;
    int position = 0;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

void move_to_start(LinkedList *list)
{
    printf("Implement move_to_start\n");
    list->current_position = list->head;
}

void move_to_end(LinkedList *list)
{
    printf("Implement move_to_end\n");
    list->current_position = list->tail;
}

void prev(LinkedList *list)
{
    printf("Implement prev\n");
    if (list->current_position->prev != NULL)
    {
        list->current_position = list->current_position->prev;
    }
}

void next(LinkedList *list)
{
    printf("Implement next\n");
    if (list->current_position->next != NULL)
    {
        list->current_position = list->current_position->next;
    }
}

void move_to_position(LinkedList *list, int position)
{
    printf("Implement move_to_position\n");
    // traverse the list and stop at the given position
    int temp = 0;
    Node *current = list->head;
    if (position < 0 || position >= list->size)
        return;
    while (temp != position)
    {
        temp++;
        current = current->next;
    }
    list->current_position = current;
}

int get_current_position(LinkedList *list)
{
    printf("Implement get_current_position\n");
    // traverse the list and stop when you are at the current position
    // return the position (integer)
    int pos = 0;
    Node *current = list->head;
    while (current != NULL)
    {
        if (current == list->current_position)
        {
            return pos;
        }
        current = current->next;
        pos++;
    }
    return -1;
}

int get_current_element(LinkedList *list)
{
    printf("Implement get_current_element\n");
    // return the value at the current position
    int pos = 0;
    Node *current = list->head;
    while (current != NULL)
    {
        if (current == list->current_position)
        {
            return current->data;
        }
        current = current->next;
        pos++;
    }
    return -1;
}

void print_list(LinkedList *list)
{

    // while(list->head !=NULL)
    // {
    //     printf("< list elements here >");
    //     printf("%d ",list->head->data);
    //     list->head=list->head->next;

    // }

    Node *current = list->head;
    printf("<");
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
            printf(", ");
        current = current->next;
    }
    printf(">\n");
}

void free_list(LinkedList *list)
{
    printf("Implement free_list\n");
    // free each node in the list
    int pos = 0;
    Node *current = list->head;
    Node *temp;
    while (current != NULL)
    {
        temp = current;
        free(temp);
        current = current->next;
    }
    list->head = list->tail = list->current_position = NULL;
    list->size = 0;
}

int main()
{
    LinkedList list;
    init_linkedlist(&list);

    append(&list, 10);
    append(&list, 20);
    append(&list, 30);
    print_list(&list);

    move_to_start(&list);
    insert(&list, 5);
    print_list(&list);

    move_to_end(&list);
    insert(&list, 35);
    print_list(&list);

    printf("Current element: %d\n", get_current_element(&list));

    remove_at_current(&list);
    print_list(&list);

    printf("List size: %d\n", get_size(&list));

    free_list(&list);
        return 0;
}