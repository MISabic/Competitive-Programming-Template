#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k;
    while(cin>>n){
        int flag=0;
        for(int i=1; i<=n; i++){
            //cout<<"new :: "<<i<<endl;
            long long l=i+1,h=n,mid;
            while(l<=h){    //cout<<l<<"     "<<h<<"      "<<(mid*(mid+1))/2 - (i*(i-1))/2<<endl;
                mid=(l+h)/2;
                if((mid*(mid+1))/2 - (i*(i-1))/2 == n){
                    cout<<i<<" "<<mid<<endl;
                    flag=1;
                    break;
                }
                if((mid*(mid+1))/2 - (i*(i-1))/2 < n){
                    l=mid+1;
                }
                else h=mid-1;
            }
            if(flag==1) break;
        }
        if(flag==0) cout<<-1<<endl;
    }
    return 0;
}


