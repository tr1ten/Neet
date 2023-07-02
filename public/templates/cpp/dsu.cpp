#include <bits/stdc++.h>

using namespace std;


class DSU
{
public:
    int *par;
    int *sz;
    DSU(int n)
    {
        this->par = new int[n];
        this->sz = new int[n];
        for (int i = 0; i < n; i++)
        {
            this->par[i] = i;
            this->sz[i] = 1;
        }
    }
    int find(int x)
    {
        int p = x;
        while (p != this->par[p])
        {
            p = par[p];
        }
        return p;
    }
    void connect(int u, int v)
    {
        int rootu = find(u);
        int rootv = find(v);
        if (rootu == rootv)
            return;
        if (sz[rootu] < sz[rootv])
        {
            par[rootu] = rootv;
            sz[rootv] += sz[rootu];
        }
        else
        {
            par[rootv] = rootu;
            sz[rootu] += sz[rootv];
        }
    }
};

int main(int argc, char const *argv[])
{
    // test it
    DSU dsu(10);
    dsu.connect(1, 2);
    dsu.connect(2, 3);
    dsu.connect(4, 5);
    dsu.connect(5, 6);
    cout << dsu.find(1) << endl;
    cout << dsu.find(2) << endl;
    cout << dsu.find(3) << endl;
    cout << dsu.find(4) << endl;
    cout << dsu.find(5) << endl;
    return 0;
}
