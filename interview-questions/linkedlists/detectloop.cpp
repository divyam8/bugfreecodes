/*

The structure of linked list is the following

struct node
{
int data;
node* next;
};

*/
int detectloop(struct node *list){
// your code goes here
  struct node*slowptr=list,*fastptr=list;
  while(slowptr&&fastptr&&fastptr->next)
  {
      slowptr=slowptr->next;
      fastptr=fastptr->next->next;
      if(slowptr==fastptr)
      return 1;
  }
  return 0;
}
