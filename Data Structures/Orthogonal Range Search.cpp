#include<bits/stdc++.h>
using namespace std;

int t,n,q,l,r,s,arr[505][505],st[505][505][10];

int sparse_table()
{
    //cout<<floor(log2(n))<<endl;
    int st_range=floor(log2(n));
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            st[k][i][0]=arr[k][i];
        }

        for(int i=1; i<=st_range; i++){
            int range=n-(1<<i);
            for(int j=0; j<=range; j++){
                st[k][j][i]=max(st[k][j][i-1],st[k][j+(1<<(i-1))][i-1]);
            }
        }
    }
}

int main()
{
    //freopen("out.txt","w",stdout);
    scanf("%d",&t);
    for(int i=1; i<=t; i++){
        scanf("%d %d",&n,&q);

        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                scanf("%d",&arr[j][k]);
            }
        }
        sparse_table();

        /*for(int j=0; j<n; j++){
            for(int k=0; k<=floor(log2(n)); k++){
                printf("%d ",st[13][j][k]);
            }
            cout<<endl;
        }*/

        printf("Case %d:\n",i);
        for(int j=0; j<q; j++){
            scanf("%d %d %d",&l,&r,&s);

            --l,--r;
            int q=floor(log2(s)),res=0;
            for(int k=l; k<l+s; k++){
                res=max(res,max(st[k][r][q],st[k][(r+s)-(1<<q)][q]));
                //cout<<"here :: "<<k<<" "<<r<<" "<<(r+s)-(1<<q)<<" "<<st[k][r][q]<<" "<<st[k][r+s-1-q][q]<<endl;
            }
            printf("%d\n",res);
        }
    }
    return 0;
}
