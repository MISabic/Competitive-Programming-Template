// Recursion Sample #1

#include<bits/stdc++.h>
using namespace std;

int visited[30],c=0;
vector<char>vec;
vector<int>order[35];
string fline,sline,str,res;

// to check if any variable that is connected with 'n' is already visited which is supposed to come after 'n'
bool is_taken(int n)
{
    for(int i=0; i<order[n].size(); i++){
        if(visited[order[n][i]])
            return false;
    }
    return true;
}

void backtrack(int pos)
{
    if(vec.size()==str.length()){
        for(int i=0; i<vec.size(); i++) cout<<vec[i];
        cout<<'\n';
        return ;
    }
    for(int i=0; i<str.length(); i++){
        if((str[i]-'a')!=pos && visited[str[i]-'a']==0 && is_taken(str[i]-'a')){

            visited[str[i]-'a']=1;
            vec.push_back(str[i]);
            backtrack(str[i]-'a');
            vec.pop_back();
            visited[str[i]-'a']=0;

        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(getline(cin,fline)){
        if(c) cout<<'\n';
        else c=1;

        /** reset */
        vec.clear();
        for(int i=0; i<30; i++) order[i].clear();
        memset(visited,0,sizeof(visited));
        /** end */

        str="";
        for(int i=0; i<fline.length(); i+=2)
            str+=fline[i];

        sort(str.begin(),str.end());

        getline(cin,sline);
        for(int i=0; i<sline.length(); i+=4){
            order[sline[i]-'a'].push_back(sline[i+2]-'a');
        }

        for(int i=0; i<str.length(); i++){
            memset(visited,0,sizeof(visited));
            visited[str[i]-'a']=1;
            vec.clear();
            vec.push_back(str[i]);
            backtrack(str[i]-'a');
            visited[str[i]-'a']=0;
        }
    }
    return 0;
}


//Recursion Sample #2

/*
#include<iostream>
#include<cstring>
#include<algorithm>
#include<functional>
using namespace std;

int n,totalSticks,length,arr[100],visited[100];

bool dfs(int index,int now,int cnt)
{
    if(cnt*length==totalSticks)
        return true;

    for(int i=index; i<n; i++){
        if(visited[i] || (i && !visited[i-1] && arr[i]==arr[i-1])) continue;
        if(now+arr[i]==length){
            visited[i]=1;
            if(dfs(0,0,cnt+1)) return true;
            visited[i]=0;
            return false;
        }
        else if(now+arr[i]<length){
            visited[i]=1;
            if(dfs(i+1,now+arr[i],cnt)) return true;
            visited[i]=0;
            if(now==0) return false;
        }
    }
    return false;
}

int main()
{
    while(cin>>n && n){
        totalSticks=0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            totalSticks+=arr[i];
        }
        sort(arr,arr+n,greater<int>());
        for(length=arr[0]; length<=totalSticks; length++){
            if(totalSticks%length==0){
                memset(visited,0,sizeof(visited));
                if(dfs(0,0,0)){
                    cout<<length<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
*/

