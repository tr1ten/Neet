#include <bits/stdc++.h>

using namespace std;
int solve(vector<int> A){
    sort(A.begin(),A.end()); // sorting helps
    int i=0;
    int res = 0;
    for (int j = 0; j < A.size(); j++)
    {
        // increase the ans window
        // decrease to match constraint
        while(1) {
            // remove ith eleement
            i++;
        }
        // save the current ans
        res = max(res,j-i+1);
    }
    return res;
}