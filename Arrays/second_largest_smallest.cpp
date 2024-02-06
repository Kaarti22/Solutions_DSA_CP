/*
Problem statement
You have been given an array ‘a’ of ‘n’ unique non-negative integers.



Find the second largest and second smallest element from the array.



Return the two elements (second largest and second smallest) as another array of size 2.



Example :
Input: ‘n’ = 5, ‘a’ = [1, 2, 3, 4, 5]
Output: [4, 2]

The second largest element after 5 is 4, and the second smallest element after 1 is 2.
*/

#include <bits/stdc++.h> 
using namespace std;

vector<int> getSecondOrderElements(int n, vector<int> a) {
    int maxi = a[0], mini = a[0];
    for(int i=1; i<n; i++){
        maxi = max(a[i], maxi);
        mini = min(a[i], mini);
    }
    int s1 = INT_MIN, s2 = INT_MAX;
    for(int i=0; i<n; i++){
        if(a[i] != maxi && a[i] > s1){
            s1 = a[i];
        }
        if(a[i] != mini && a[i] < s2){
            s2 = a[i];
        }
    }
    return {s1,s2};
}