/*
Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

 

Example 1:


Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
Example 2:

Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.
 

Constraints:

1 <= n <= 200
n - 1 <= roads.length <= n * (n - 1) / 2
roads[i].length == 3
0 <= ui, vi <= n - 1
1 <= timei <= 109
ui != vi
There is at most one road connecting any two intersections.
You can reach any intersection from any other intersection.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        vector<pair<int, int>> adj[n];
        for(auto it: roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> distance(n, 1e18), ways(n, 0);
        distance[0] = 0 * 1ll;
        ways[0] = 1 * 1ll;
        pq.push({0 * 1ll, 0});
        while (!pq.empty()) {
            long long currDistance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;
                if (currDistance + (edgeWeight * 1ll) < distance[adjNode]) {
                    distance[adjNode] = currDistance + (edgeWeight * 1ll);
                    ways[adjNode] = ways[node];
                    pq.push({distance[adjNode], adjNode});
                } else if (currDistance + (edgeWeight * 1ll) == distance[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};
