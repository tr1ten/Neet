const int N = 3005;
int dp_prev[N];
int dp_cur[N];
int a[N];
int pa[N];
// must satisfy quandrangle inequality
int C(int i,int j) {
    return (pa[j+1]-pa[i])*(pa[j+1]-pa[i]);
}
// find dp[l]...dp[r]
void compute(int l,int r,int opl,int opr){
    if(r<l) return;
    int mid = (l+r) >> 1;
    pair<int,int> best = {INF,-1};
    for(int k=opl;k<=min(opr,mid);k++){
        best = min(best,{(k-1>=0 ? dp_prev[k-1] : 0) + C(k,mid),k}  );
    }
    dp_cur[mid] = best.first;
    int opt = best.second;
    compute(l,mid-1,opl,opt);
    compute(mid+1,r,opt,opr);
}

void testcase(){
    int n,k;
    cin >> n>> k;
    tkv(a,n);
    rep(i,0,n) {pa[i+1] =a[i]+pa[i]; dp_prev[i] = INF;}
    rep(i,0,k){
        compute(0,n-1,0,n-1);
        rep(i,0,n) dp_prev[i] = dp_cur[i];
    }
    put(dp_cur[n-1]);


}
