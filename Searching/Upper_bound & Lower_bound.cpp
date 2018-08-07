#include<bits/stdc++.h>
using namespace std;

#define MAX 999999999999999LL

long long minValue(long long toSearch, long long sz, long long *arr)
{
    long long index,start,last,mid;
    if(toSearch<=arr[0])
        return -1;
    else{
        start=0, last=sz;
        while(start<=last){
            mid=(start+last)/2LL;       //cout<<mid<<"     "<<arr[mid]<<"     "<<arr[mid+1]<<endl;
            if(arr[mid]<toSearch && arr[mid+1]>=toSearch)
                break;
            if(arr[mid]>=toSearch)
                last=mid;
            else if(arr[mid]<toSearch && arr[mid+1]<=toSearch)
                start=mid;
        }
        index=mid;
    }
    return arr[index];
}

long long maxValue(long long toSearch, long long sz, long long *arr)
{
    long long index,start,last,mid;
    if(toSearch>=arr[sz-1])
        return -1;
    else{
        start=0, last=sz;
        while(start<=last){
            mid=(start+last)/2LL;       //cout<<mid<<"     "<<arr[mid]<<"     "<<arr[mid+1]<<endl;
            if(arr[mid]>toSearch && arr[mid-1]<=toSearch)
                break;
            if(arr[mid]<=toSearch)
                start=mid;
            else if(arr[mid]>toSearch && arr[mid-1]>=toSearch)
                last=mid;
        }
        index=mid;
    }
    return arr[index];
}

int main()
{
    long long sizeOfMainArray,query,i,arr[50505],toSearch,start,end,mid,k1,k2;

    scanf("%lld",&sizeOfMainArray);
    for(i=0; i<sizeOfMainArray; i++)
        scanf(" %lld",&arr[i]);

    arr[sizeOfMainArray]=MAX;     // check whether MAX is long long or int

    scanf("%lld",&query);

    for(i=0; i<query; i++)
    {
        scanf("%lld",&toSearch);
        cout<<"Minimum value :: "<<minValue(toSearch,sizeOfMainArray,arr)<<endl;
        cout<<"Maximum value :: "<<maxValue(toSearch,sizeOfMainArray,arr)<<endl;
    }
    return 0;
}
