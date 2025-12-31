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
    getline(cin, log);
    string s=validateLog(log);
    if(s=="invalid") return -1;
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