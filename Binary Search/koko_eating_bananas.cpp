/*
Link: https://leetcode.com/problems/koko-eating-bananas/description/

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long numberOfHours(vector<int>& piles, int k){
        long long totalNumberOfHours = 0;
        for(auto it: piles){
            totalNumberOfHours += (it * 1ll)/(k * 1ll) + (it % k ? 1 : 0);
        }
        return totalNumberOfHours;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(numberOfHours(piles, mid) <= (h * 1ll)){
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};