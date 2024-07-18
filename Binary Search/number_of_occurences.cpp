/*
Link: https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-occurrence

Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

Example 1:

Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the
given array.
Example 2:

Input:
N = 7, X = 4
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 0
Explanation: 4 is not present in the
given array.
Your Task:
You don't need to read input or print anything.
Your task is to complete the function count() which takes the array of integers arr, n, and x as parameters and returns an integer denoting the answer.
If x is not present in the array (arr) then return 0.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ 106
1 ≤ X ≤ 106
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int index = -1;
	    int low = 0, high = n-1;
	    while(low <= high){
	        int mid = low + (high - low)/2;
	        if(arr[mid] == x){
	            index = mid;
	            break;
	        }
	        if(arr[mid] < x){
	            low = mid + 1;
	        } else {
	            high = mid - 1;
	        }
	    }
	    if(index == -1) return 0;
	    int ans = 1;
	    int leftIndex = index - 1, rightIndex = index + 1;
	    while(leftIndex >= 0 && arr[leftIndex] == x){
	        leftIndex--;
	        ans++;
	    }
	    while(rightIndex < n && arr[rightIndex] == x){
	        rightIndex++;
	        ans++;
	    }
	    return ans;
	}
};