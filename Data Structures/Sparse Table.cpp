#include<bits/stdc++.h>
#define ssz 100000
#define col 7
using namespace std;

int input[ssz],sparse[ssz][col];

void build_sparse(int n)
{
    for(int i=0; i<n; i++) {
        sparse[i][0]=i;
    }

    for(int j=1; 1<<j<=n; j++) {
        for(int i=0; i+(1<<j)-1<n; i++) {
            if(input[sparse[i][j-1]] < input[sparse[i+(1<<(j-1))][j-1]]){
                sparse[i][j]=sparse[i][j-1];
            }
            else{
                sparse[i][j]=sparse[i+(1<<(j-1))][j-1];
            }
        }
    }
}

long long query(int low,int high)
{
    int l=high-low+1;
    int k=log2(l);
    if(input[sparse[low][k]]<=input[sparse[low+l-(1<<k)][k]]){
        return input[sparse[low][k]];
    }
    else{
        return input[sparse[high-(1<<k)+1][k]];
    }
}

int main()
{
    int n,L,R,q;
    cin>>n; // input array size
    for(int i=0; i<n; i++)
        cin>>input[i]; // between -10^9 and 10^9

    build_sparse(n);

    cin>>q; // number of queries
    for(int i=0; i<q; i++) {
        cin>>L>>R; // boundaries of next query, 0-indexed
        long long answer=query(L,R);
        cout<<answer<<endl;
    }
    return 0;
}
