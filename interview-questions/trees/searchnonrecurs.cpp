/* C++ program to print level order traversal using STL */
#include <iostream>
#include <queue>
#include <climits>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// Iterative method to find height of Bianry Tree
bool printLevelOrder(Node *root,int data)
{
    // Base Case
   if (root != NULL)  
 {
    // Create an empty queue for level order tarversal
    queue<Node *> q;
    // Enqueue Root and initialize height
    q.push(root);
   
    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue
        Node *node = q.front();
        if(data==node->data)
           return true;
           q.pop();
 
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
   
   
   }
   return false;
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
    int n=10;
    //int a=
    if(printLevelOrder(root,n))
    cout<<"Element found";
    else 
     cout<<"Element not found";
   
    return 0;
}