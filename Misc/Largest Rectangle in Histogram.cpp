#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,arr[50000],c=0;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        stack<int>st;
        int area=0,mxarea=-1,i;
        for(i=0; i<n; ){
            if(st.empty() || (arr[i]>=arr[st.top()])){
                st.push(i++);
            }
            else{
                int top=st.top();
                st.pop();
                if(st.empty()){
                    area=arr[top]*i;
                }
                else{
                    area=arr[top]*(i-st.top()-1);
                }
                if(area>mxarea)
                    mxarea=area;
            }
        }
        while(!st.empty()){
            int top=st.top();
            st.pop();
            if(st.empty()){
                area=arr[top]*i;
            }
            else{
                area=arr[top]*(i-st.top()-1);
            }
            if(area>mxarea)
                mxarea=area;
        }
        printf("Case %d: %d\n",++c,mxarea);
    }
    return 0;
}
