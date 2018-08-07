/**
    there is only one way to choose 0 from n
    http://math.stackexchange.com/questions/461194/prove-pascals-rule-algebraically
    http://math.stackexchange.com/questions/20475/proving-pascals-rule-n-choose-r-n-1-choose-r-1n-1-choose
*/

#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long ncr[1010][1010];

void combination()
{
    for(long long i=0; i<=1005; i++){
        for(long long j=0; j<=i; j++){
            if(j==0)
                ncr[i][j]=1;
            else
                ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;
        }
    }
}

int main()
{
    combination();
    for(int i=0; i<=10; i++){
        for(int j=0; j<=i; j++){
            cout<<i<<"    "<<j<<"   ::   "<<ncr[i][j]<<endl;
        }
    }
    return 0;
}




/*

#include<bits/stdc++.h>
using namespace std;

long long combination(long long n,long long r)
{
    long long res=1;
    for(long long i=1; i<=r; i++){
        res=(res*(n-r+i))/i;
    }
    return res;
}

int main()
{
    long long n,r,res;
    while(cin>>n>>r && (n || r)){
        r=min(r,n-r);
        cout<<combination(n,r)<<endl;
    }
    return 0;
}

*/
