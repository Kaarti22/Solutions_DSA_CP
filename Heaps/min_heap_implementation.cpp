/*
Link: https://www.naukri.com/code360/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=PROBLEM

Implement the Min Heap data structure.

You will be given 2 types of queries:-

0 X
Insert X in the heap.

1
Print the minimum element from the heap and remove it.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 5
1 <= N <= 10^5
1 <= X <= 50

Time Limit: 1 sec
Sample Input 1 :
2
3
0 2
0 1
1
2
0 1
1
Sample Output 1 :
1
1
Explanation Of Sample Input 1 :
For the first test case:-
Insert 2 in the heap and currently, 2 is the smallest element in the heap.
Insert 1 in the heap and now the smallest element is 1.
Return and remove the smallest element which is 1.

For the second test case:-
Insert 1 in the heap and currently, 1 is the smallest element in the heap.
Return the smallest element from the heap which is 1 and remove it.
Sample Input 2 :
2
5
0 5
1
0 43
0 15
0 5
2
0 4
1
Sample Output 2 :
5
4
*/

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    priority_queue<int, vector<int>, greater<int>>pq;
    vector<int>ans;
    for(auto it: q){
        if(it[0] == 0){
            pq.push(it[1]);
        } else {
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    return ans;
}
