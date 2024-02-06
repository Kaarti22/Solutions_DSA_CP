/*

Link: https://www.codingninjas.com/studio/problems/linear-search_6922070?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Problem statement
You are given an array ‘arr’ containing ‘n’ integers. You are also given an integer ‘num’, and your task is to find whether ‘num’ is present in the array or not.



If ‘num’ is present in the array, return the 0-based index of the first occurrence of ‘num’. Else, return -1.



Example:
Input: ‘n’ = 5, ‘num’ = 4 
'arr' =  [6,7,8,4,1] 

Output: 3

Explanation:
4 is present at the 3rd index.
*/

#include <bits/stdc++.h> 
using namespace std;

int linearSearch(int n, int num, vector<int> &arr)
{
    int ind = -1;
    for(int i=0; i<n; i++){
        if(arr[i] == num){
            ind = i;
            break;
        }
    }
    return ind;
}
