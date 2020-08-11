#include<bits/stdc++.h>
using namespace std;

stack<int>st;

void scc(vector<int>vec[],int visited[],int v)
{
    visited[v]=1;
    for(int i=0; i<vec[v].size(); i++){
        int x=vec[v][i];
        if(!visited[x]){
            scc(vec,visited,x);
        }
    }
    st.push(v);
}

int main()
{
    //freopen("out.txt","w",stdout);
    int t,n,m,a,b;
    scanf("%d",&t);
    for(int i=1; i<=t; i++){
        scanf("%d %d",&n,&m);
        vector<int>graph[n+5],graphTranspose[n+5];
        for(int j=0; j<m; j++){
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
            graphTranspose[b].push_back(a);
        }
        int visited[n+5];
        memset(visited,0,sizeof(visited));
        for(int j=1; j<=n; j++){
            if(!visited[j])
                scc(graph,visited,j);
        }
        memset(visited,0,sizeof(visited));
        int cnt=0;
        while(!st.empty()){
            int x=st.top();
            st.pop();
            if(!visited[x]){
                ++cnt;
                scc(graphTranspose,visited,x);
            }
        }
        printf("Case %d: %d\n",i,cnt);
    }
}
