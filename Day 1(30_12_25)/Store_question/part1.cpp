// Customer log: "Y Y N Y" //represents if customer come to store every hour, Y means come, N means no.
// Closing Time: Store is closed at a given hour
// So need to compute the penalty by the rule:

// if customers dont come (N) when the store is open: +1
// if customers come (Y) when the store is close: +1
// int compute_penalty(String log, int closing_time);

#include<bits/stdc++.h>
using namespace std;

string validateLog(string log){
    string s="";
    for(char ch: log){
        if(ch!=' ') s+=toupper(ch);
    }
    for(char ch: s){
        if(ch!='Y' && ch!='N'){
            return "invalid";
        }
    }
    return s;
}

int solve(){
    string log;
    int close_time;
    getline(cin, log);
    cin>>close_time;
    cin.ignore();
    string s=validateLog(log);
    if(s=="invalid") return -1;
    int n=s.size();
    int ans=0;
    if(close_time>=n){
        return -1;
    }
    for(int i=0;i<close_time;i++){
        if(s[i]=='N') ans++;
    }
    for(int i=close_time;i<n;i++){
        if(s[i]=='Y') ans++;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        int ans=solve();
        cout<<ans<<endl;
    }
    return 0;
}