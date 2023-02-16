#include<bits/stdc++.h>
using namespace std;

void dfsrec(vector<int> adj[], int v, vector<bool> &vis, vector<int>&ans){
    vis[v] = true;

    for(auto it : adj[v]){
        if(!vis[it]){
vis[it] = true;
dfsrec(adj, it, vis, ans);

        }

    }

    ans.push_back(v);


}
vector<int> dfs(vector<vector<int>> &graph, int src)
{
    int n = graph.size();
    int m = graph[0].size();
    vector<int>ans;
    vector<int>adj[n];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(graph[i][j] == 1){
                adj[i].push_back(j);

            }

        }
    }

    vector<bool>visited(n, false);
    dfsrec(adj , src, visited, ans);


}


int main() {
    vector<vector<int>> graph = {
        {0 ,0,1,1,0},
        {1,0,0,1,0},
        {0 , 0 ,1,0,1},
        {1,0,0,1,0},
        {0 ,0 , 0 ,1,0}

    };

    vector<int>ans = dfs(graph, 0);

for(auto it : ans){
cout<<it<<" ";
}

    
}