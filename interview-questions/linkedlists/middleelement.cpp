/* Link list Node 
struct Node {
    int data;
    struct Node* next;
}; */

/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(struct Node *head)
{
   // Your code here
   struct Node *ptr1x,*ptr2x,*temp;
   temp=ptr1x=ptr2x=head;
   int i=0,len;
   
   while(temp!=NULL)
   {
       len++;
       temp=temp->next;
   }
   while(ptr1x->next!=NULL)
   {
       if(i==0)
       {
           ptr1x=ptr1x->next; //increment only the first pointer
           i=1;
       }
       else if(i==1)
       {
           ptr1x=ptr1x->next; //increment both the pointers
           ptr2x=ptr2x->next;
           i=0;
       }
   }
   if(len%2==0)
   return ptr2x->data;
   else
   return ptr2x->next->data;
}
