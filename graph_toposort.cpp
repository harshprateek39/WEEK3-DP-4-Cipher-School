	#include<bits/stdc++.h>
    using namespace std;
	void dfs(vector<int>adj[] , int s , vector<bool>&vis , stack<int>&st) {
	    vis[s] = true;
	    for(auto it : adj[s]){
	        if(vis[it] == false){
	            dfs(adj , it , vis , st);
	            st.push(it);
	        }
	    }
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	   // vector<int>ans;
	   // queue<int>q;
	   
	   //Here below wee are calculating the inorder deg of the vertices
	   
	   // vector<int>ind(v , 0);
	   // for(int u = 0; u < v ; u++) {
	   //     for(auto ver : adj[u]) {
	   //         ind[ver]++;
	   //     }
	   // }
	    
	    //Then we the pushing the vetices with indegree 0
	    
	   // for(int i = 0 ; i<v ; i++){
	   //     if(ind[i] == 0){
	   //         q.push(i);
	   //     }
	   // }
	    
	   // while(!q.empty()) {
	   //     int curr = q.front();
	   //     q.pop();
	        
	   //     for(auto ver : adj[curr]){
	   //         ind[ver]--;
	   //         if(ind[ver] == 0){
	   //             q.push(ver);
	   //         }
	   //     }
	        
	   //     ans.push_back(curr);
	   // }
	   // return ans;
	   
	   
	   //Toplogical short using dfs
	   
	   vector<bool>vis(v , false);
	   vector<int>ans;
	   stack<int>st;
	   for(int i = 0 ; i<v;i++) {
	       if(vis[i] == false){
	           dfs(adj , i , vis , st);
	           st.push(i);
	       }
	   }
	   
	   while(!st.empty()){
	       ans.push_back(st.top());
	       st.pop();
	   }
	   
	   return ans;
	}

    int main(){

    }