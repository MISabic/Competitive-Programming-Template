#include<bits/stdc++.h>
#define mx 100000000000LL

using namespace std;

struct edge
{
    long long v,w;
    edge(){}
    edge(long long to, long long weight){
        v=to, w=weight;
    }
    bool operator<(edge e)const{
        return w>e.w;
    }
};

long long dist[100100],res[100100];

void dijkstra(long long src,vector<edge>*vec)
{
    priority_queue<edge>pq;
    pq.push(edge(src,0));
    dist[src]=0;
    while(!pq.empty()){
        //cout<<"  hello  "<<endl;
        edge E=pq.top();
        pq.pop();

        int sz=vec[E.v].size();

        for(int i=0; i<sz; i++){
            edge adj=vec[E.v][i];

            if(E.w+adj.w<dist[adj.v]){

                dist[adj.v] = E.w + adj.w;
                pq.push(edge(adj.v,dist[adj.v]));
                res[adj.v]=E.v;

            }

        }
    }
}

int main()
{
    int n,m,u,v,w;
    while(cin>>n>>m){
        vector<edge>vec[100100];
        memset(res,0,sizeof(res));
        for(int i=0; i<m; i++){
            cin>>u>>v>>w;
            vec[u].push_back(edge(v,w));
            vec[v].push_back(edge(u,w));
            res[u]=1;
            res[v]=1;
        }
        /*for(int j=0; j<m; j++){
            for(int i=0; i<vec[j].size(); i++){
                cout<<j<<"   ::   "<<vec[j][i].v<<"    "<<vec[j][i].w<<endl;
            }
        }*/

        for(int i=0; i<100005; i++)
            dist[i]=mx;

        dijkstra(1,vec);

        if(dist[n]==mx) cout<<-1<<endl;
        else{
            stack<long long>st;
            while(n!=1){
                st.push(n);
                n=res[n];
            }
            st.push(1);
            while(!st.empty()){
                cout<<st.top()<<" ";
                st.pop();
            }
            cout<<endl;
        }
    }
}




/**     An Example :D

#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define mx 100000000000000LL

using namespace std;

struct edge
{
    long long v,w;
    edge(){}
    edge(long long to, long long weight){
        v=to, w=weight;
    }
    bool operator<(edge e)const{
        return w>e.w;
    }
};

long long dist[100100],res[100100],visited[100100];

void dijkstra(long long k,long long x,long long src,vector<edge>*vec)
{
    priority_queue<edge>pq;
    pq.push(edge(src,0));
    dist[src]=0;
    int flag=0;
    while(!pq.empty()){
        edge E=pq.top();
        pq.pop();

        if(E.v<=k && flag==0){
            flag=1;
            for(int i=1; i<=k; i++){
                if(E.v==i) continue;

                if(E.w+x<dist[i]){
                    dist[i] = E.w + x;
                    if(visited[i]==0){
                        pq.push(edge(i,dist[i]));
                        visited[i]=1;
                        flag=0;
                    }
                }
            }
        }

        long long sz=vec[E.v].size();
        for(int i=0; i<sz; i++){
            edge adj=vec[E.v][i];

            if(E.w+adj.w<dist[adj.v]){

                dist[adj.v] = E.w + adj.w;
                pq.push(edge(adj.v,dist[adj.v]));
                visited[adj.v]=1;
            }
        }
    }
}

int main()
{
    long long t,n,k,x,m,s,u,v,w;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld %lld %lld %lld",&n,&k,&x,&m,&s);
        vector<edge>vec[100100];
        for(int i=0; i<m; i++){
            scanf("%lld %lld %lld",&u,&v,&w);
            vec[u].push_back(edge(v,w));
            vec[v].push_back(edge(u,w));
        }

        for(int i=0; i<=n+10; i++)
            dist[i]=mx;

        dijkstra(k,x,s,vec);

        memset(visited,0,sizeof(visited));

        for(int i=1; i<=n; i++)
            printf("%lld ",dist[i]);
        printf("\n");
    }
}
*/
