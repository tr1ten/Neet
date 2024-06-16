vector<vector<int>> rotate(vector<vector<int>> &mat){
    int n=mat.size(),m=mat[0].size();
    vector<vector<int>> ans(m,vi(n));
    rep(i,0,n){
        rep(j,0,m){
            ans[j][i] = mat[i][j];
        }
    }
    rep(i,0,m){
        rep(j,0,n/2){
            swap(ans[i][j],ans[i][n-j-1]);
        }
    }
    return ans;
}