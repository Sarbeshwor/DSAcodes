#include "bst.h"
#include <iostream>
#include <vector>

using namespace std;

// int getSecondLargest(Node* node){
//     vector<int> elements;

//     // Write your code here.
//    arrange(node, elements);
//    int ans=elements[elements.size()-2];
//    cout<<ans<<endl;
//    return ans;

    
// }
int getSecondLargest(Node* node) {
    vector<int> elements;

    // Fill the vector with in-order traversal
    arrange(node, elements);
    
    // Check the size of the elements vector
    if (elements.size() < 2) {
        cout << "Not enough elements in the tree to find the second largest." << endl;
        return -1; // or throw an exception based on your needs
    }

    // Print the contents of the vector for debugging
    cout << "Elements in order: ";
    for (int val : elements) {
        cout << val << " ";
    }
    cout << endl;

    // Return the second largest element
    int ans = elements[elements.size() - 2];
    cout << "Second largest element: " << ans << endl;
    return ans;
}


int main(){
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    char option;
    int val;
    int a, b;

    Node *root = NULL;
    
    while(scanf("%c %d\n", &option, &val) == 2){
        if (option=='G')
        {
            printf("%d\n", getSecondLargest(root));
        }
        
        if(option == 'I'){
            root = insertNode(root, val);
            printTree(root);
            printf("\n");
        } else if (option == 'D'){
            root = deleteNode(root, val);
            printTree(root);
            printf("\n");
        } else if (option == 'F'){
            if(find(root, val) != NULL)
                printf("Found\n");
            else
                printf("Not Found\n");
        } else if(option == 'T'){
            if(val == 1){
                inOrder(root);
                printf("\n");
            }
            else if (val == 2)
            {
                preOrder(root);
                printf("\n");                
            }
            else{
                postOrder(root);
                printf("\n");
            }
        } else if(option == 'G'){
            printf("hi");
            printf("%d\n", getSecondLargest(root));
        }
    }
    return 0;
}