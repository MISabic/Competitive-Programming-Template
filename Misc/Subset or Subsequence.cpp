#include<bits/stdc++.h>
using namespace std;

long long n,k,arr[50],c=0;
string str;

void subseq(long long i,string s)
{
    long long n=str.size();
    if(i==n)
    {
        if(!s.empty()){

            /*cout<<s<<endl;*/  /** here "s" is a subset or subsequence */

            long long res=1,flag=0;
            for(int i=0; i<s.length(); i++){
                res*=(arr[s[i]-'0']);
                if(res>k){
                    flag=1;
                    break;
                }
            }
            if(res<=k && flag==0) ++c;

        }
        return;
    }
    subseq(i+1,s);
    s.push_back(str[i]);
    subseq(i+1,s);
}

int main()
{
    while(scanf("%lld %lld",&n,&k)==2){
        str="";
        for(int i=0; i<n; i++) str+=(i+'0');
        for(int i=0; i<n; i++){
            scanf("%lld",&arr[i]);
        }
        c=0;
        string temp;
        subseq(0,temp);
        printf("%lld\n",c);
    }
}

