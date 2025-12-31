// https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include<bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n);
    for(auto it: flights){
        adj[it[0]].push_back({ it[1], it[2] });
    }
    vector<int> v(n, INT_MAX);
    queue<pair<int, int>> q;
    q.push({ src, 0 });
    while(!q.empty() && k>=0){
        int N=q.size();
        while(N--){
            int node=q.front().first;
            int dist=q.front().second;
            q.pop();
            for(auto it: adj[node]){
                if(dist+it.second>=v[it.first]) continue;
                q.push({ it.first, dist+it.second });
                v[it.first]=dist+it.second;
            }
        }
        k--;
    }
    return v[dst]==INT_MAX ? -1 : v[dst];
}

int main(){
    int n=4;
    vector<vector<int>> flights = {
        {0,1,100},
        {1,2,100}, 
        {2,0,100},
        {1,3,600},
        {2,3,200}
    };
    int src=0;
    int dst=3;
    int k=1;
    int ans=findCheapestPrice(n, flights, src, dst, k);
    cout<<ans<<endl;
}