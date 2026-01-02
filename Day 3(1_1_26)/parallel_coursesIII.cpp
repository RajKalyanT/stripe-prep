// You are given an integer n, which indicates that there are n courses labeled
// from 1 to n. You are also given a 2D integer array relations where
// relations[j] = [prevCoursej, nextCoursej] denotes that course prevCoursej has
// to be completed before course nextCoursej (prerequisite relationship).
// Furthermore, you are given a 0-indexed integer array time where time[i]
// denotes how many months it takes to complete the (i+1)th course.

// You must find the minimum number of months needed to complete all the courses
// following these rules:

// You may start taking a course at any time if the prerequisites are met.
// Any number of courses can be taken at the same time.
// Return the minimum number of months needed to complete all the courses.

// Note: The test cases are generated such that it is possible to complete every
// course (i.e., the graph is a directed acyclic graph).

// Input: n = 3, relations = [[1,3],[2,3]], time = [3,2,5]
// Output: 8

// Input: n = 5, relations = [[1,5],[2,5],[3,5],[3,4],[4,5]], time = [1,2,3,4,5]
// Output: 12

// https://leetcode.com/problems/parallel-courses-iii/description/

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<vector<int>> &relations, vector<int> &time) {
  vector<vector<int>> adj(n + 1);
  for (auto it : relations) {
    adj[it[0]].push_back(it[1]);
  }
  vector<int> indegree(n + 1, 0);
  vector<int> dist(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    for (auto it : adj[i])
      indegree[it]++;
    dist[i] = time[i - 1];
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (indegree[i] == 0)
      q.push(i);
  }
  int ans = INT_MIN;
  while (!q.empty()) {
    int N = q.size();
    for (int i = 0; i < N; i++) {
      int node = q.front();
      q.pop();
      ans = max(ans, dist[node]);
      for (auto it : adj[node]) {
        dist[it] = max(dist[it], dist[node] + time[it - 1]);
        indegree[it]--;
        if (indegree[it] == 0)
          q.push(it);
      }
    }
  }
  return ans;
}

int main() {
  // Test case 1
  int n1 = 3;
  vector<vector<int>> relations1 = {{1, 3}, {2, 3}};
  vector<int> time1 = {3, 2, 5};
  int ans1 = solve(n1, relations1, time1);
  cout << ans1 << endl;

  // Test case 2
  int n2 = 5;
  vector<vector<int>> relations2 = {{1, 5}, {2, 5}, {3, 5}, {3, 4}, {4, 5}};
  vector<int> time2 = {1, 2, 3, 4, 5};
  int ans2 = solve(n2, relations2, time2);
  cout << ans2 << endl;

  return 0;
} 