#include<bits/stdc++.h>
#define eps 0.00000000001
#define fabs(a,b) fabs(a-b)>eps
using namespace std;

double distance(double x1, double y1, double z1, double x2, double y2, double z2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}

int main()
{
    int t,x1,y1,z1,x2,y2,z2,x,y,z;
    cin>>t;
    for(int i=1; i<=t; i++){
        cin>>x1>>y1>>z1>>x2>>y2>>z2>>x>>y>>z;

        tuple<double,double,double> low(x1,y1,z1), high(x2,y2,z2), mid1, mid2;
        double ans=(x1==x2 && y1==y2 && z1==z2)?distance(x1,y1,z1,x,y,z):0;

        while(fabs(get<0>(low),get<0>(high)) || fabs(get<1>(low),get<1>(high)) || fabs(get<2>(low),get<2>(high))){

            double factor1=(get<0>(high)-get<0>(low));
            double factor2=(get<1>(high)-get<1>(low));
            double factor3=(get<2>(high)-get<2>(low));

            mid1=make_tuple( (get<0>(low) + factor1/3), (get<1>(low) + factor2/3), (get<2>(low) + factor3/3) );
            mid2=make_tuple( (get<0>(high) - factor1/3), (get<1>(high) - factor2/3), (get<2>(high) - factor3/3) );

            double dist1=distance(get<0>(mid1), get<1>(mid1), get<2>(mid1), x, y, z);
            double dist2=distance(get<0>(mid2), get<1>(mid2), get<2>(mid2), x, y, z);

            if(dist1<dist2){
                high=make_tuple(get<0>(mid2), get<1>(mid2), get<2>(mid2));
                ans=dist1;
            }
            else if(dist2<dist1){
                low=make_tuple(get<0>(mid1), get<1>(mid1), get<2>(mid1));
                ans=dist2;
            }
            else{
                low=make_tuple(get<0>(mid1), get<1>(mid1), get<2>(mid1));
                high=make_tuple(get<0>(mid2), get<1>(mid2), get<2>(mid2));
                ans=dist1;
            }

            //cout<<get<0>(low)<<" "<<get<1>(low)<<" "<<get<2>(low)<<" "<<get<0>(high)<<" "<<get<1>(high)<<" "<<get<2>(high)<<" "<<dist1<<" "<<dist2<<endl;

        }

        printf("Case %d: %.10lf\n",i,ans);
    }
    return 0;
}

