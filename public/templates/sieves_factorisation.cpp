#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int sieve[N+1];
// find prime <sqrt(MAX)
// O(LlogL)
void preprocess(){
    sieve[0] = 1;
    sieve[1] = 1;
    for(int x=2;x<=N;x++){
        if(sieve[x]!=0) continue; 
        sieve[x] = x;
        for(int u=2*x;u<=N;u +=x){
            sieve[u] = x;
        }
    }
}

vector<int> factors(int x){
    vector<int> res;
    while(x>1){
        int f = sieve[x];
        if(x%f==0) res.push_back(f);
        while(x%f==0) x/=f;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    preprocess(); // must call this
    return 0;
}
