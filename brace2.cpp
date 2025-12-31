// Problem statement: You are given a string, s, that represents a pattern for generating words. Each character in the pattern is either:

// A single lowercase letter (which must appear exactly as is)
// A set of alternative characters enclosed in curly braces {} and separated by commas. For example, {a,b} means either ‘a’ or ‘b’ can appear at that position.
// Your task is to return all possible words that can be formed by choosing one option from each position in the string, and return the result in lexicographical (dictionary) order.
#include <bits/stdc++.h>
using namespace std;

bool isValid(string s){
    int n=s.size();
    stack<char> st;
    for(int i=0;i<n;i++){
        if(s[i]=='{'){
            st.push(s[i]);
        }else if(s[i]=='}'){
            if(st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}

vector<string> solve(string s){
    if(!isValid(s)) return { s };
    vector<string> ans;
    string temp="";
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='{'){
            if(temp!=""){
                if(ans.empty()) ans.push_back(temp);
                else{
                    int N=ans.size();
                    for(int j=0;j<N;j++){
                        ans[j]+=temp;
                    }
                }
                temp="";
            }
            i+=1;
            string cur="";
            vector<string> arr;
            while(s[i]!='}'){
                if(s[i]==','){
                    arr.push_back(cur);
                    cur="";
                }else{
                    cur+=s[i];
                }
                i++;
            }
            arr.push_back(cur);
            if(arr.size()<2) return { s };
            cur="";
            if(ans.empty()){
                ans=arr;
                continue;
            }
            vector<string> nw;
            for(auto ar: ans){
                for(auto a: arr){
                    nw.push_back(ar+a);
                }
            }
            ans=nw;
        }else{
            temp+=s[i];
        }
    }
    if(temp!=""){
        if(ans.empty()) ans.push_back(temp);
        else{
            int N=ans.size();
            for(int j=0;j<N;j++){
                ans[j]+=temp;
            }
        }
        temp="";
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    int t;
    cin>>t;
    cin.ignore();
    string s;
    while(t--){
        getline(cin, s);
        vector<string> ans=solve(s);
        for(auto it: ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}