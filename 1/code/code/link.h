#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    // Add more fields here
    int size;
    int maxCapacity;
    int currentPosition;

} ArrayList;

int count = 0;

void init_arraylist(ArrayList *list, int capacity)
{
    // printf("implement init_arraylist\n");
    // dynamically allocate space for the array
    list->array = (int *)malloc(capacity * sizeof(int));
    // initialize the size, capacity, and current position
    list->size = 0;
    list->maxCapacity = capacity;
    list->currentPosition = 0;
}

void clear(ArrayList *list)
{
    printf("cleared list\n");
    // clear the list but do not free the array
    // modify the size, capacity, and current position
    list->maxCapacity = 0;
    list->size = 0;
    list->currentPosition = 0;
}

int get_size(ArrayList *list)
{
    int size = 0;
    for (int i = 0; i < list->maxCapacity; i++)
    {
        if (list->array[i] != '\0')
            size++;
    }
    printf("size is %d\n", size);
    return size;
}

void resize(ArrayList *list, int new_capacity)
{
    // allocate space for new array with new_capacity
    if (new_capacity <= 0)
        new_capacity = 1;
    list->array = (int *)realloc(list->array, new_capacity * sizeof(int));
    // print log message
    printf("resized array from %d to %d\n", list->maxCapacity, new_capacity);
    list->maxCapacity = new_capacity;
}

void append(ArrayList *list, int value)
{

    // call resize if necessary
    if (list->size > list->maxCapacity)
    {
        resize(list, (list->maxCapacity) * 2);
    }
    // add value to the end of the list
    list->array[list->size] = value;
    list->size++;
    count ++;
    if(count > get_size(list))
        printf("appended %d\n",value);
}

void insert(ArrayList *list, int value)
{
    // call resize if necessary
    if (list->size > list->maxCapacity)
    {
        resize(list, (list->maxCapacity) * 2);
    }
    // shift the elements to the right to make space
    list->size++;
    for (int i = list->size; i > list->currentPosition; i--)
    {
        list->array[i] = list->array[i - 1];
    }
    // add value at the current position
    list->array[list->currentPosition] = value;
    printf("inserted %d\n", value);
    
}

int remove_at_current(ArrayList *list)
{
    printf("removed %d\n", list->array[list->currentPosition]);
    if(list->size <= list->maxCapacity / 4)
    {
        resize(list,list->maxCapacity / 2);
    }
    // save the value of the current element in a variable
    int currentElement = list->array[list->currentPosition];
    // shift the elements to the left to fill the gap
    for (int i = list->currentPosition; i < list->size; i++)
    {
        list->array[i] = list->array[i + 1];
    }
    // change the size, and current position as necessary
    list->size--;
    // call resize if necessary
    // return the saved value
    return currentElement;
}

int find(ArrayList *list, int value)
{
    // printf("Implement find\n");
    // traverse the list and return the position of the value
    for (int i = 0; i < list->size; i++)
    {
        if (list->array[i] == value)
        {
            printf("found %d at %d\n", value, i);
            return value;
        }
    }
    // return -1 if the value is not found
    printf("did not find %d in the list\n", value);
    return -1;
}

void move_to_start(ArrayList *list)
{
    printf("moved current position to 0\n");
    // consider the cases when the list is empty
    list->currentPosition = 0;
}

void move_to_end(ArrayList *list)
{
    printf("moved current position to end\n");
    // consider the cases when the list is empty
    list->currentPosition = list->size - 1;
}

void prev(ArrayList *list)
{
    // no change if the current position is at the start
    if (list->currentPosition != 0)
    {
        printf("moved current position from %d to %d\n", list->currentPosition, list->currentPosition - 1);
        list->currentPosition--;
    }
    else{
        printf("can not move prev from the start\n");
    }
}

void next(ArrayList *list)
{
    // no change if the current position is at the end
    if (list->currentPosition != list->size - 1)
    {
        printf("moved current position from %d to %d\n", list->currentPosition, list->currentPosition + 1);
        list->currentPosition++;
    }
    else{
        printf("can not move next from the end\n");
    }
}

void move_to_position(ArrayList *list, int position)
{
    printf("moved current position from %d to %d\n", list->currentPosition, position);
    list->currentPosition = position;
}

int get_current_position(ArrayList *list)
{
    printf("current position is %d\n", list->currentPosition);
    return -1;
}

int get_current_element(ArrayList *list)
{
    printf("current element is %d\n", list->array[list->currentPosition]);
    return -1;
}

void print_list(ArrayList *list)
{
    if (list->size != 0)
        printf("<");
    else
        printf("< ");
    for (int i = 0; i < list->size; i++)
    {
        if (list->currentPosition == i)
        {
            printf(" |");
            printf("%d ", list->array[i]);
        }
        else
            printf(" %d ", list->array[i]);
    }
    if (list->size != 0)
        printf(">\n");
    else
        printf(" >\n");
}

void free_list(ArrayList *list)
{
    // printf("Implement free_list\n");
    // free the array before terminating the program
    free(list->array);
}