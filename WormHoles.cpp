    
#include <iostream>
#include <limits.h>
#include<bits/stdc++.h>

using namespace std;

//First Refer Dijkstra Algorithm for grid matrix graph

struct Point {
    int x,y;
};


bool AllVisited(bool* visited, int V) {
    for(int i=0;i<V;i++) if(visited[i]==false) return false;
    return true;
}

// driver program to test above function
int main()
{
    int N;
    cin>>N;
    int V = 2*N + 2;
    int grid[V][V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            grid[i][j]=-2;
         }
    }
    Point input[V];
    cin>>input[0].x>>input[0].y; //start, point of source
    cin>>input[1].x>>input[1].y; //end, point of destination
    int k=2,cost;
    while(k<V) {
        cin>>input[k].x>>input[k].y>>input[k+1].x>>input[k+1].y>>cost;
        grid[k][k+1]=grid[k+1][k]=cost;
        k+=2;
    }
    for(int i=0;i<V;i++) grid[i][i]=-1;
    for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            if(grid[i][j]==-2) {
                grid[i][j]=abs(input[i].x-input[j].x) + abs(input[i].y-input[j].y);
            }
        }
    }

    //printing grid
    for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }

	//dijkstra for grid with source 0

    bool visited[V];
    for(int i=0;i<V;i++) visited[i]=false;

    int source=0;
    int dist[V];
    for(int i=0;i<V;i++) dist[i]=INT_MAX;
    dist[0]=0;

    while(!AllVisited(visited,V)) {
        visited[source]=true;
        int u,min=INT_MAX;
        for(int i=0;i<V;i++) {
            if(grid[source][i]!=-1 && !visited[i]) {

                if(dist[source]+grid[source][i]<dist[i])
                {
                    dist[i]=dist[source]+grid[source][i];
                }
            }
            if(!visited[i] && min>dist[i]) {
                min=dist[i];
                u=i;
            }
        }
        source=u;
    }

    cout<<"\n\n";
    for(int i=0;i<V;i++) cout<<dist[i]<<" ";
    cout<<"\n\nANS: "<<dist[1];
	return 0;
}
/*#include<bits/stdc++.h>
using namesapce std;
int n;
int entryX[12];
int entryY[12];
int exitX[12];
int exitY[12];
int cost[12];
int y[12];
int dp[12][12];
int main()
{
	cin>>n;
	cin>>entryX[0]>>entryY[0];
	exitX[0]=entryX[0];
	exitY[0]=entryY[0];
	cin>>entryX[n+1]>>entryY[n+1];
	exitX[n+1]=entryX[n+1];
	exitY[n+1]=entryY[n+1];
	cost[0]=-1;
	cost[n+1]=-1;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		cin>>entryX[i]>>entryY[i]>>exitX[i]>>exitY[i]>>cost[i];
	}
		
	for(int i=0;i<=(n+1);i++)
	{
		for(int j=0;j<=(n+1);j++)
		{
			if(i==j)
				continue;
				
		}
	}
}*/
