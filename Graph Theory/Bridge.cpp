#include<bits/stdc++.h>
using namespace std;

int cnt=0,visited[100100],disc[100100],low[100100],parent[100100];
                                    //low = personal_cnt
vector<int>vec[100100];
vector< pair<int,int> >bridges;

struct Bridges{
    int s;
    int t;
    Bridges(int u,int v){
        s = min(u,v);
        t = max(u,v);
    }
};

vector<Bridges> bridgeList;

bool cmp(Bridges a,Bridges b){
    if(a.s == b.s) return (a.t<b.t);
    return (a.s<b.s);
}

void dfs(int src)
{
    //cout<<"source :: "<<src<<endl;
    visited[src]=1;
    disc[src]=low[src]=(++cnt);
    int child=0;

    for(int i=0; i<vec[src].size(); i++){
        int cur=vec[src][i];

        if(visited[cur]==0){
            child++;
            parent[cur]=src;
            dfs(cur);

            low[src]=min(low[src],low[cur]);

            if(low[cur]>disc[src]){
                bridgeList.push_back({cur,src});
            }
        }
        else if(cur!=parent[src]){
            low[src]=min(low[src],disc[cur]);
        }
    }
}

int main()
{
    int n,m,u,v;
    while(cin>>n>>m){
        for(int i=0; i<=n; i++) vec[i].clear();

        memset(low,0,sizeof(low));
        memset(disc,0,sizeof(disc));
        memset(parent,-1,sizeof(parent));
        memset(visited,0,sizeof(visited));

        for(int i=0; i<m; i++){
            cin>>u>>v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        for(int i=0; i<n; i++){
            cnt=0;
            if(visited[i]==0){
                dfs(i);
            }
        }

        sort(bridgeList.begin(),bridgeList.end(),cmp);

        cout<<endl<<bridgeList.size()<<endl;
        for(int i=0; i<bridgeList.size(); i++){
            cout<<bridgeList[i].s<<" "<<bridgeList[i].t<<endl;
        }
        bridgeList.clear();
    }
    return 0;
}

