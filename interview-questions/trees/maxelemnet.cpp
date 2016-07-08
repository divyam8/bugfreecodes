/* C++ program to find maximum element in the tree */
#include <iostream>
#include <climits>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// Iterative method to find height of Bianry Tree
int findmax(Node *root)
{
    int root_val,left,right,max=INT_MIN;
    
    if (root != NULL)  
    {
       root_val=root->data;
       left=findmax(root->left);
       right=findmax(root->right);
    //find the largest of the three values 
       if(left>right)
         max=left;
       else 
        max=right;
        if(root_val>max)
         max=root_val;
    }
    return max;
}
 
// Utility function to create a new tree node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    int n=findmax(root);
    cout<<n;
    return 0;
}
