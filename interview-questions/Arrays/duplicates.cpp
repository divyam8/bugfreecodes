/*given an array of n numbers give algo for checking whether there are any duplicates in the array of not
*/
#include<iostream>
#include<stdlib.h>
 
using namespace std;
void checkduplicate(int a[],int n)
{
  for(int i=0;i<n;i++)
  {
     if(a[abs(a[i])]<0)
     {
       cout<<"Duplicate exists";
       return;
       
     }
     else 
         a[a[i]]=-a[a[i]];      
  }
   cout<<"\n No duplicates in the array";
}
int main()
{
  int a[6]={3,2,1,2,2,3};
  int n=6;
  checkduplicate(a,n);  
  
return 0;
}
