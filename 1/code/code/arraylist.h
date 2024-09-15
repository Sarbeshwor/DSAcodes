#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int size;
    int position;
    int capacity;
    // Add more fields here

} ArrayList;

void init_arraylist(ArrayList *list, int capacity)
{
    list->array = (int *)malloc(sizeof(int) * capacity);

    // dynamically allocate space for the array
    // initialize the size, capacity, and current position
    list->size = 0;
    list->capacity = capacity;
    list->position = 0;
}

void clear(ArrayList *list)
{
    printf("cleared list\n");

    // clear the list but do not free the array
    list->size = 0;
    list->position = 0;
    list->position = -1;
    // modify the size, capacity, and current position
}

int get_size(ArrayList *list)
{
//     int size=0;
   
//    for (int i = 0; i < list->capacity; i++)
//    {
//     if (list->array=='\0')
//     {
//         break;
//     }
//     size++;
    
//    }

   printf("size is %d\n",list->size);
   return list->size;
   
    
}

void resize(ArrayList *list, int new_capacity)
{
    // if (list->capacity==new_capacity)
    // {
    

    //}
    
    // allocate space for new array with new_capacity
    // print log message
    printf("Resized array from %d to %d\n",list->capacity, new_capacity);
    list->array = (int *)realloc(list->array, new_capacity * sizeof(int));
        list->capacity = new_capacity;
}

void append(ArrayList *list, int value)
{
    // printf("Implement append\n");
    // call resize if necessary
      if (list->size==list->capacity)
    {
        resize(list, list->capacity * 2);
            //printf("appended %d \n",value);

    }

    // add value to the end of the 
    list->array[list->size]=value;
    list->size++;
}

void insert(ArrayList *list, int value)
{
    // printf("Implement insert\n");
    // call resize if necessary
    if (list->size>=list->capacity)
    {
        resize(list,list->capacity*2);
        printf("resized array \n");
    }
    
    // shift the elements to the right to make space
    for (int i = list->size; i > list->position; i--)
    {
        list->array[i]=list->array[i-1];
    }
    
    // add value at the current position
    list->array[list->position]=value;
    list->size++;
    printf("inserted %d\n",value);
}

int remove_at_current(ArrayList *list)
{
    // printf("Implement remove_at_current\n");
    // return -1;
    // save the value of the current element in a variable
    int to_remove=list->array[list->position];
    // shift the elements to the left to fill the gap
    for (int i = list->position; i < list->size-1; i++)
    {
        list->array[i]=list->array[i+1];
    }
    
    // change the size, and current position as necessary
    list->size--;
    printf("removed %d\n",to_remove);
    // call resize if necessary
    // return the saved value
    return to_remove;
}

int find(ArrayList *list, int value)
{
    // printf("Implement find\n");
    // return -1;
    // traverse the list and return the position of the value
    for (int i = 0; i < list->size; i++)
    {
       if (list->array[i]==value)
       {
        printf("found %d at %d \n",value,i);
        return i;
       }
    //    else{
    //     printf("did not find %d in the list\n",value);
    //     return -1;
    //    }
       
    }
    printf("did not find %d in the list\n",value);
        return -1;
     
    
    // return -1 if the value is not found
}

void move_to_start(ArrayList *list)
{
    // printf("Implement move_to_start\n");
    // consider the cases when the list is empty
    printf("moved current position to 0 \n");
    list->position=0;
    
}

void move_to_end(ArrayList *list)
{
    printf("Implement move_to_end\n");
    // consider the cases when the list is empty
    printf("moved current position to end \n");

    list->position=list->size-1;
}

void prev(ArrayList *list)
{
    // printf("Implement prev\n");
    if (list->position==0)
    {
       return;
    }
    else{
        printf("Moved current position from %d to %d\n",list->position,list->position-1);
        list->position=list->position-1;
    }
    
    // no change if the current position is at the start
}

void next(ArrayList *list)
{
    printf("Implement next\n");
    if (list->position==list->size-1)
    {
        return;
    }
    else{
        printf("moved current position from %d to %d\n", list->position, list->position + 1);

        list->position++;
    }
    
    // no change if the current position is at the end
}

void move_to_position(ArrayList *list, int position)
{
    // printf("Implement move_to_position\n");
    if (position>=0 && position<list->size)
    {   
    printf("moved current position from %d to %d\n", list->position, position);

        list->position=position;
    }
    else{
        printf("Invalid Position \n");
    }
    
}

int get_current_position(ArrayList *list)
{
    // printf("Implement get_current_position\n");
    printf("current position is %d\n", list->position);

    return list->position;
}

int get_current_element(ArrayList *list)
{
    // printf("Implement get_current_element\n");
    printf("current element is %d\n", list->array[list->position]);

    return list->array[list->position];
}

void print_list(ArrayList *list)
{
    if (list->size==0)
    {
        printf("<  >\n");
    }
    else{
        printf("< ");
        for (int i = 0; i < list->size; i++)
        {
            if (i==list->position)
            {
                printf("|%d",list->array[i]);
            }
            else{
                printf("%d",list->array[i]);
            }
            if (i!=list->size-1)
            {
                printf("  ");
            }
            
            
        }
            printf(" >\n");

        
    }
}

void free_list(ArrayList *list)
{
    // printf("Implement free_list\n");
    // free the array before terminating the program
    free(list->array);

}
