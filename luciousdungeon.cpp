/*
Input:
2
4 3 
2 3 2
2 5 1
5 3 1
3 1 1
4 2 15
2 2
1 2
1 1
2 2 2

Output:
YES
4
NO
*/
#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#define INF 99999999

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int a,b,T;
int m,n;
vector< vector<int> > dist(101,vector<int>(101,0));
vector< vector<int> > rectgrid(101,vector<int>(101,INF));
vector< vector<int> > visited(101,vector<int>(101,0));
int x1,y1;

  
  typedef bool (*comp)(pair<int,int>,pair<int,int>);
  
  bool compare( pair<int,int> a,pair<int,int> b)  
  {  
      return dist[a.first][a.second] > dist[b.first][b.second];  
  }  
  

void DIJ()
{
    //std::priority_queue<pair<int,int >, std::vector< pair<int, int > >, std::greater< pair<int, int > > > pq; //it will be using as a min heap in priority queue
        
        priority_queue< pair<int,int>,vector< pair<int,int> >, comp> pq(compare); 

        dist[0][0]=rectgrid[0][0];  //initialize distance of the source vertices as rectgrid value given
        pq.push(make_pair(0,0));       
        visited[0][0]=1;           //mark source vertex as visited
       
        while(!pq.empty())
        {
            pair<int,int > d=pq.top();
                pq.pop();

            x1=d.first; // }  // Coordinates / Pick the minimum distance vertex from the set of vertices not
                               // yet processed. u is always equal to src in first iteration.
            y1=d.second;   

            if(x1==a&&y1==b)
            { //final coordinate found then return
                return;
            }

            for(int i=0;i<4;i++)  // Find shortest path for all vertices
            {
                 int ax=dx[i]+x1;    // dx[4]={1,-1,0,0};
                 int ay=dy[i]+y1;    // dy[4]={0,0,-1,1};
                 if(ax<0||ax>=m||ay<0||ay>=n||visited[ax][ay]==1||dist[ax][ay]<rectgrid[ax][ay]+dist[x1][y1]) 
                 {
                    continue;
                 }
                 dist[ax][ay]=rectgrid[ax][ay]+dist[x1][y1];
                 visited[ax][ay]=1;
                 pq.push(make_pair(ax,ay));
            }
        }

}

int main(int argc, char const *argv[])
{
    int k;
    scanf("%d",&k);
    while(k--)
    {
        m=0,n=0;
        scanf("%d%d",&m,&n);
        for(int i=0;i<m;i++)
        {
           for(int j=0;j<n;j++)
           {
                scanf("%d",&rectgrid[i][j]);
                dist[i][j]=INF; 
                visited[i][j]=0;       
           }
        }
        a=0,b=0,T=0; 
        scanf("%d%d%d",&a,&b,&T);
        
        DIJ();
        printf("\n");
      
        if(dist[a-1][b-1]<=T)
        {
            printf("YES");
            printf("\n%d",T-dist[a-1][b-1]);
        }
        else
            printf("NO");

    }
     

    return 0;
}
