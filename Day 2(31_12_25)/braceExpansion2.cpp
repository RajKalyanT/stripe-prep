// https://leetcode.com/problems/brace-expansion-ii/description/

#include<bits/stdc++.h>
using namespace std;

vector < string > mul(vector < string > a, vector < string > b) {
    if (a.empty()) return b;
    if (b.empty()) return a;
    vector < string > ans;
    for (auto it1: a) {
        for (auto it2: b) {
            ans.push_back(it1 + it2);
        }
    }
    return ans;
}

vector < string > solve(string s) {
    vector < string > res;
    vector < string > cur;
    stack < vector < string >> stk;
    for (char ch: s) {
        if (ch >= 'a' && ch <= 'z') {
            if (!cur.empty()) {
                for (auto & it: cur) it += ch;
            } else cur.push_back(string(1, ch));
        }
        else if (ch == '{') {
            stk.push(res);
            stk.push(cur);
            cur.clear();
            res.clear();
        }
        else if (ch == '}') {
            vector < string > precur = stk.top();
            stk.pop();
            vector < string > preres = stk.top();
            stk.pop();
            for (auto it: cur) res.push_back(it);
            cur = mul(precur, res);
            res = preres;
        }
        else if (ch == ',') {
            for (auto it: cur) res.push_back(it);
            cur.clear();
        }
    }
    for (auto it: cur) res.push_back(it);
    sort(res.begin(), res.end());
    return vector < string > (res.begin(), unique(res.begin(), res.end()));
}

int main() {
    int t;
    cin >> t;
    string s;
    while (t--) {
        cin >> s;
        vector < string > ans = solve(s);
        for (auto it: ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}