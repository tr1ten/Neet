#include <bits/stdc++.h>
using namespace std;
// battle tested
// https://judge.yosupo.jp/submission/170986
typedef long long ll;
const int N = 5*(1e5) + 5;
int n;
struct Segment{
    ll sum=0;
} segm[4*N]; // 0 index
Segment combine(Segment left,Segment right){
    Segment res;
    res.sum = (left.sum + right.sum);
    return res;
}

// child- 2*x+1,2*x+2 (0 coz index)
// add x to [l...r]
void update(int node,int left,int right,int i,ll value){
    if(left==i && right==i) {
            segm[node].sum += value;
        }
    else{
        int mid = (left+right)/2;
        if(i<=mid) update(2*node+1,left,mid,i,value);
        else update(2*node+2,mid+1,right,i,value);
        segm[node] = combine(segm[2*node+1] , segm[2*node+2]);
    }
    
}

Segment query(int node,int left,int right,int l,int r){
    if(left>=l && right<=r) {return segm[node];}
    int mid = (left+right)/2;
    Segment res;
    if(l<=mid) res = combine(res,query(2*node+1,left,mid,l,r));
    if(r>mid) res = combine(res,query(2*node+2,mid+1,right,l,r));

    return res;
}
// everything is zero indexed
void update(int i,ll x){
    update(0,0,n-1,i,x);
}
Segment query(int l,int r){
    return query(0,0,n-1,l,r);
}
int main(int argc, char const *argv[])
{   
    cin >> n;
    int q;
    cin >> q;
    for(int i=0;i<n;i++) {int x;cin >> x;update(i,x);}
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        if(x==0){
            int ind,y;
            cin >> ind >> y;
            update(ind,y);
        }
        else{
            int l,r;
            cin >> l >> r;
            r--;
            cout << (query(l,r)).sum << endl;
        }
    }
    
    return 0;
}
