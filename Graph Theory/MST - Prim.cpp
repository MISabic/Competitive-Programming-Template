/** Maximum ST*/


#include<bits/stdc++.h>
using namespace std;

struct data{
    int src;
    int w;
    data(int s,int weight){
        src=s,w=weight;
    }
    bool operator<(data p)const{
        return w<p.w;
    }
};

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,wi,c=0;
    string from,to;
    while(cin>>n>>m && (n || m)){

        map<string,int>mp;
        vector<int>vec[500];
        int num=1,arr[250][250],visited[250],mx=10000000;

        memset(arr,0,sizeof(arr));

        for(int i=0; i<m; i++){
            cin>>from>>to>>wi;

            if(mp[from]==0) mp[from]= num++;
            if(mp[to]==0) mp[to]= num++;

            int x=mp[from],y=mp[to];

            vec[x].push_back(y);
            vec[y].push_back(x);

            if(arr[x][y]<wi){
                arr[x][y]=wi;
                arr[y][x]=wi;

            }
        }
        memset(visited,0,sizeof(visited));

        cin>>from>>to;

        priority_queue<data>pq;
        pq.push(data(mp[from],10000000));

        while(!pq.empty()){     //cout<<pq.top().src<<"     "<<pq.top().w<<endl;

            int x=pq.top().src,sz=vec[x].size();

            if(pq.top().w<mx) mx=pq.top().w;

            if(x==mp[to]) break;

            pq.pop();
            visited[x]=1;

            for(int i=0; i<sz; i++){
                if(visited[vec[x][i]]==0){
                    pq.push(data(vec[x][i],arr[x][vec[x][i]]));
                }
            }

        }
        cout<<"Scenario #"<<++c<<endl;
        cout<<mx<<" tons"<<endl;
        cout<<endl;
    }
    return 0;
}


/** Minimum ST*/

/**

#include<bits/stdc++.h>
using namespace std;

struct data{
    int src;
    int w;
    data(int s,int weight){
        src=s,w=weight;
    }
    bool operator<(data p)const{
        return w>p.w;
    }
};

int main()
{
    int n,m,u,v,w;
    while(cin>>n>>m){
        vector<int>vec[10010];
        map<pair<int,int>,int>mp;
        for(int i=0; i<m; i++){
            cin>>u>>v>>w;
            if(u==v)
                vec[u].push_back(v);
            else{
                vec[u].push_back(v);
                vec[v].push_back(u);
            }
            int val=mp[make_pair(u,v)];
            if(val!=0 && val>w){
                mp[make_pair(u,v)]=w;
                mp[make_pair(v,u)]=w;
            }
            else if(val==0){
                mp[make_pair(u,v)]=w;
                mp[make_pair(v,u)]=w;
            }
        }
        int visited[10010];
        long long res=0;
        memset(visited,0,sizeof(visited));
        priority_queue<data>pq;
        pq.push(data(1,0));
        while(!pq.empty()){
            int x=pq.top().src;     //cout<<x<<"     "<<pq.top().w<<endl;
            if(visited[x]==0) res+=(long long)pq.top().w;
            visited[x]=1;
            pq.pop();
            for(int i=0; i<vec[x].size(); i++){
                if(visited[vec[x][i]]==0){
                    pq.push(data(vec[x][i],mp[make_pair(vec[x][i],x)]));
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}

*/

