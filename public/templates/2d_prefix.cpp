#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>

using namespace std;

const long long MOD = 1e9+7;
const long long INF = 1e10+5;

// Function to get sum from r1,c1 to r2,c2 from ps
long long get_sum(int r1, int c1, int r2, int c2, const vector<vector<long long>>& ps) {
    return ps[r1][c1] - (ps[r1][c2+1] + ps[r2+1][c1]) + ps[r2+1][c2+1];
}

// Function to fill the prefixes and check if x is ok
bool is_ok(long long x, int n, const vector<vector<int>>& mat, vector<vector<long long>>& pref) {
    // Reset and fill the prefixes
    for (auto& v : pref) memset(&v[0], 0, sizeof(long long)*v.size());
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            pref[i][j] = (mat[i][j] <= x) + pref[i+1][j] + pref[i][j+1] - pref[i+1][j+1];
        }
    }
    return true;
}
