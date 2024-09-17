#include <stdio.h>
#include <math.h>
#include<stdlib.h>

typedef struct
{
    int *array;
    // Add more fields here
    int totalbook;
    int currentPosition;
    int size;

    

} ArrayList;
void init_arraylist(ArrayList *list, int capacity)
{
    printf("implement init_arraylist\n");
    list->array = (int *)malloc(capacity * sizeof(int));
  
    list->totalbook=0;
    list->currentPosition=0;
    list->size=0;
    
    
}
void skip(ArrayList *list)
{
    printf("skipped \n");
    list->currentPosition = list->currentPosition+1;
}
void move_and_shift(ArrayList *list, int value)
{
   
   int temp = list->array[list->currentPosition];
   list->array[list->currentPosition]=list->array[list->size-1];
   list->array[list->size-1]=temp;
    
}
int discard(ArrayList *list)
{
    printf("discarded %d\n", list->array[list->currentPosition]);
    int currentElement = list->array[list->currentPosition];
    free(list->array[list->currentPosition]);
    for (int i = list->currentPosition; i < list->size; i++)
    {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
    return currentElement;
}
// int main(){
//     return 0;
// }