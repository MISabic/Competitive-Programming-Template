#include<bits/stdc++.h>
using namespace std;

struct data{
    int u,v,w;
    data(int from,int to,int weight){
        u=from,v=to,w=weight;
    }
    bool operator<(data p)const{
        return w<p.w;
    }
};

int t,n,m,u,v,w,a,c=0,par[10010],sz[10010];
long long cnt=0,res=0;
map<pair<int,int>,int>mp;

int finder(int x)
{
    if(par[x]==x) return x;
    return par[x]=finder(par[x]);
}

void unioner(int a,int b)       // based on set size
{
    int para,parb;
    para=finder(a);
    parb=finder(b);
    if(para==parb)
    {
        //sz[para]++;
        return;
    }
    if(sz[para]==sz[parb])
    {
        par[parb]=para;
        sz[para]+=sz[parb]+1;
    }
    else if(sz[parb]>sz[para])
    {
        par[para]=parb;
        sz[parb]+=sz[para]+1;
    }
    else if(sz[para]>sz[parb])
    {
        par[parb]=para;
        sz[para]+=sz[parb]+1;
    }
    cnt+=mp[make_pair(min(a,b),max(a,b))];
}

int main()
{
    cin>>t;
    while(t--){
        cin>>n>>m>>a;
        vector<data>graph;
        for(int i=0; i<m; i++){
            cin>>u>>v>>w;
            int x=u,y=v;
            u=min(x,y),v=max(x,y);
            if(w>=a) continue;
            if(mp[make_pair(u,v)]==0)
                mp[make_pair(u,v)]=w;
            else
                mp[make_pair(u,v)]=min(mp[make_pair(u,v)],w);
        }
        cnt=res=0;

        map<pair<int,int>,int>::iterator it=mp.begin();
        for(it; it!=mp.end(); it++){
            graph.push_back(data((it->first).first,(it->first).second,it->second));
        }
        sort(graph.begin(),graph.end());
        /*for(int i=0; i<graph.size(); i++){
            cout<<graph[i].u<<"     "<<graph[i].v<<"     "<<graph[i].w<<endl;
        }*/

        for(int i=0; i<=n; i++)
            par[i]=i;

        for(int i=0; i<graph.size(); i++){
            unioner(graph[i].u,graph[i].v);
        }

        unordered_set<int>st;
        for(int i=1; i<=n; i++){
            finder(i);
            st.insert(par[i]);
        }

        cnt+=(a*st.size());
        printf("Case #%d: %lld %d\n",++c,cnt,st.size());
        mp.clear();
    }
    return 0;
}

