#include <iostream>

using namespace std;

const long long MOD = 1e9+7;
const long long INF = 1e10+5;

const int N = 1000 + 5;
long long fact[N];
long long inv[N];
long long finv[N];

void pre() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i-1]*i)%MOD;
    }
    inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    finv[0] = finv[1] = 1;
    for (int i = 2; i <= N; i++) {
        finv[i] = (inv[i]*finv[i-1])%MOD;
    }
}

long long nCk(int n,int k) {
    return (((fact[n]*finv[k])%MOD)*finv[n-k])%MOD;
}

int main(int argc, char const *argv[]) {
    pre();
    cout << nCk(10,2);
    return 0;
}