#include<bits/stdc++.h>
using namespace std;

int main()
{
    /*vector<int> sm;
    sm.push_back(7);
    sm.push_back(8);
    for(vector<int> :: reverse_iterator i=sm.rbegin(); i<sm.rend(); i++)
        printf("%d\n",*i);*/
    /*string str="naruto uzumaki";
    printf("++%s\n",str.c_str());
    reverse(str.begin(),str.end());
    printf("++%s\n",str.c_str());
    str.erase(2,8);
    printf("++%s\n",str.c_str());*/
    /*list<int> link;
    link.push_back(7);
    link.push_back(8);
    link.push_front(3);
    list<int>::iterator itr = find(link.begin(),link.end(),3);
    link.insert(itr,4);
    for(itr=link.begin(); itr!=link.end(); itr++)
        printf("%d\n",*itr);*/

    tuple<string,int,int,double>tp;
    get<0>(tp) ="MI";
    get<1>(tp) =5;
    get<2>(tp) =152;
    get<3>(tp) =3.99;

    cout<< get<0>(tp) <<"     "<< get<1>(tp) <<"     "<< get<2>(tp) <<"     "<< get<3>(tp) << endl;

    tp=make_tuple("Flame",7,155,4.00);

    cout<< get<0>(tp) <<"     "<< get<1>(tp) <<"     "<< get<2>(tp) <<"     "<< get<3>(tp) << endl;

    string a;
    int b,c;
    double d;
    tie(a,b,c,d)=(tp);      //assign the values

    cout<<a<<"     "<<b<<"     "<<c<<"     "<<d<<endl;

    int k=844;
    cout << setfill('0') << setw(8) << hex << k << endl;
    return 0;
}

