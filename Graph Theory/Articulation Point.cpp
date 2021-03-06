#include<bits/stdc++.h>
using namespace std;

int cnt=0,visited[100100],disc[100100],low[100100],parent[100100],ap[100100];
                                            //low = personal_cnt, ap = articulation_points
vector<int>vec[100100];

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

            if(parent[src]==-1 && child>1) {
                ap[src]=1;
            }

            low[src]=min(low[src],low[cur]);

            if(parent[src]!=-1 && low[cur]>=disc[src]){
                ap[src]=1;
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

        memset(ap,0,sizeof(ap));
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

        int num=0;
        for(int i=0; i<n; i++){
            if(ap[i]==1)
                ++num;
        }
        cout<<num<<endl;
        for(int i=0; i<=n; i++){
            if(ap[i]==1)
                cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
