#include <bits/stdc++.h>
using namespace std;
// battle tested
typedef long long ll;
const int N = 2*(1e5) + 5;
int n;
struct Segment{
    ll sum,lazy;
} segm[2*N]; // 0 index


void propogate(int node,int left,int right){
    segm[node].sum += (right-left+1)*segm[node].lazy;
    if(left<right){
        segm[2*node+1].lazy += segm[node].lazy;
        segm[2*node+2].lazy += segm[node].lazy;
    }
    segm[node].lazy =0;
    
}
// child- 2*x+1,2*x+2 (0 coz index)
// add x to [l...r]
void update(int node,int left,int right,int l,int r,ll value){
    propogate(node,left,right); // main funda update only when called
    if(left>=l && right<=r) {
        segm[node].lazy += value;
        }
    else{
        int mid = (left+right)/2;
        if(l<=mid) update(2*node+1,left,mid,l,r,value);
        if(r>mid) update(2*node+2,mid+1,right,l,r,value);
        propogate(2*node+1,left,mid); // since we need to use thier value they must be updated
        propogate(2*node+2,mid+1,right);
        segm[node].sum = segm[2*node+1].sum + segm[2*node+2].sum;

    }
    
}

ll query(int node,int left,int right,int l,int r){
    propogate(node,left,right);
    if(left>=l && right<=r) return segm[node].sum;
    int mid = (left+right)/2;
    ll res= 0;
    if(l<=mid) res +=query(2*node+1,left,mid,l,r);
    if(r>mid) res +=query(2*node+2,mid+1,right,l,r);
    return res;

}
// everything is zero indexed
void update(int l,int r,ll x){
    update(0,0,n-1,l,r,x);
}
ll query(int l,int r){
    return query(0,0,n-1,l,r);
}
int main(int argc, char const *argv[])
{   
    n = 10;
    for(int i=0;i<n;i++) update(i,i,i+1);
    update(1,4,2);
    cout << query(0,4); // 23
    return 0;
}
