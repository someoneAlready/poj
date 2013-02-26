#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
template <class T> void checkmax(T &t, T x){if (x > t) t = x;}
template <class T> void checkmin(T &t, T x){if (x < t) t = x;}
template <class T> void _checkmax(T &t, T x){if (t == -1 || x > t) t = x;}
template <class T> void _checkmin(T &t, T x){if (t == -1 || x < t) t = x;}
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define fill(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define N 30

int i,j,k,m,n,l;
char a[N+10][N+10][N+10];
int v[N+10][N+10][N+10];

struct P{
    int x, y, z;
    P(){}
    P(int x, int y, int z):x(x),y(y),z(z){}
    P operator +(P &p)const{ return P(x+p.x, y+p.y, z+p.z); }   
    bool ok(){ if (x>0 && y>0 && z>0 && x<=n && y<=m && z<=l && a[x][y][z]!='#') return true; return false;}     
};

P d[]={P(1,0,0), P(-1,0,0), P(0,1,0), P(0,-1,0), P(0,0,1), P(0,0,-1)};
P S, E;

void bfs(){
    queue<P> q; fill(v, -1);
    q.push(S), v[S.x][S.y][S.z]=0;
    while (!q.empty()){
        int dep=v[q.front().x][q.front().y][q.front().z];
        rep(k, 6){
            P p=q.front()+d[k];
            if (p.ok() && v[p.x][p.y][p.z]==-1){
                v[p.x][p.y][p.z]=dep+1;
                q.push(p);
            }
        }
        q.pop();
    } 
    if (v[E.x][E.y][E.z]==-1) puts("Trapped!");
    else printf("Escaped in %d minute(s).\n", v[E.x][E.y][E.z]);
}

int main(){
    while (~scanf("%d%d%d", &n, &m, &l) && n+m+l){
        repf(i, 1, n) repf(j, 1, m) repf(k, 1, l){
            a[i][j][k]=getchar();
            while (strchr("#.SE", a[i][j][k])==NULL) a[i][j][k]=getchar();
            if (a[i][j][k]=='S') S=P(i,j,k);
            else if (a[i][j][k]=='E') E=P(i,j,k);
        }
        bfs();

    }
    return 0;
}
