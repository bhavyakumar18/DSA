#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void DFS(int node,vector<int> adj[],vector<bool>& visited)
{
    visited[node]=true;
    cout<<node<<" ";

    for(int i=0;i<adj[node].size();i++)
    {
        int next=adj[node][i];

        if(!visited[next])
            DFS(next,adj,visited);
    }
}

void BFS(int start,vector<int> adj[],int n)
{
    vector<bool> visited(n,false);
    queue<int> q;

    visited[start]=true;
    q.push(start);

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        cout<<node<<" ";

        for(int i=0;i<adj[node].size();i++)
        {
            int next=adj[node][i];

            if(!visited[next])
            {
                visited[next]=true;
                q.push(next);
            }
        }
    }
}

int main()
{
    int n,e,u,v,start;

    cout<<"Enter number of buildings: ";
    cin>>n;

    vector<int> adj[n];

    cout<<"Enter number of roads: ";
    cin>>e;

    for(int i=0;i<e;i++)
    {
        cout<<"Enter two connected buildings: ";
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<"Enter starting building: ";
    cin>>start;

    vector<bool> visited(n,false);

    cout<<"DFS Traversal: ";
    DFS(start,adj,visited);

    cout<<"\nBFS Traversal: ";
    BFS(start,adj,n);

    cout<<endl;

    return 0;
}
