/*
Rhezo and his friend Vanya love problem solving. They have a problem set containing 
N
N problems, with points assigned to each. Rhezo wants to solve problems in such a way that he gets the maximum number of points. Rhezo has a weird habit of solving only prime number of consecutive problems, that is, if he solves 
X
X consecutive problems from the problem set, then 
X
X should be prime. Vanya has already solved all problems from the problem set and he wonders how much maximum points Rhezo can get. Vanya can answer this, but can you?

Input:

First line contains a single integer 
N
N, denoting the number of problems in the problem set. Next line contains 
N
N space separated integers denoting the points assigned to the problems.

Output:

Print a single integer, the maximum points Rhezo can get.

Constraints:

1
≤
N
≤
5000
1≤N≤5000
1
≤
1≤Points of Problems
≤
10
5
≤105
Sample Input(Plaintext Link)
 4
8 1 3 7
Sample Output(Plaintext Link)
 12
Explanation
Rhezo will solve problems 
1
1, 
2
2 and 
3
3, and will get 
12
12 points. Note that, he cannot solve all the problems because then he will solve
4
4(non-prime) consecutive problems.
*/

#include <stdio.h>

int isprime(int N)
{
    int i;
    if(N<2 || (!(N&1) && N!=2))
        return 0;
    for(i=3; i*i<=N; i+=2)
    {
        if(!(N%i))
            return 0;
    }
    return 1;
}
int main()
{
    int testcase,n,i,j,prime=0,sum=0,max=0;
    int a[50001];
   
    
    
    	scanf("%d",&n);
    	for(i=0;i<n;i++)
    	scanf("%d",&a[i]);
    	
    	
    	for(i=n;i>0;i--)
    	if(isprime(i))
    	break;
    	
    	prime=i;
      //  printf("%d",prime);

        for(i=0;i<n-prime;i++)
        {
        	sum=0;
            for(j=i;j<prime;j++)
              sum=sum+a[j];
           
            if(sum>max)
             max=sum; 
        }
        printf("%d",max);
    	 
    return 0;
}
