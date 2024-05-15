// call with asc and desc a
// return zig zag array a1>a2<a3>a4
bool zig_zag(vector<int> a,vector<int> &b){    
    sort(a.begin(),a.end());
    int i,j;
    int n = a.size();
    for(int s=0;s<2;s++){
        for(i=0,j=s;j<n;j+=2) b[j] = a[i++];
        for(j=s^1;j<n,i<n;j+=2) b[j] = a[i++];
        int ok = 1;
        for(i=1;i<n;i++){
            if(b[i]==b[i-1]){ ok=0;break;}    
        }
        if(ok) return true;
    }
    return false;
}