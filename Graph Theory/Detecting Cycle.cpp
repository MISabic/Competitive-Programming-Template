#include <bits/stdc++.h>
using namespace std;

enum Color{WHITE, GRAY, BLACK};

vector<int>graph[100100];

bool dfs(int u,int color[])
{
    color[u]=GRAY;
    for(int i=0; i<graph[u].size(); i++)
    {
        int v=graph[u][i];

        if(color[v]==GRAY)
            return true;

        if(color[v]==WHITE && dfs(v,color))
            return true;
    }

    color[u]=BLACK;

    return false;
}

bool isCyclic(int numOfVertices)
{
    int color[numOfVertices+10];
    for(int i=0; i<numOfVertices; i++)
        color[i]=WHITE;

    for(int i=0; i<numOfVertices; i++)
        if(color[i]==WHITE)
            if(dfs(i,color)==true)
                return true;

    return false;
}

int main()
{
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(3);

    if(isCyclic(4))
        cout<<"Graph contains cycle"<<endl;
    else
        cout<<"Graph doesn't contain cycle"<<endl;

    graph[2].push_back(0);

    if(isCyclic(4))
        cout<<"Graph contains cycle"<<endl;
    else
        cout<<"Graph doesn't contain cycle"<<endl;

    return 0;
}
