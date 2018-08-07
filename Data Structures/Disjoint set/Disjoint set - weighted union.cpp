#include<bits/stdc++.h>
using namespace std;

int par[100010],sz[100010];

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
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,x,y;
    cin>>n>>m;
    for(int i=0; i<=n; i++)     // important part - initialization
        par[i]=i;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        unioner(x,y);
    }
    for(int i=1; i<=n; i++)
        cout<<i<<"  ::  "<<par[i]<<endl;
    return 0;
}

