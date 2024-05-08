#include<bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }
inline long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }
inline long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }
struct GCD_type { long long x, y, d; };
GCD_type ex_GCD(long long a, long long b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}
int testCases;
int t;
const int N = 20;
long long a[N], n[N], ans, lcmm;
bool crt(){
    ans = a[1];
    lcmm = n[1];
    for(int i = 2; i <= t; i++)
    {
        auto pom = ex_GCD(lcmm, n[i]);
        int x1 = pom.x;
        int d = pom.d;
        if((a[i] - ans) % d != 0) return false;
        ans = normalize(ans + x1 * (a[i] - ans) / d % (n[i] / d) * lcmm, lcmm * n[i] / d);
        lcmm = LCM(lcmm, n[i]); // you can save time by replacing above lcm * n[i] /d by lcm = lcm * n[i] / d
    }
    return true;
}

void testcase(){
    t = 2;
    for(int i=1;i<=t;i++){
        cin >> a[i] >> n[i];
    }
    if(!crt()) cout << ("no solution") << endl;
    else cout << (ans,lcmm);
}
