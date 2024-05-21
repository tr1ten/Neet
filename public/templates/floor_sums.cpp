// https://codeforces.com/blog/entry/118001

// tested: https://cses.fi/problemset/result/9309219/
int MOD = 1e9 + 7;
int sum(int l,int r){
    l %=MOD,r%=MOD;
    int s1 = ((l-1))*(l)/2;
    s1 %=MOD;
    int s2 = r*(r+1)/2;
    s2 %=MOD;
    return (s2-s1+MOD)%MOD;
}
int floor_sums(int n){
    int res = 0;
    // fact: atmost sqrt distinct value of n/l
    for(int l=1,r=1;n/l;l=r+1){
        r = n/(n/l); // max r such that same floor value as l
        // res += (n/l)*sum(l,r)%MOD;
        // do something in range l to r for floor value of n/l
    }
    return res;
}
