#include<bits/stdc++.h>
using namespace std;

/** kadane function*/

int kadane(int arr[],int n)	//n=how many elements
{
    int sum=0,ans=0,k=0;

    for(int i=0; i<n; i++){
        if(arr[i]<=0) ++k;    //k; Check if all are negative
    }

    if(k==n){
        cout<<"All negative values."<<endl;
        return 0;
    }

	for(int i=0; i<n; i++){
        if(sum+arr[i]<0)
            sum=0;
        else
            ans=max(ans,sum+=arr[i]);
    }

	return ans;
}

int main(int argc, char const *argv[])
{
	int arr[] = {1, -4, 1, -10, -11, 2, -6};
	cout<<kadane(arr,4)<<"\n";
	return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,arr[10101];
    while(cin>>n && n){
        int sum=0,ans=0,k=0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            if(arr[i]<=0) ++k;
        }
        if(k==n){
            cout<<"Losing streak."<<endl;
            continue;
        }
        for(int i=0; i<n; i++){
            if(sum+arr[i]<0)
                sum=0;
            else
                ans=max(ans,sum+=arr[i]);
        }
        cout<<"The maximum winning streak is "<<ans<<"."<<endl;
    }
    return 0;
}
*/
