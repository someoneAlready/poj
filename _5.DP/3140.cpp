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
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define N 100000

int i,j,k,m,n,l;
vi a[N+10], b[N+10];
ll c[N+10], s[N+10];
ll ret, tot;

template<class T>T tAbs(T a){ return a>0?a:-a; }

void dfs(int i, int fa){
    s[i]=c[i];
    rep(k, sz(a[i])) if (a[i][k]!=fa){
        int j=a[i][k];
        dfs(j, i), s[i]+=s[j];
    }
    _checkmin(ret, tAbs(tot-2*s[i]));
}

ll solve(){
    clr(s, 0);
    repf(i, 1, n) sort(all(b[i]));
    repf(i, 1, n) rep(j, sz(b[i])) if (j==0 || b[i][j]!=b[i][j-1]) 
        a[i].pb(b[i][j]);
    ret=-1;
    dfs(1, 0);
    return ret;
}

int main(){
    int test=0;
    while (~scanf("%d%d", &n, &m) && n+m){
        tot=0;
        repf(i, 1, n)
            scanf("%d", &c[i]), a[i].clear(), b[i].clear(), tot+=c[i];
        while (m--) scanf("%d%d", &j, &k), b[j].pb(k), b[k].pb(j);
        printf("Case %d: %lld\n", ++test, solve());
    }
    return 0;
}

