/*given an array of n numbers give algo for finding sum equal to k
Time complexity:O(nlogn)
Space complexity:O(1)
*/
#include<iostream>
#include<stdlib.h>
#include<algorithm>
 
using namespace std;
void sumisequaltok(int a[],int n,int k)
{
   sort(a,a+n);
   int i=0,j=n-1,temp;
   while(i<j)
   {    
    temp=a[i]+a[j];
    if(temp==k)    
    {
       cout<<"Element found:"<<i<<j;
       return;
    }
    else if(temp<k)
     i=i+1;
    else
     j=j-1;
   }
return;
  
   
}
int main()
{
  int a[]={1, 4, 45, 6, 10, -8};
  int n=sizeof(a)/sizeof(a[0]);
  int k=16;
  sumisequaltok(a,n,k);  
  
return 0;
}
