#include <bits/stdc++.h>

using namespace std;

vector<string> mat;
const int N = 1005;
bool vis[N][N];
pair<long,long> flood_fill(int i,int j,int m,int n,char c){
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    vis[i][j]=1;
    long long area = 1;
    long long peri = 0;
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};
    while (!q.empty())
    {   
        auto p = q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int y =p.first+dy[k],x=p.second+dx[k];
            if(x<m && y <n && x>=0 && y>=0 && !vis[y][x] && mat[y][x]==c) {
                vis[y][x] =1;
                area++;
                q.push(make_pair(y,x));
            }
            if( !(x<m && y <n && x>=0 && y>=0) || mat[y][x]!=c ) peri++;
        }
    }
    return make_pair(area,-peri);
    
}
