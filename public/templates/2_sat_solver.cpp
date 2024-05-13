// O(N + M)
// checker: https://codeforces.com/contest/1971/submission/260766599
namespace SS {
    vector<int> ids;
    vector<int> low;
    vector<bool> onStack;
    stack<int> st;
    vector<vector<int>> g;
    vector<bool> sols;
    int n=0;
    int n_terms=0;
    int timer;
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
        }
    }
    void stronglyConnectedComponents()
    {
        timer=0;
        ids.resize(n);
        fill(ids.begin(),ids.end(),-1);
        onStack.clear();
        onStack.resize(n);
        low.resize(n);
        for(int i=0;i<n;i++){
            if(ids[i]==-1){
                dfs(i);
            }
        }
    }
    // 1. call me to initialize graph
    void init(int terms) {
        n_terms = terms;
        n = 2*terms;
        g.clear();
        g.resize(n);
        sols.clear();
        sols.resize(n);
    }
    // ensure the equation is in CNF, eg (PvQ) ^ (~PvQ) ^ ... OR AND OR AND 
    void add_impl(int i,int j){
        g[i].push_back(j);
    }
    int neg(int i){
        if(i<n_terms){
            return i+n_terms;
        }
        return i-n_terms;
    }
    void add_or(int i,int j){
        add_impl(neg(i),j);
        add_impl(neg(j),i);
    }
    void make_equal(int i,int j) {
        add_or(neg(i),j);
        add_or(i,neg(j));
    }

    void add_xor(int i,int j){
        add_or(i,j);
        add_or(neg(i),neg(j));
    }
    void force_var(int i){
        add_impl(i,i);
    }
    // 2. call me to get ans
    bool solve(){
        stronglyConnectedComponents();
        for(int i=0;i<n_terms;i++){
            if(low[i]==low[neg(i)]) return false;
            sols[i] = low[i] > low[neg(i)]; // i am not sure if this works, can use reverse topo as well but since this is same as ordering so should work
        }
        return true;
    }
}
