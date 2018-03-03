#include<bits/stdc++.h>
using namespace std;
#define MAX 10007
typedef pair<int,int> pii;
vector<pii> edge[MAX];
int dist[MAX];
bool visited[MAX];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[u].push_back(make_pair(v,w));
        //edge[v].push_back(make_pair(u,w)); //FOR BIDIRECTIONAL
    }
    for(int i=1;i<=n;i++)
        dist[i]=INT_MAX;

    dist[1]=0;

    multiset<pii> s;
    s.insert(make_pair(0,1));
    while(!s.empty()){
        pii x=*s.begin();
        s.erase(x);

        int u=x.second;
        int c=x.first;

        if(visited[u]) continue;

        visited[u]=true;

        for(int i=0;i<edge[u].size();i++){
            int v=edge[u][i].first;
            int w=edge[u][i].second;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                s.insert(make_pair(dist[v],v));
            }
        }
    }

    for(int i=2;i<=n;i++){
        cout<<dist[i]<<" ";
    }

    return 0;
}

