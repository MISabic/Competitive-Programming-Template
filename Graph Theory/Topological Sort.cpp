#include <bits/stdc++.h>
using namespace std;

vector<int>graph[100100];

bool dfs(int v, bool visited[], stack<int> &st)
{
    visited[v] = true;
    for(int i=0; i<graph[v].size(); i++)
    {
        if (!visited[graph[v][i]])
            dfs(graph[v][i], visited, st);
    }
    st.push(v);
}

void topologicalSort(int numOfVertices)
{
    stack<int> st;

    bool visited[numOfVertices];
    for(int i=0; i<numOfVertices; i++)
        visited[i]=false;

    for(int i=0; i<numOfVertices; i++)
      if(visited[i]==false)
        dfs(i, visited, st);

    while(st.empty()==false)
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main()
{
    graph[5].push_back(2);
    graph[5].push_back(0);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);

    cout << "Following is a Topological Sort of the given graph \n";
    topologicalSort(6);

    return 0;
}

