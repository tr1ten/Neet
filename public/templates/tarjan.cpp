#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 +5;
vector<int> ids;
vector<int> low;
bool onStack[N];
stack<int> st;
vector<vector<int>> g;
int timer;
int scc_count;
void dfs(int u){
    onStack[u] = 1;
    st.push(u);
    ids[u] = low[u] = timer++;
    for(int v:g[u]){
        if(ids[v]==-1) dfs(v);
        if(onStack[v]) low[u] = min(low[u],low[v]); // maintain stack invariant, only include node in scc
    }
    if(low[u]==ids[u]){
        while(!st.empty()) {
            int v = st.top();
            onStack[v] = 0;
            low[v] = low[u];// once scc completed, reset back to start
            st.pop();
            if(v==u) break;
        } 
        scc_count++;
    }
}
int stronglyConnectedComponents(int n, vector<vector<int>> &adj)
{
    timer=0;
    scc_count = 0;
    ids.resize(n);
    fill(ids.begin(),ids.end(),-1);
    low.resize(n);
    g=adj;
    for(int i=0;i<n;i++){
        if(ids[i]==-1){
            dfs(i);
        }
    }
    return scc_count;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        while(m--){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        cout << stronglyConnectedComponents(n,adj) << endl;
    }
    return 0;
}
