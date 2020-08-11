#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,r,u,v,w;
    scanf("%d",&t);
    for(int i=1; i<=t; i++){
        scanf("%d %d",&n,&r);
        vector<pair<int,int>>graph[n+5];
        vector<pair<int,int>>dist(n+5,{100000000,100000000});
        for(int j=0; j<r; j++){
            scanf("%d %d %d",&u,&v,&w);
            graph[u].push_back({w,v});
            graph[v].push_back({w,u});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        dist[1].first=0;

        while(!pq.empty()){
            pair<int,int> x=pq.top();
            pq.pop();
            int sz=graph[x.second].size();
            for(int j=0; j<sz; j++){
                pair<int,int>temp=graph[x.second][j];
                int newDist=x.first+temp.first;
                if(newDist<dist[temp.second].first){
                    dist[temp.second]={newDist,dist[temp.second].first};
                    pq.push({dist[temp.second].first,temp.second});
                }
                else if(newDist>dist[temp.second].first && newDist<dist[temp.second].second){
                    dist[temp.second]={dist[temp.second].first,newDist};
                    pq.push({dist[temp.second].second,temp.second});
                }
            }
        }

        printf("Case %d: %d\n",i,dist[n].second);
    }
    return 0;
}
