#include <iostream>
using namespace std;

class Queue
{
private:
    int *array;
    //write your code here. Add additional private variables if necessary
    int capacity;
    int front;
    int last;

public:
    // Constructor
    Queue()
    {
        array = new int[1];
        capacity = 1;
        front=0;
        last=0;

        //write your code here. Initialize additional private variables if necessary
        
    }
    Queue(int initialCapacity)
    {
        array = new int[initialCapacity]; // Allocate initial memory
        //write your code here. Initialize additional private variables if necessary
        capacity = initialCapacity;
        front=0;
        last=0;

    }

    // Destructor
    ~Queue()
    {
        delete[] array; // Free dynamically allocated memory
    }

    // Helper function to resize the array when full
    void resize(int newCapacity)
    {
        int *newArray = new int[newCapacity]; // Allocate new array

        //write your code here. Copy the elements from the old array to the new array
        for (int i = front; i < last; i++)
        {
            newArray[front] = array[front+1];

        }
        

        delete[] array; // Free old memory

        //write your code here. Update the capacity and array pointers
        capacity = newCapacity;
        array = newArray;

    }

    // Enqueue an element onto the queue
    void enqueue(int x)
    {
        //write your code here. Check if the array is full and resize if necessary.
        if(capacity==last){
            resize(2*capacity);
        }
        array[last]=x;
        last++;

    }

    // Remove and return the peek element
    int dequeue()
    {
       //write your code here. Check if the stack is empty and return -1 if it is.
       if (isEmpty())
       {
        return -1;
       }
       
       //remove the peek element and return it
         int removelement=array[front];
        //  delete array[front];
        for (int i = 0; i < last+1; i++)
        {
            array[i]=array[i+1];
        }
        last--;

        

            
       //resize the array if necessary
       if(last==capacity/4){
        resize(capacity/4);
       }
       return removelement;
    }

    // Return the peek element without removing it
    int peek()
    {
        
        //write your code here. Check if the queue is empty and return -1 if it is.
        if (isEmpty())
        {
            /* code */
            return -1;
        }
        
        //return the peek element
        return array[front];
    }

    // Return the number of elements in the queue
    int length()
    {
        //write your code here. Return the number of elements in the queue
        return last;
    }

    // Check if the queue is empty
    bool isEmpty()
    {

        
        //write your code here. Return true if the queue is empty, false otherwise
        if (last==0)
        {
            return true;
        }
        else{
            return false;
        }
        
    }

    // Clear the queue
    void clear()
    {
        //write your code here. Clear the queue. resize the array to 1
        delete [] array;
        capacity=1;
        array= new int[capacity];
        last=0;
        front=0;

    }
};
