#include<iostream>
#include<queue>
#include<stdio.h>

using namespace std;
int answer;
char m[51][51];
int n,x,y,z,j,a,b,c,d;
bool visited[51][51][51];

int BFS()
{

    queue <pair<int, pair<int, pair<int, int> > > > q;
    d=0;
    q.push(make_pair (a,make_pair(b,make_pair(c,d))));
    
    for (int i = 0; i <51; ++i)
    {
      for (int j = 0; j <51; ++j)
      {
        for (int k = 0; k < 51; ++k)
        {
          visited[i][j][k]=false;
        }
      }
    }

    while(!q.empty())
    {
        pair<int, pair<int, pair<int, int> > > r=q.front();
        q.pop();

        if(r.first==r.second.first&&r.second.first==r.second.second.first)
          return r.second.second.second;

        if(visited[r.first][r.second.first][r.second.second.first])
          continue;

        visited[r.first][r.second.first][r.second.second.first] = true;

     for(int i=0;i<n;i++)  // for each edge e incident on v in graph
      {
          if(r.first!=i&&m[r.first][i]==m[r.second.first][r.second.second.first])  // matching the colour between two oponent pieces
          {
              q.push(make_pair(i,make_pair(r.second.first,make_pair(r.second.second.first,r.second.second.second+1))));
              
          }
          if(r.second.first!=i&&m[r.second.first][i]==m[r.first][r.second.second.first])
          {
               q.push(make_pair(r.first,make_pair(i,make_pair(r.second.second.first,r.second.second.second+1))));
          
          }
          if(r.second.second.first!=i&&m[r.second.second.first][i]==m[r.second.first][r.first])
          {
               q.push(make_pair(r.first,make_pair(r.second.first,make_pair(i,r.second.second.second+1))));
               
          }

      }
    }
    return -1;

}

int main()
{
  scanf("%d",&n);
  while(n)
  {
    
    scanf("%d%d%d",&a,&b,&c);
    
   a--;b--;c--; 
    for(int i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
         cin>>m[i][j];
      }
    }

      int answer=BFS();
      if(answer==-1)
      printf("impossible\n");
      else
      printf("%d\n",answer); 
      scanf("%d",&n);
  }
  return 0;
}
