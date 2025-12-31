// https://leetcode.com/problems/top-k-frequent-elements/description/

#include<bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mpp;
    for(auto it: nums){
        mpp[it]++;
    }
    priority_queue<pair<int, int>,vector<pair<int,int>>, greater<>> pq;
    for(auto it: mpp){
        pq.push({ it.second, it.first });
        if(pq.size()>k) pq.pop();
    }
    vector<int> ans;
    while(k--){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    vector<int> nums;
    int n;
    int k;
    while(t--){
        cin>>n;
        nums.resize(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        cin>>k;
        vector<int> ans=topKFrequent(nums, k);
        for(auto it: ans) cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}