#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define piii pair<int,pii>
#define pll pair<ll,ll>
#define psi pair<string,int>
#define rep(i,n) for(i=0;i<n;i++)
#define repd(i,n) for(i=n;i>=0;i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define vvlli vector<vector<long long int> >
#define ll long long int
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define PI 3.14159265
#define mod 1000000007
#define N 100001
 
 
ll gcd(ll a,ll b)
{
    if(b==0)
      return a;
    return gcd(b,a%b);
}
 
ll power(ll a,ll n)
{
    if(n==0)
      return 1;
    ll x=power(a,n/2);
    x=(x*x)%mod;
    if(n%2!=0)
    {
      x=x*a;
      x=x%mod;
    }
    return x;
}
 
 
int main()
{
    //ios_base::sync_with_stdio(false); 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t,i,j,k,r,n,m,q,x;
    scanf("%lld",&t);
    ll ans=0;
    while(t--)
    {
        scanf("%lld",&n);
        vi v(n);
        ans=0;
        for(i=0;i<n;i++)
            cin>>v[i];
        cin>>x>>k;
        if(k>n || x<k)
        {
            printf("Not Possible\n");
            continue;
        }
        sort(v.begin(),v.end());
        j=x-k;
        ans+=j*(ll)v[0];
 
        for(i=0;i<k;i++)
            ans+=(ll)v[i];
        printf("%lld\n",ans );
    }
    
    return 0;
} 
