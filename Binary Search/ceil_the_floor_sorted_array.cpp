/*
Link: https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401?leftPanelTabValue=PROBLEM

You're given a sorted array 'a' of 'n' integers and an integer 'x'.



Find the floor and ceiling of 'x' in 'a[0..n-1]'.



Note:
Floor of 'x' is the largest element in the array which is smaller than or equal to 'x'.
Ceiling of 'x' is the smallest element in the array greater than or equal to 'x'.


Example:
Input: 
n=6, x=5, a=[3, 4, 7, 8, 8, 10]   

Output:
4

Explanation:
The floor and ceiling of 'x' = 5 are 4 and 7, respectively.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
6 8
3 4 4 7 8 10


Sample Output 1 :
8 8


Explanation of sample input 1 :
Since x = 8 is present in the array, it will be both floor and ceiling.


Sample Input 2 :
6 2
3 4 4 7 8 10


Sample Output 2 :
-1 3


Explanation of sample input 2 :
Since no number is less than or equal to x = 2 in the array, its floor does not exist. The ceiling will be 3.


Constraints :
1 <= n <= 2 * 10^5      
1 <= a[i] <= 10^9
Time limit: 1 sec

*/

#include <bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int low = 0, high = n-1;
	while(low < high){
		int mid = low + (high - low)/2;
		if(a[mid] < x){
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	if(a[low] == x || a[high] == x) return {x, x};
	if(a[low] > x){
		if(low > 0) return {a[low-1], a[low]};
		return {-1, a[low]};
	}
	if(a[high] < x){
		if(high < n-1) return {a[high], a[high+1]};
		return {a[high], -1};
	}
	return {a[low], a[high]};
}