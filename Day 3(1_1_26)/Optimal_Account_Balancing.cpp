// https://www.designgurus.io/answers/detail/465-optimal-account-balancing-nsa783

#include<bits/stdc++.h>
using namespace std;

void bfs(int parent, unordered_map<int, vector<pair<int, int>>>& adj, unordered_map<int, int>& loan){
    queue<pair<pair<int, int>, pair<int, vector<int>>>> q;
    unordered_map<int, int> visited;
    visited[parent]=1;
    for(auto it: adj[parent]){
        if(loan[]!=0){
            q.push({ { parent, it.first }, { it.second, { parent, it.first } } });
            visited[it.first]=1;
        }
    }
    while(!q.empty()){
        int p=q.front().first.first;
        int node=q.front().first.second;
        int weight=q.front().second.first;
        vector<int> path=q.front().second.second;
        q.pop();
        if(parent==node){
            for(auto it: path){
                
            } 
        }
    }
}

int solve(vector<vector<int>>& transactions){
    unordered_map<int, vector<pair<int, int>>> adj;
    unordered_map<int, int> loan;
    for(auto it: transactions){
        adj[it[0]].push_back({ it[1], it[2] });
        adj[it[0]]+=it[2];
    }
    
}

int main(){
    // Test case 1
    vector<vector<int>> transactions1 = {
        {0, 1, 10},
        {2, 0, 5}
    };

    // Test case 2
    vector<vector<int>> transactions2 = {
        {0, 1, 10},
        {1, 0, 1},
        {1, 2, 5},
        {2, 0, 5}
    };

}