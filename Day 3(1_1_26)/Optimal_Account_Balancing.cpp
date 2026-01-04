// https://www.designgurus.io/answers/detail/465-optimal-account-balancing-nsa783

// Definition: We have a list of transactions, where each transaction is represented as a triple [x, y, z] meaning person x gave person y an amount of $z. Our goal is to determine the minimum number of transactions required to settle all debts among these people. In other words, we want to balance the accounts so that everyone’s net debt or credit becomes zero, using the least number of money transfers between individuals.

// Key Points:
// A “settling transaction” means one person pays another person some amount of money to offset their debt. We want to minimize how many such transactions occur.
// Person IDs are not guaranteed to be contiguous or in order (e.g., you might have persons with IDs 0, 2, 6, etc.).
// If no one owes anything net (all accounts are already balanced), the result is 0 because no transactions are needed.

// Constraints:
// 1 <= transactions.length <= 8 – At most 8 transactions are given as input.
// Each transaction is of the form [from, to, amount] with:
// 0 <= from, to < 12 (ID range).
// from != to (no self-transactions).
// 1 <= amount <= 100 (positive amounts only).
// The total number of people involved can be up to 12 (IDs 0 through 11). Due to the small input size, exhaustive or brute-force approaches are feasible.

// Example 1:
// Input: transactions = [[0,1,10], [2,0,5]]
// Output: 2

// Example 2:
// Input: transactions = [[0,1,10], [1,0,1], [1,2,5], [2,0,5]]
// Output: 1

#include<bits/stdc++.h>
using namespace std;

int recursion(vector<int>& positives, vector<int>& negatives){
    if(positives.size()+negatives.size()==0) return 0;
    int cnt=INT_MAX;
    int negative=negatives[0];
    for(int positive: positives){
        vector<int> new_positives=positives;
        vector<int> new_negatives=negatives;
        new_positives.erase(find(new_positives.begin(), new_positives.end(), positive));
        new_negatives.erase(find(new_negatives.begin(), new_negatives.end(), negative));
        if(positive==-negative){
            ;
        }else if(positive>-negative) new_positives.push_back(positive+negative);
        else new_negatives.push_back(positive+negative);
        cnt=min(cnt, recursion(new_positives, new_negatives));
    }
    return cnt+1;
}

int solve(vector<vector<int>>& transactions){
    unordered_map<int, int> mpp;
    for(auto it: transactions){
        mpp[it[0]]-=it[2];
        mpp[it[1]]+=it[2];
    }
    vector<int> positives;
    vector<int> negatives;
    for(auto it: mpp){
        if(it.second>0) positives.push_back(it.second);
        else if(it.second<0) negatives.push_back(it.second);
    }
    int ans=recursion(positives, negatives);
    return ans;
}

int main(){
    int t;
    cin>>t;
    vector<vector<int>> transactions;
    int n;
    while(t--){
        cin>>n;
        vector<int> temp(3, 0);
        for(int i=0;i<n;i++){
            cin>>temp[0]>>temp[1]>>temp[2];
            transactions.push_back(temp);
        }
        int ans=solve(transactions);
        cout<<ans<<endl;
        transactions.clear();
    }
    return 0;
}