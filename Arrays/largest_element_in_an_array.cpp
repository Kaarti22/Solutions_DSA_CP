/*

Link: https://www.codingninjas.com/codestudio/problems/largest-element-in-the-array-largest-element-in-the-array_5026279?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

Problem statement
Given an array ‘arr’ of size ‘n’ find the largest element in the array.

Example:

Input: 'n' = 5, 'arr' = [1, 2, 3, 4, 5]

Output: 5

Explanation: From the array {1, 2, 3, 4, 5}, the largest element is 5.
*/

#include <bits/stdc++.h> 
using namespace std;

int largestElement(vector<int> &arr, int n) {
    int maxi = arr[0];
    for(int i=1; i<n; i++){
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}