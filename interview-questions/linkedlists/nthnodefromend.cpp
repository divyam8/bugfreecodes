/* struct Node
 {
   int data;
   struct Node* next;
 }; */

/* Should return data of n'th node from the end of linked list */
int getNthFromLast(struct Node *head, int n)
{
       int count=0,M=0;
       // Your code here
       struct Node *temp=head;
       while(temp!=NULL)
       {
          
           temp=temp->next;
            count++;
       }
       if(count<n)
       return -1;
       
       M=count-n+1;
       temp=head;
       for(int i=1;i<M;i++)
       {
          temp=temp->next;   
       }
       return temp->data;
}
