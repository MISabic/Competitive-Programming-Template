#include<bits/stdc++.h>
#define mem0(a)         memset(a,0,sizeof(a))
#define mem1(a)         memset(a,-1,sizeof(a))
#define memc(a,c)       memset(a,'c',sizeof(a))
#define ll              long long
#define llu             long long unsigned int
#define pb              push_back
#define mkp             make_pair
#define P               pair<int,int>
#define fi              first
#define si              second
#define all(c)          (c).begin(),(c).end()
using namespace std;

int fx1[]={+1,-1,0,0};
int fy1[]={0,0,+1,-1};
int res[1010][1010],visited[1010][1010],arr[1010][1010],finarr[1010][1010],afinarr[1010][1010];

bool isValid(int n, int m, int x, int y)
{
    return (x<n && x>=0 && y<m && y>=0);
}

int main()
{
    int n,m,k,x,y,h,w,sr,sc,fr,fc;
    while(cin>>n>>m){
        mem0(visited);
        mem0(res);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>arr[i][j];
            }
        }
        cin>>h>>w>>sr>>sc>>fr>>fc;
        --sr,--sc,--fr,--fc;






        int k1=0,k2=0;
        for(int i=0; i<n; i++){
            int c=0,res=0;
            k1=0,k2=0;
            for(int j=0; j<w; j++){
                res+=arr[i][j];
            }
            //cout<<"   "<<m-w+1<<endl;
            for(int j=1; j<=m-w+1; j++){
                //cout<<j-1<<"    "<<j+w-1<<"    "<<res<<endl;
                if(res>=1){
                    finarr[i][k1++]=1;
                    //cout<<i<<" hello "<<k1<<endl;
                }
                else finarr[i][k1++]=0;
                if(arr[i][j-1]==1) res-=arr[i][j-1];
                res+=arr[i][j+w-1];
            }
        }

        for(int j=0; j<k1; j++){
            int c=0,res=0,k2=0;
            for(int i=0; i<h; i++){
                res+=finarr[i][j];
            }
            for(int i=1; i<=m-h+1; i++){
                //cout<<i-1<<"    "<<i+h-1<<"    "<<res<<endl;
                if(res>=1){
                    afinarr[k2++][j]=1;
                    //cout<<i<<" hello "<<k1<<endl;
                }
                else afinarr[k2++][j]=0;
                if(finarr[i-1][j]==1) res-=finarr[i-1][j];
                res+=finarr[i+h-1][j];
            }
        }

        //cout<< k1<<"   "<<k2<<endl;

        /*for(int i=0; i<n-h+1; i++){
            int c=0,res=0;
            for(int j=0; j<m-w+1; j++){
                cout<<afinarr[i][j];
            }
            cout<<endl;
        }*/







        queue<P>q;
        visited[sr][sc]=1;
        q.push(mkp(sr,sc));
        while(!q.empty()){
            x=q.front().fi;
            y=q.front().si;
            q.pop();
            for(int i=0; i<4; i++){
                if(isValid(n-h+1,m-w+1,x+fx1[i],y+fy1[i]) && visited[x+fx1[i]][y+fy1[i]]==0 && afinarr[x+fx1[i]][y+fy1[i]]==0){
                    visited[x+fx1[i]][y+fy1[i]]=1;
                    q.push(mkp(x+fx1[i],y+fy1[i]));
                    res[x+fx1[i]][y+fy1[i]]=res[x][y]+1;
                }
            }
        }
        if(visited[fr][fc]==0) cout<<-1<<endl;
        else cout<<res[fr][fc]<<endl;
    }
    return 0;
}

