#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
}*end,*start;
struct node * delete(struct node *p)
{
	if(p==start)
	{
		start=start->next;
		end->next=start;
		start->prev=end;
		p=start;		


	}
	else if(p==end)
	{
	
		end->prev->next=start;
		start->prev=end->prev;
		end=end->prev;
		p=end->next;
	
	}
	else
	{
		p->prev->next=p->next;
		p->next->prev=p->prev;
		p=p->next;
	}

	return p;
}
		


int main(int argc, char const *argv[])
{
	int i,testcase,n,space,m;
	struct node *x,*y,*z,*w;
	int a[100000];
	
	scanf("%d",&testcase);
	scanf("\n%d",&n);
	
	while(testcase!=0)
	{
		space=n;
		//create(n1);
     		
	    start = (struct node*) malloc(sizeof(struct node));
	    start->data = 0;
	    start->next = NULL;
	    start->prev = NULL;
		y=start;
		for(i=1;i<n;i++)
		{
			struct node *x = (struct node*) malloc(sizeof(struct node));
			x->data=i;
			y->next=x;
			x->prev=y;
			x->next=start;
			start->prev=x;
			y=y->next;
			
		}
	    end=y;
	    w=start;
	    z=w->next;	
		for(i=1;i<=n;i++)
		{	
		
			if(space==1)
			{
				a[w->data]=i;
				
			}
	     	else
			{

				m=i%space;
				if(m!=0)
				{
					while((m-1)>0)
					{
						
						w=w->next;
						z=z->next;
						m=m-1;
					}
					a[z->data]=i;    
					z=delete(z);
					w=z;
					z=z->next;
			    }
				else
				{
					a[w->data]=i;
					w=delete(w);
					z=z->next;
				}
			
			}
			
			space--;
		}

		for(i=0;i<n;i++)
		{
			printf("%d\t",a[i]);

		}
 
	
		testcase--;
		if(testcase==0)
			break;
		printf("\n");
		scanf("\n%d",&n);

	}
	return 0;
}
