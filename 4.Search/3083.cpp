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
#define N 40

int i,j,k,m,n,l;
char a[N+10][N+10];
int v[N+10][N+10];

struct P{
    int x, y;
    P(){}
    P(int x, int y):x(x), y(y){}
    P operator +(P &p)const{ return P(x+p.x,y+p.y); }
    bool ok(){if (x>0 && y>0 && x<=n && y<=m && a[x][y]!='#')return true; return false; }
};
P S, E;
P d[4]={P(0,-1), P(-1,0), P(0,1), P(1,0)};

int bfs(){
    queue<P> q; fill(v, 0);
    q.push(S), v[S.x][S.y]=1;
    
    while (!q.empty()){
        rep(k, 4){
            P p=q.front()+d[k];
            if (p.ok() && !v[p.x][p.y]){
                v[p.x][p.y]=v[q.front().x][q.front().y]+1;
                q.push(p);
            }
        }
        q.pop();
    }
    return v[E.x][E.y];
}

int dfsLF(P x, int k){
    if (a[x.x][x.y]=='E') return 1;
    repf(i, -1, 2){
        int kk=(4+k+i)%4;
        P p=x+d[kk];
        if (p.ok()) return dfsLF(p, kk)+1;
    }
}


int dfsRT(P x, int k){
    if (a[x.x][x.y]=='E') return 1;
    repd(i, 1, -2){
        int kk=(4+k+i)%4;
        P p=x+d[kk];
        if (p.ok()) return dfsRT(p, kk)+1;
    }
}

int main(){
    int tests;
    scanf("%d", &tests);
    while (tests--){
        scanf("%d%d", &m, &n);
        repf(i, 1, n) repf(j, 1, m){
            a[i][j]=getchar();
            while (strchr("#.SE", a[i][j])==NULL) a[i][j]=getchar();
            if (a[i][j]=='S') S=P(i,j);
            else if (a[i][j]=='E') E=P(i,j);
        }
        int lf, rt;
        if (S.x==1) lf=rt=4;
        else if (S.x==n) lf=rt=2;
        else if (S.y==1) lf=rt=3;
        else if (S.y==m) lf=rt=1;
        
        printf("%d %d %d\n", dfsLF(S, lf), dfsRT(S, rt), bfs());
    }
    return 0;
}
