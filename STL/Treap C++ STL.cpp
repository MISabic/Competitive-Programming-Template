/*#include <bits/stdc++.h>
using namespace std;

/// Importing policy_based_data_structure:

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

/// Importing ends here.

/// struct for declaring struct type pb_ds:

struct vals{
    int num;
    int typ;
    vals(int a,int b){
        num = a;
        typ = b;
    }
    bool operator <(const vals& other) const {
		return num > other.num; /// num is the value on what basis it'll be sorted.
	}
};

/// typedef original name to pb_ds for simplicity:
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pb_ds;
/// struct type pb_ds:
typedef tree <vals, null_type, less<vals>, rb_tree_tag, tree_order_statistics_node_update> pb_ds_st;

int main(){
    /// Declaring a pb_ds(policy based ds):
    pb_ds treap;

    treap.insert(2);
    treap.insert(8);
    treap.insert(5);
    treap.insert(3);
    /// Return number of elements smaller than k:
    cout << treap.order_of_key(4) << endl << endl; // 2

    /// Clear the treap:
    treap.clear();

    treap.insert(1);
    treap.insert(2);
    treap.insert(4);
    treap.insert(8);
    treap.insert(8);
    treap.insert(16);

    cout << treap.order_of_key(17) << endl << endl;

    /// Return pointer to the k'th smallest number(0-based indexed):
    //cout << *treap.find_by_order(1) << endl; // 2

    treap.erase(8);

    cout << *treap.find_by_order(0) << endl; // 8; now the array is :: 1 2 8 16
    cout << *treap.find_by_order(1) << endl; // 8; now the array is :: 1 2 8 16
    cout << *treap.find_by_order(2) << endl; // 8; now the array is :: 1 2 8 16
    cout << *treap.find_by_order(3) << endl; // 8; now the array is :: 1 2 8 16
    cout << *treap.find_by_order(4) << endl << endl; // 0; nothing at 4th index

    cout << treap.order_of_key(-5) << endl;  // 0
    cout << treap.order_of_key(11) << endl;  // 4
    cout << treap.order_of_key(50) << endl;  // 5

    /// If we want to get map but not the set, as the second argument type must be used mapped type.

    /// Tree supports all the operations of set including two new features:

    /// 1. find_by_order(k) :
    /// Returns an iterator to the k-th largest element (counting from zero).

    /// 2. order_of_key(k) :
    /// Returns the number of items in a set that are strictly smaller than k.



    /// The use of struct type policy based ds:

    pb_ds_st treap_st;

    treap_st.insert(vals(1,1));
    treap_st.insert(vals(40,2));
    treap_st.insert(vals(70,3));
    treap_st.insert(vals(15,4));
    treap_st.insert(vals(27,5));
    treap_st.insert(vals(45,6));

    pb_ds_st::iterator it;

    for(it = treap_st.begin();it!=treap_st.end();it++){
        vals v = *it;
        cout << v.num << " " << v.typ << endl;
    }
    return 0;
}*/



#include <bits/stdc++.h>
using namespace std;

struct node {
    node *ch[2];
    int r,v,s;
    node(int v):v(v) {
        s = 1;
        r = rand();
        ch[0] = ch[1] = NULL;
    }
    bool operator <(const node &rhs) const {
        return r<rhs.r;
    }
    int cmp(int x) {
        if(x == v) return -1;
        return x<v ? 0:1;
    }
    void maintain() {
        s = 1;
        if(ch[0] != NULL) s += ch[0]->s;
        if(ch[1] != NULL) s += ch[1]->s;
    }
};

struct Treap {
    inline void rotate(node * &o,int d) {
        node *k = o->ch[d^1];
        o->ch[d^1] = k->ch[d];
        k->ch[d] = o;
        o->maintain();
        k->maintain();
        o = k;
    }

    inline void insert(node * &o,int x) {
        if(o == NULL) o = new node(x);
        else{
            int d = (x<o->v ? 0:1);
            insert(o->ch[d],x);
            if(o->ch[d]->r>o->r) rotate(o,d^1);
        }
        o->maintain();
    }

    inline void remove(node * &o,int x) {
        int d = o->cmp(x);
        if(d == -1) {
            node *u = o;
            if(o->ch[0] != NULL && o->ch[1] != NULL) {
                int d2 = (o->ch[0]->r>o->ch[1]->r? 1:0);
                rotate(o,d2);
                remove(o->ch[d2],x);
            } else {
                if(o->ch[0] == NULL) o = o->ch[1];
                else o = o->ch[0];
                delete u;
            }
        }
        else {
            remove(o->ch[d],x);
        }
        if(o != NULL) o->maintain();
    }

    inline int kth(node * o,int k) {
        if(o == NULL || k <= 0 || k>o->s) return 0;
        int s = (o->ch[0] == NULL ? 0: o->ch[0]->s);
        if(k == s+1) return o->v;
        else if(k <= s) return kth(o->ch[0],k);
        else return kth(o->ch[1],k-s-1);
    }
}treap;

/// While using treap, always remember to use root in the function parameter.

int main () {
    int A[] = {2,4,7,1,2,22,5,15,5,2};

	node *root = NULL;
    for(int i = 0;i<10;i++){
        treap.insert(root,A[i]);
    }

    /// treap.remove(root,2); /// remove only one occurrence of 2

    for(int i = 1;i<=10;i++){
        /// Find the i'th element in sorted order(1 based index)
        int kth = treap.kth(root,i);
        printf("%d'th num = %d\n",i,kth);
    }
    return 0;
}

