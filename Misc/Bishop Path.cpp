#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,n,m,x,y;
    cin>>t;
    while(t--){
        cin>>n>>m>>x>>y;
        ll k1=max(x+m-y,x+y-1); //upor ar nich borabor jei koyta ghor ase sei koytatei ami jete parbo [konakuni]
        ll k2=min(n,k1);
        ll k3=min(x-(m-y),x-(y-1));
        ll k4=max(1LL,k3);
        ll res=(min(k2,x+m-y)-x)+(min(k2,x+y-1)-x)+(x-(max(k4,x-(m-y))))+(x-(max(k4,x-(y-1))));
        cout<<res+1<<endl;
    }
    return 0;
}

