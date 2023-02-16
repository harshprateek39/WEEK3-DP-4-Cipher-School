#include<bits/stdc++.h>
using namespace std;
vector<int> bfs(vector<vector<int>> &graph, int src)
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
    queue<int> q;
    q.push(src);
visited[src] = true;

while(!q.empty()){
int node = q.front();
q.pop();
ans.push_back(node);
for(auto it : adj[node]){
if(!visited[it]){
    visited[it] = true;
    q.push(it);
    
}

}
}

}


int main() {
    vector<vector<int>> graph = {
        {0 ,0,1,1,0},
        {1,0,0,1,0},
        {0 , 0 ,1,0,1},
        {1,0,0,1,0},
        {0 ,0 , 0 ,1,0}

    };

    vector<int>ans = bfs(graph, 0);

for(auto it : ans){
cout<<it<<" ";
}

    
}