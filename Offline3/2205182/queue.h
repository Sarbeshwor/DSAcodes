#include "QueueLinkedList.h" 
#include <iostream>
using namespace std;

class Stack
{
private:
    //write your code here. Add additional private variables if necessary
    Queue q;
public:
    // Constructor
    Stack()
    {
        //write your code here. Initialize additional private variables if necessary
    }
    Stack(int initialCapacity)
    {
        //write your code here. Initialize additional private variables if necessary
    }

    // Destructor
    ~Stack(){}

    // Push an element onto the stack
    void push(int x)
    {
        //write your code here.
        q.enqueue(x);
        //push the element onto the stack
    }

    // Remove and return the top element
    int pop()
    {
        //write your code here. Check if the stack is empty and return -1 if it is.
        if(isEmpty()){
            return -1;
        }
        for(int i = 0; i < length() - 1; i++){
            int val = q.dequeue();
            q.enqueue(val);
        }
        //pop the top element and return it
        return q.dequeue();
    }

    // Return the top element without removing it
    int top()
    {
        //write your code here. Check if the stack is empty and return -1 if it is.
        if(isEmpty()){
            return -1;
        }
        //return the top element
        for(int i = 0; i < length() - 1; i++){
            int val = q.dequeue();
            q.enqueue(val);
        }
        int top = q.peek();
        int val = q.dequeue();
        q.enqueue(val);
        return top;
    }

    // Return the number of elements in the stack
    int length()
    {
        //write your code here. Return the number of elements in the stack
        return q.length();
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        //write your code here. Return true if the stack is empty, false otherwise
        return q.isEmpty();
    }

    // Clear the stack
    void clear()
    {
        //write your code here. Clear the stack.
        q.clear();
    }
};