#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<typename T> 
using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// useful defs
typedef long long ll; 
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef unordered_map<ll,ll> mll;
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define per(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define trav(a,arr) for (auto& a: (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name,sz,value) vi name(sz,value)
#define mk_mat(name,n,m,value) vector<vi> name(n, vi(m, value))
#define contains(x) find(x) != string::npos
#define tkv(vec,sz) rep(i,0,sz) cin>>vec[i]
#define srv(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
#define vsum(vec) accumulate(vec.begin(), vec.end(), 0L);
#define vmax(vec) *max_element(vec.begin(), vec.end());
#define vmin(vec) *min_element(vec.begin(), vec.end());
#define pvc(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
#define put(x) cout<<(x)<<endl;
#define put2(x,y) cout<<(x)<<" "<<(y)<<endl;
#define put3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl;
#define mod(x) (x + MOD)%MOD
// debugging
#define timed(x) {auto start = chrono::steady_clock::now(); x; auto end = chrono::steady_clock::now(); auto diff = end - start; cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;}
void __print(auto x) {cerr << x;}
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; __print(x); cerr << endl;
#else
#define debug(x)
#endif
const ll MOD = 1e9+7;
const ll INF = 1e10+5;
const int S = 500; // block size
struct Q {
    int l;
    int r;
    int idx;
};
bool cmp(Q A, Q B)
{
  if (A.l / S != B.l / S) return A.l< B.l;
  return (A.r < B.r)^(A.l/S%2); // change direction after each block change due to q.l
}
const int N = 2e6 + 3;
unordered_map<ll,ll> cnt; // DS to get & update res 
ll res=0; // running ans of each query
void add(int j){
}
void del(int j){
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--){
        int n,t;
        cin >> n >> t;
        vi A(n);
        tkv(A,n);
        vector<Q> ques;
        rep(i,0,t){
            int l,r;
            cin >> l >> r;
            ques.push_back({l-1,r-1,i}); // 0 index
        }
        sort(all(ques),cmp);
        int curL = 0;
        int curR = -1;
        vi ans(t);
        rep(i,0,t){
            auto q =ques[i];
            while(curL>q.l){ // add
                curL--;
                // add();
            }
            while(curL<q.l){ // remove 
                // del();
                curL++;
            }
            while(curR>q.r){    // rempve
                // del();
                curR--;
            }
            while(curR<q.r){ // add
                curR++;
                // add();
            }
            ans[q.idx] = res;
        }
        trav(x,ans) put(x);
    }

    return 0;
}
