#include<bits/stdc++.h>
#define sz 100
using namespace std;

int arr[sz];
int tree[sz*3];

int build_tree(int root, int left, int right)
{
    if(left==right) return tree[root]=arr[left];

    int child=root<<1;
    int mid=(left+right)>>1;

    build_tree(child,left,mid); // left child
    build_tree(child+1,mid+1,right); // right child

    tree[root]=tree[child]+tree[child+1];
}

int update_tree(int root, int left, int right, int index, int update_value)
{
    if(index>right || index<left) return 0;
    if(left>=index && index<=right) return tree[root]=update_value;

    int child=root<<1;
    int mid=(left+right)>>1;

    update_tree(child,left,mid,index,update_value); // left child
    update_tree(child+1,mid+1,right,index,update_value); // right child

    tree[root]=tree[child]+tree[child+1];
}

int query(int root, int left, int right, int query_left, int query_right)
{
    if(query_left>right || query_right<left) return 0;
    if(query_left<=left && right<=query_right) return tree[root];

    int child=root<<1;
    int mid=(left+right)>>1;

    int res1=query(child,left,mid,query_left,query_right); // left child
    int res2=query(child+1,mid+1,right,query_left,query_right); // right child

    return res1+res2;
}

int main()
{
    for(int i=1; i<=8; i++){
        cin>>arr[i];
    }
    build_tree(1,1,8);
    for(int i=1; i<=16; i++){
        cout<<i<<"  :: "<<tree[i]<<endl;
    }
    update_tree(1,1,8,4,5);
    for(int i=1; i<=16; i++){
        cout<<i<<"  :: "<<tree[i]<<endl;
    }
    cout<<query(1,1,8,2,3)<<endl;;
    return 0;
}

// 4 3 5 -1 8 2 6 1
