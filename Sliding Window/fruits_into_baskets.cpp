/*
Link: https://leetcode.com/problems/fruit-into-baskets/description/

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

 

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
 

Constraints:

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0, n = fruits.size();
        int one = fruits[0], two = -1, recent = fruits[0];
        int oneCount = 1, twoCount = 0;
        for(int i=1; i<n; i++){
            if(fruits[i] == one){
                recent = one;
                oneCount++;
            } else if(two == -1){
                two = fruits[i];
                recent = two;
                twoCount++;
            } else if(fruits[i] == two){
                recent = two;
                twoCount++;
            } else {
                ans = max(ans, oneCount + twoCount);
                if(recent == two){
                    oneCount = 0;
                    for(int j=i-1; j>=0; j--){
                        if(fruits[j] == two){
                            oneCount++;
                        } else {
                            break;
                        }
                    }
                    one = two;
                    twoCount = 1;
                    two = fruits[i];
                    recent = two; 
                } else {
                    oneCount = 0;
                    for(int j=i-1; j>=0; j--){
                        if(fruits[j] == one){
                            oneCount++;
                        } else {
                            break;
                        }
                    }
                    two = fruits[i];
                    twoCount = 1;
                    recent = two;
                }
            }
        }
        return max(ans, oneCount + twoCount);
    }
};