#include<stdio.h>
#include<stdlib.h>

/*int binarySearch1(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;

        // If the element is present at the middle itself
        if (arr[mid] == x)  return mid;

        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);

        // Else the element can only be present in right subarray
        return binarySearch(arr, mid+1, r, x);
   }

   // We reach here when element is not present in array
   return -1;
}

// initially called with low = 0, high = N – 1
int binarySearch2(A[], value, low, high)
{
  // invariants: value >= A[i] for all i < low
    value < A[i] for all i > high
    if (high < low)
        return low
    mid = low +((high – low) / 2) // THIS IS AN IMPORTANT STEP TO AVOID BUGS
    if (A[mid] > value)
        return BinarySearch_Right(A, value, low, mid-1)
    else
        return BinarySearch_Right(A, value, mid+1, high)
}

int binarySearch3(A[], value)
{
    low = 0
    high = N - 1
    while (low <= high)
    {
        // invariants: value >= A[i] for all i < low
        value < A[i] for all i > high
        mid = low +((high – low) / 2) // THIS IS AN IMPORTANT STEP TO AVOID BUGS
        if (A[mid] > value)
            high = mid - 1
        else
            low = mid + 1
    }
    return low
}

int binarySearch4(int key)
{
    int start = 0;
    int end = max;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (n == a[mid])
            return mid;
        else if (n < a[mid])
            end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}*/

int search(int x[], int n, int k)
{
    int a,p = 0;
    for (a = n; a >= 1; a /= 2)
    {
        while (p+a < n && x[p+a] <= k){
            printf("%d %d %d\n",p,a,x[p+a]);
            p += a;
        }
    }
    return p+1;
}

int main()
{
    int arr[100],n,i,num,start,end;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    while(scanf("%d",&num)==1)
    //start=0,end=n-1;
    //binarySearch(arr,n,num,start,end);
    printf("%d\n",search(arr, n, num));

}



/*

#include<stdio.h>

int main()
{
    long long int n,x,start=1,end,mid,count;
    while(scanf("%lld %lld",&n,&x)==2)
    {
        count=0, start=1, end = n;
        while (count!=7)
        {
            ++count;
            if(start==1) mid=(start+end)/2;
            else{
                mid=(end-start+1)/2;
                start+=mid;
            }
            printf("%lld %lld %lld\n",start,end,mid);
            if(x<mid)
                end=mid;
            else if(x>mid)
                start=mid;
            else
                break;
        }
        printf("%lld\n",count);
    }
    return 0;
}

*/
