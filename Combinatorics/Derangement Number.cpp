/**
    !n = sub-factorial or derangement number

    !n = n * !(n-1) + (-1)^n

    !n = (n-1) * (!(n-1) + !(n-2))

    !n = n! * sigma [from k=0 to n] ( (-1)^k / k! )
*/

#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long den[1010];

void derangement()
{
    den[0]=1;
    den[1]=0;
    den[2]=1;
    for(long long i=3; i<=1005; i++){
        den[i]=(i-1)*(den[i-1]+den[i-2])%mod;
    }
}

int main()
{
    derangement();
    for(int i=0; i<=1000; i++){
        cout<<i<<"   ::   "<<den[i]<<endl;
    }
    return 0;
}

