#include<bits/stdc++.h>
#define sz 100
using namespace std;

int arr[sz];
struct segment_tree{
    int propagate=0,data=0;
} tree[sz*3];

int build_tree(int root, int left, int right)
{
    if(left==right) return tree[root].data=arr[left];

    int child=root<<1;
    int mid=(left+right)>>1;

    build_tree(child,left,mid);
    build_tree(child+1,mid+1,right);

    tree[root].data=tree[child].data+tree[child+1].data;
}

void update_tree(int root, int left, int right, int update_left, int update_right, int update_value)
{
    if(update_left>right || update_right<left) return ;
    if(update_left<=left && right<=update_right){
        tree[root].data+=(right-left+1)*update_value;
        tree[root].propagate+=update_value;
        return ;
    }

    int child=root<<1;
    int mid=(left+right)>>1;

    update_tree(child,left,mid,update_left,update_right,update_value);
    update_tree(child+1,mid+1,right,update_left,update_right,update_value);

    tree[root].data=tree[child].data+tree[child+1].data+(right-left+1)*tree[root].propagate;
}

int query(int root, int left, int right, int query_left, int query_right, int carry=0)
{
    if(query_left>right || query_right<left) return 0;
    if(query_left<=left && right<=query_right) return tree[root].data+carry*(right-left+1);

    int child=root<<1;
    int mid=(left+right)>>1;

    int res1=query(child,left,mid,query_left,query_right,carry+tree[root].propagate);
    int res2=query(child+1,mid+1,right,query_left,query_right,carry+tree[root].propagate);

    return res1+res2;
}

int main()
{
    for(int i=1; i<=8; i++){
        cin>>arr[i];
    }
    build_tree(1,1,8);
    for(int i=1; i<=16; i++){
        cout<<i<<"  :: "<<tree[i].data<<endl;
    }
    update_tree(1,1,8,3,5,6);
    for(int i=1; i<=16; i++){
        cout<<i<<"  :: "<<tree[i].data<<endl;
    }
    cout<<query(1,1,8,2,4)<<endl;;
    return 0;
}

// 4 3 5 -1 8 2 6 1
