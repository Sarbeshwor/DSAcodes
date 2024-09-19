#include <iostream>
using namespace std;

class Stack
{
private:
    int *array;
    //write your code here. Add additional private variables if necessary
    int capacity;
    int currentsize;
    

public:
    // Constructor
    Stack()
    {
        array = new int[1]; 
        capacity=1;
        currentsize=0;
        //write your code here. Initialize additional private variables if necessary
        
    }
    Stack(int initialCapacity)
    {
        capacity=initialCapacity;
        array = new int[initialCapacity]; // Allocate initial memory
        //write your code here. Initialize additional private variables if necessary
        currentsize=0;
    }

    // Destructor
    ~Stack()
    {
        delete[] array; // Free dynamically allocated memory
    }

    // Helper function to resize the array when full
    void resize(int newCapacity)
    {
        int *newArray = new int[newCapacity]; // Allocate new array
        
        //write your code here. Copy the elements from the old array to the new array
        for (int i = 0; i < currentsize; i++)
        {
            newArray[i]=array[i];
        }
        

        delete[] array; // Free old memory
        
        //write your code here. Update the capacity and array pointers
        capacity=newCapacity;
        array=newArray;
    }

    // Push an element onto the stack
    void push(int x)
    {
        //write your code here. Check if the array is full and resize if necessary.
        if (capacity==currentsize)
        {
            resize(2*capacity);

        }
        array[currentsize]=x;
        currentsize++;
        //push the element onto the stack
    }

    // Remove and return the top element
    int pop()
    {
       //write your code here. Check if the stack is empty and return -1 if it is.
       if (isEmpty())
       {
        // cout<<"stack is empty"<<endl;
        return -1;
       }
       int topelement=array[currentsize-1];
       //pop the top element and return it
       currentsize--;
       //resize the array if necessary
       if (currentsize==capacity/4 && currentsize>0)
       {
        resize(capacity/2);
        // cout<<"decreased size from "<<endl;
       }
       return topelement;
    }

    // Return the top element without removing it
    int top()
    {
        
        //write your code here. Check if the stack is empty and return -1 if it is.
        if (isEmpty())
        {
            // cout<<"empty stack"<< endl;
            return -1;
        }
        return array[currentsize-1];
        //return the top element
    }

    // Return the number of elements in the stack
    int length()
    {
        return currentsize;
        //write your code here. Return the number of elements in the stack
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        //write your code here. Return true if the stack is empty, false otherwise
        return currentsize==0;
    }

    // Clear the stack
    void clear()
    {
        //write your code here. Clear the stack. resize the array to 1
        delete [] array;
        capacity=1;
        array= new int[capacity];
        currentsize=0;
        
    }
};
