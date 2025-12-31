#include<bits/stdc++.h>
using namespace std;

int minPenalty(string s){
    int n=s.size();
    int pre=0;
    for(char ch: s){
        if(ch=='Y') pre++;
    }
    int ans=pre;
    int time=0;
    for(int i=0;i<n;i++){
        if(s[i]=='Y') pre--;
        else pre++;
        if(pre<ans){
            ans=pre;
            time=i+1;
        }
    }
    return time;
}

vector<int> solve(){
    string log;
    getline(cin, log);
    stringstream ss(log);
    string temp;
    string cur="";
    vector<int> ans;
    while(ss>>temp){
        if(temp=="END"){
            ans.push_back(minPenalty(cur));
            cur="";
        }else if(temp!="BEGIN"){
            cur+=temp;
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        vector<int> ans=solve();
        for(auto it: ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}