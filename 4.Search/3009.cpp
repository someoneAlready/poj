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
#define N 20

int i,j,k,m,n,l;
int a[N+10][N+10];
int ans;

struct P{
    int x, y;
    P(){}
    P(int x,int y):x(x),y(y){}
    P operator +(P &p)const{ return P(x+p.x,y+p.y); }
    P operator -(P &p)const{ return P(x-p.x,y-p.y); }
    bool ok(){if (x>0 && y>0 && x<=n && y<=m)return true; return false; }
};

P d[4]={P(-1,0), P(0,1), P(1,0), P(0, -1)};
P S, G;

void dfs(P p, int dep){
    if (dep>10 || (ans!=-1 && dep>=ans)) return;
    rep(k, 4){
        P q=p+d[k];
        if (q.ok() && a[q.x][q.y]==1) continue;
        while (q.ok() && a[q.x][q.y]==0) q=q+d[k];
        if (q.ok()){
            if (a[q.x][q.y]==3) _checkmin(ans, dep);
            else{
                a[q.x][q.y]=0;
                dfs(q-d[k], dep+1);
                a[q.x][q.y]=1;
            }
        }
    }
}

int main(){
    while (~scanf("%d%d", &m, &n) && n+m){
        fill(a, 0);
        repf(i, 1, n) repf(j, 1, m){
            scanf("%d", &a[i][j]);
            if (a[i][j]==2) S=P(i,j), a[i][j]=0;
            else if (a[i][j]==3) G=P(i,j);
        }
        ans=-1;
        dfs(S, 1);
        printf("%d\n", ans);
    }
    return 0;
}
