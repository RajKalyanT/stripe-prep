// https://leetcode.com/problems/evaluate-division/description/

#include <bits/stdc++.h>
using namespace std;

double bfs(string src, string dst, unordered_map<string, vector<pair<double, string>>>& adj){
    if (!adj.count(src) || !adj.count(dst)) return -1.0;
    cout<<src<<dst<<endl;
    if(src==dst) return 1.0;
    queue<pair<double, string>> q;
    unordered_map<string, int> visited;
    for(auto it: adj[src]){
        q.push({ it.first, it.second });
        visited[it.second]=1;
    }
    cout<<q.size()<<endl;
    while(!q.empty()){
        double val=q.front().first;
        string node=q.front().second;
        q.pop();
        if(node==dst){
            return val;
        }
        for(auto it: adj[node]){
            if(visited[it.second]) continue;
            q.push({ val*it.first, it.second });
            visited[it.second]=1;
        }
    }
    return -1;
}
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, vector<pair<double, string>>> adj;
    for(int i=0;i<values.size();i++){
        adj[equations[i][0]].push_back({ values[i], equations[i][1] });
        adj[equations[i][1]].push_back({ 1/values[i], equations[i][0] });
    }
    vector<double> ans;
    for(auto it: queries){
        string src=it[0];
        string dst=it[1];
        ans.push_back(bfs(src, dst, adj));
    }
    return ans;
}

int main(){
    vector<vector<string>> equations = {{"a","b"}, {"b","c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a","c"}, {"b","a"}, {"a","e"}, {"a","a"}, {"x","x"}};
    vector<double> ans=calcEquation(equations, values, queries);
    for(auto it: ans) cout<<it<<" ";
    cout<<endl;
    return 0;
}