#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int K = 25;
const int N = 1e5 + 5;

ll st[N][K+1];
ll merge(ll x,ll y){
    return min(x,y);
}
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
void build(vector<ll> A){
    int K = log2_floor(A.size());
    for(int i =0;i<A.size();i++) st[i][0] = A[i];
    for(int k=1;k<=K;k++){
        for(int i=0;i<A.size();i++){
            st[i][k] = merge(st[i][k-1],st[i+(1ll<<(k-1))][k-1] );
        }
    }
}
// pre C++20

ll query(int l,int r){
    int k = log2_floor(r-l+1);
    return merge(st[l][k],st[r-(1ll<<k) +1][k] );
}
int main(int argc, char const *argv[])
{
    vector<ll> a{2,3,1,4,5,3,1,0};
    build(a);
    cout << query(3,7) << endl;
    
    return 0;
}
