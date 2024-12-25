#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
};
int minimum(Node *node){
    if(node==nullptr){
        return -1;
    }
    Node * curr = node;
    while(curr->left!=nullptr){
        curr=curr->left;

    }
    return curr->val;
}
int maximum(Node *node){
    if(node==nullptr){
        return -1;
    }
    Node *temp = node;
    while (temp->right!=nullptr)
    {
        temp->right;
    }
    return temp->val;
    
}

Node *insertNode(Node *node, int val)
{
    // Write your codes here
    Node *newNode = new Node;
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    if (node == NULL)
    {
        return newNode;
    }
    if(val<node->val){
        node->left=insertNode(node->left,val);
    }
    else{
        node->right=insertNode(node->right,val);
    }
    return node;

    // This function takes a pointer to the root of the BST and 
    // the value to be inserted
    // Returns the pointer to the root of the modified BST.
}

Node *deleteNode(Node *node, int val)
{
    // Write your codes here
    Node *temp;
    if(node==NULL){
        return node;
    }
    if(val<node->val){
        node->left=deleteNode(node->left,val);
    }
    else if(val>node->val){
        node->right=deleteNode(node->right,val);
    
    }
    // node = find(node,val);
    else{
        if(node->left==NULL){
            temp=node->right;
            delete node;
            return temp;
        }
        else if(node->right==NULL){
            temp=node->left;
            delete node;
            return temp;
        }
        temp=node->right;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        node->val=temp->val;
        node->right=deleteNode(node->right,temp->val);
    }
    // This function takes a pointer to the root of the BST and 
    return node;
    // the value to be deleted.
    // Returns the pointer to the root of the modified BST.
}
int secondhighest(Node *node){
    if (node==nullptr)
    {
        return -1;
    }
    Node *secondhighest=node;
    while (secondhighest->right!=nullptr)
    {
        secondhighest->right;
    }
    deleteNode(node,secondhighest->val);
     while (secondhighest->right!=nullptr)
    {
        secondhighest->right;
    }
    return secondhighest->val;

    
    
}

Node* find(Node *node, int val)
{
    // Write your codes here
   
    Node *temp=node;
    while(temp!=NULL){
        if(temp->val==val){
            return temp;
        }
        else if(val<temp->val){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return NULL;

    // This function takes a pointer to the root of the BST and 
    // the value to be searched.
    // Returns the pointer to the node that contains val.
    // Returns NULL if not found.
}

void inOrder(Node *node)
{
    // Write your codes here
    Node *temp=node;
    if(temp==NULL){
        return;
    }
    inOrder(temp->left);
    cout<<temp->val<<" ";
    inOrder(temp->right);

    // This function takes a pointer to the root of the BST
    // Prints the in-order traversal of the given BST

}
void arrange(Node *node, vector<int>&result)
{
    // Write your codes here
    
    if(node==NULL){
        return;
    }
    arrange(node->left,result);
    result.push_back(node->val);
    arrange(node->right,result);

    // This function takes a pointer to the root of the BST
    // Prints the in-order traversal of the given BST

}
void preOrder(Node *node)
{
    // Write your codes here
    Node *temp=node;
    if(temp==NULL){
        return;
    }
    cout<<temp->val<<" ";
    preOrder(temp->left);
    preOrder(temp->right);


    // This function takes a pointer to the root of the BST
    // Prints the pre-order traversal of the given BST
}

void postOrder(Node *node)
{
    // Write your codes here
    Node * temp = node;
    if(temp==NULL){
        return;
    }
    postOrder(temp->left);
    postOrder(temp->right);
    cout<<temp->val<<" ";

    
    // This function takes a pointer to the root of the BST
    // Prints the post-order traversal of the given BST
}

void printTree(Node *root){
    // Write your codes here
    Node *temp = root;
    if(temp==NULL){
        cout<<"_";
        return;
    }
    cout<<temp->val;
    if (root->left!=NULL || root->right!=NULL)
    {
        cout<<"( ";
        printTree(temp->left);
        cout<<", ";
        printTree(temp->right);
        cout<<") ";
    }
    // This function takes a pointer to the root of the BST
    // Prints parenthesized representation of the given BST
}