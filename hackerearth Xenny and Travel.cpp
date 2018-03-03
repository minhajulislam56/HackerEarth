#include<bits/stdc++.h>
using namespace std;
#define MAX 1300
const int inf=1e5+7;
int dist[MAX];
int n;
bool visited[MAX];
int road[MAX][MAX],rroad[MAX][MAX],rail[MAX][MAX],rrail[MAX][MAX];
void dijkstra(int s, int arr[][MAX])
{
    for(int i=1;i<=n;i++) dist[i]=inf;
    memset(visited,false,sizeof visited);

    dist[s]=0;

    while(true){
        int u=-1, bdist=inf;
        for(int i=1;i<=n;i++){
            if(!visited[i] && dist[i]<bdist){
                u=i;
                bdist=dist[i];
            }
        }
        if(bdist==inf) break;
        for(int i=1;i<=n;i++){
            if(!visited[i] && arr[u][i]<inf && u!=i){
                if(dist[u]+arr[u][i]<dist[i])
                    dist[i]=dist[u]+arr[u][i];
            }
        }
        visited[u]=true;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            if(i==j) x=inf;
            road[i][j]=rroad[j][i]=x;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            if(i==j) x=inf;
            rail[i][j]=rrail[j][i]=x;
        }
    }
    int u,v;
    cin>>u>>v;
    dijkstra(u,road);
    int tmp[MAX];
    for(int i=1;i<=n;i++)
        tmp[i]=dist[i];
    dijkstra(v,rrail);
    int ans=inf;
    for(int i=1;i<=n;i++){
        if(i!=u && i!=v)
            ans=min(ans,tmp[i]+dist[i]);
    }

    dijkstra(u,rail);
    for(int i=1;i<=n;i++)
        tmp[i]=dist[i];
    dijkstra(v,rroad);
    for(int i=1;i<=n;i++){
        if(i!=u && i!=v){
            ans=min(ans,tmp[i]+dist[i]);
        }
    }
    cout<<ans<<endl;

    return 0;
}
