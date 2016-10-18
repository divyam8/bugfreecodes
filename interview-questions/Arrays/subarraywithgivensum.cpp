#include <bits/stdc++.h>
#define ll long long int
using namespace std;   
 
int main()
{
    //ios_base::sync_with_stdio(false); 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t,i,j,k,r,n,m,q,x;
    ll sum,finalsum;
    scanf("%lld",&t);
    ll ans=0;
    string s;
    while(t--)
    {
        cin>>n;
        sum=0,finalsum=0;
        ll a[n];
        for(i=0;i<n;i++)
        {
        	cin>>a[i];
        }
        cin>>sum;
        for(i=0;i<n;i++)
        {
        	 finalsum=0;
        	for(j=i;j<n;j++)
        	{
                  finalsum+=a[j];
                  if(finalsum==sum)
                  	cout<<i<<" "<<j;
        	}
        }

  
    }
    
    return 0;
}
