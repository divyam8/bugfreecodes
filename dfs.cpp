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
int ans;
int clr[100];
bool vis[100],par[100];
 
pii dfs(int i,vvi& v)
{
    int j,k;
    vis[i]=1;
    pii p,q,r;
    p.f=clr[i];
    p.s=1;
    bool b=true;
    for(j=0;j<v[i].size();j++)
    {
        if(vis[v[i][j]]==0)
        {
            q=dfs(v[i][j],v);
 
            if(p.f!=q.f)
                b=false;
 
            p.s+=q.s;
            if(q.s>ans)
                ans=q.s;
        }
    }
    if(b)
    {
        if(p.s>ans)
            ans=p.s;
        return p;
    }
    return mp(0,0);
}
 
int main()
{
    //ios_base::sync_with_stdio(false); 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t,i,j,k,r,n,m,q,x;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        memset(par,0,sizeof(par));
        vvi v(n);
        ans=1;
        for(i=0;i<n;i++)
            scanf("%d",&clr[i]);
 
        for(i=0;i<n-1;i++)
        {
            scanf("%d",&j);
            scanf("%d",&k);
            j--,k--;
            v[j].pb(k);
            par[k]=1;
        }
        for(i=0;i<n;i++)
            if(par[i]==0)
                dfs(i,v);
        printf("%d\n",ans );
    }
    
    return 0;
}
