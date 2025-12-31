// https://leetcode.com/problems/merge-intervals/description/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(auto it: intervals){
        pq.push({ it[0], it[1] });
    }
    while(!pq.empty()){
        int x1=pq.top().first;
        int y1=pq.top().second;
        pq.pop();
        if(pq.empty()){
            ans.push_back({ x1, y1 });
            break;
        }
        int x2=pq.top().first;
        int y2=pq.top().second;
        if(y1>=x2){
            pq.pop();
            pq.push({ min(x1, x2), max(y1, y2) });
        }else{
            ans.push_back({ x1, y1 });
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    vector<vector<int>> intervals;
    int n;
    int tmp1, tmp2;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>tmp1>>tmp2;
            intervals.push_back({ tmp1, tmp2 });
        }
        vector<vector<int>> ans=merge(intervals);
        for(auto it: ans){
            cout<<"["<<it[0]<<" "<<it[1]<<"] ";
        }
        cout<<endl;
        intervals.clear();
    }
}