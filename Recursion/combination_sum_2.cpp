/*
Link: https://leetcode.com/problems/combination-sum-ii/description/

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void generateCombinations(vector<int>& candidates, int target, int ind, vector<vector<int>>& ans, vector<int>& current) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }
        if (target < 0 || ind >= candidates.size()) return;

        for (int i = ind; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > ind && candidates[i] == candidates[i - 1]) continue;

            current.push_back(candidates[i]);
            generateCombinations(candidates, target - candidates[i], i + 1, ans, current);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> current;
        generateCombinations(candidates, target, 0, ans, current);
        return ans;
    }
};
