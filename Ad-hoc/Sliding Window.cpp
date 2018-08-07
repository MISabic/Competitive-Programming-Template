#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

ll arr[300100],calc[100100];
vector<ll>vec;

void sliding_window(ll arr[],ll n,ll k)
{
    deque<ll>  Qi(k);

    int i;
    for(i=0; i<k; i++){
        while((!Qi.empty()) && arr[i]<=arr[Qi.back()])
            Qi.pop_back();

        Qi.push_back(i);
    }

    for( ; i<n; ++i){
        vec.push_back(Qi.front());

        while((!Qi.empty()) && Qi.front()<=i-k)
            Qi.pop_front();

        while((!Qi.empty()) && arr[i]<=arr[Qi.back()])
            Qi.pop_back();

        Qi.push_back(i);
    }

    vec.push_back(Qi.front());
}

int main()
{
    ll t,k,n,m,p,q,r,s,a,b,c;
    string str;
    double x,y;
    map<string,int>mp;
    while(cin>>n>>k){
        ll cnt=999999999999,chidori=0,total=0,flag=0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        for(int i=n; i<n+k+5; i++) arr[i]=999999999999;
        sliding_window(arr,n+k+2,k+1);
        for(int i=0; i<n; i++){
            if(arr[vec[i]]<arr[i] && vec[i]!=i){    //cout<<"hello"<<endl;
                swap(arr[vec[i]],arr[i]);
                flag=1;
                break;
            }
        }
        for(int i=0; i<n; i++) cout<<arr[i]<<" ";
        cout<<endl;
        vec.clear();
    }
    return 0;
}


