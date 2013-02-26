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

#define N 26

int i,j,k,m,n,l;
bool v[N+10][N+10];

struct P{
    int x, y;
    P(){}
    P(int x,int y):x(x),y(y){}
    P operator +(P &p)const{
        return P(x+p.x, y+p.y);
    }
    bool ok(){
        if (x>0 && y>0 && x<=n && y<=m && !v[x][y]) return true;
        return false;
    }
    void color(bool flag){
        v[x][y]=flag;
    }
};

P d[8]={P(-2, -1), P(-2, 1), P(-1, -2), P(-1, 2), 
        P(1, -2), P(1, 2) , P(2, -1), P(2, 1)};
P s[N*N+10];

bool dfs(P p, int dep){
    s[dep]=p;
    if (dep==1){
        repd(i, n*m, 1) printf("%c%d", s[i].x-1+'A', s[i].y);
        putchar('\n');
        return true;
    }
    
    rep(k, 8){
        P q=p+d[k];
        if (q.ok()){
            q.color(true);
            if (dfs(q, dep-1)) return true;
            q.color(false);
        }
    }
    return false;
}

void solve(){
    fill(v, 0);
    repf(i, 1, 1) repf(j, 1, 1){
        s[n*m]=P(i,j);
        P(i,j).color(true);
        if (dfs(P(i,j), n*m)) return;
        P(i,j).color(false);
    }
    puts("impossible");
}

int main(){
    int tests;
    scanf("%d", &tests);
    repf(test, 1, tests){
        scanf("%d%d", &m, &n);
        printf("Scenario #%d:\n", test);
        solve();
        putchar('\n');
    }
    return 0;
}

