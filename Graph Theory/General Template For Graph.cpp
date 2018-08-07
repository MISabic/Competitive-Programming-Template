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
int fx2[]={+1,-1,0,0,+1,+1,-1,-1};
int fy2[]={0,0,+1,-1,+1,-1,-1,+1};
int fxh[]={+1,-1,+2,-2,+1,+2,-2,-1};
int fyh[]={-2,-2,-1,-1,+2,+1,+1,+2};
int res[1010][1010],visited[1010][1010];

bool isValid(int n, int m, int x, int y)
{
    return (x<=n && x>0 && y<=m && y>0);
}

int main()
{
    int n,m,bombs,numberofbombs,k,x,y,su,sv,eu,ev;
    char ch,ph;
    while(cin>>ch>>sv>>ph>>ev){
        su=(int)ch-96;
        eu=(int)ph-96;
        queue<P>q;
        mem0(visited);
        mem0(res);
        visited[su][sv]=1;
        q.push(mkp(su,sv));
        while(!q.empty()){
            int x=q.front().fi;
            int y=q.front().si;
            q.pop();
            for(int i=0; i<8; i++){
                if(isValid(8,8,x+fxh[i],y+fyh[i]) && visited[x+fxh[i]][y+fyh[i]]==0){
                    visited[x+fxh[i]][y+fyh[i]]=1;      //cout<<i<<"   "<<x+fxh[i]<<"  ::  "<<y+fyh[i]<<endl;
                    q.push(mkp(x+fxh[i],y+fyh[i]));
                    res[x+fxh[i]][y+fyh[i]]=res[x][y]+1;
                }
            }
        }
        /*for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                cout<<i<<"  ::  "<<j<<"  ::  "<<res[i][j]<<endl;
            }
        }*/
        printf("To get from %c%d to %c%d takes %d knight moves.\n",ch,sv,ph,ev,res[eu][ev]);
    }
}

/*

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
int res[1010][1010],visited[1010][1010];

bool isValid(int n, int m, int x, int y)
{
    return (x<n && x>=0 && y<m && y>=0);
}

int main()
{
    int n,m,bombs,numberofbombs,k,x,y,su,sv,eu,ev;
    while(cin>>n>>m && (n || m) && cin>>bombs){
        mem0(visited);
        mem0(res);
        for(int i=0; i<bombs; i++){
            cin>>x>>numberofbombs;
            for(int j=0; j<numberofbombs; j++){
                cin>>k;
                visited[x][k]=1;
            }
        }
        cin>>su>>sv>>eu>>ev;
        queue<P>q;
        visited[su][sv]=1;
        q.push(mkp(su,sv));
        while(!q.empty()){
            x=q.front().fi;
            y=q.front().si;
            q.pop();
            for(int i=0; i<4; i++){
                if(isValid(n,m,x+fx1[i],y+fy1[i]) && visited[x+fx1[i]][y+fy1[i]]==0){
                    visited[x+fx1[i]][y+fy1[i]]=1;      //cout<<i<<"   "<<x+fxh[i]<<"  ::  "<<y+fyh[i]<<endl;
                    q.push(mkp(x+fx1[i],y+fy1[i]));
                    res[x+fx1[i]][y+fy1[i]]=res[x][y]+1;
                }
            }
        }
        cout<<res[eu][ev]<<endl;
    }
    return 0;
}
*/
