#include<bits/stdc++.h>

using namespace std;

struct data{
    int a,b,c;
    string str;
    data(){};
    data(int x,int y,int z,string s){
        a=x,b=y,c=z,str=s;
    }
    bool operator < ( data x ) const {
        if(x.a==a && x.b==b && x.c==c) return str < x.str;
        else if(x.a==a && x.b==b) return c > x.c;
        else if(x.a==a) return b > x.b;
        return a > x.a;
    }
};

int main()
{
    data d[100];
    d[0]=data(5,6,8,"Mash");
    d[1]=data(4,8,9,"Sak");
    d[2]=data(1,10,3,"Mushi");
    d[3]=data(5,8,4,"Naruto");
    d[4]=data(5,8,2,"Sasuke");
    d[5]=data(8,7,9,"Guy");
    d[6]=data(5,8,4,"Sabic");
    sort(d,d+7);
    for(int i=0; i<7; i++){
        cout<<i<<"  ::  "<<d[i].a<<"  "<<d[i].b<<"  "<<d[i].c<<"  "<<d[i].str<<endl;
    }
}
