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
#define N 100
#define M 200

int i,j,k,m,n,l;
int f[N+10][M+10], g[N+10][M+10], v[N+10];
vi a[N+10];

void dfs(int i, int fa){
    repf(j, 0, m) g[i][j]=f[i][j]=v[i];
    
    rep(k, sz(a[i])) if (a[i][k]!=fa){
        int j=a[i][k];
        dfs(j, i);
        
        repd(k, m, 1) repf(l, 0, k-1){
            if (k-l-2>=0) checkmax(g[i][k], g[i][k-l-2]+f[j][l]);
            checkmax(g[i][k], f[i][k-l-1]+g[j][l]);
            if (k-l-2>=0) checkmax(f[i][k], f[i][k-l-2]+f[j][l]);            
        }
    }
}

int main(){    
    while (~scanf("%d%d", &n, &m)){
        clr(f, -1), clr(g, -1);
        repf(i, 1, n){
             scanf("%d", &v[i]);
             a[i].clear();
        }

        rep(x, n-1){
            scanf("%d%d", &i, &j);
            a[i].pb(j), a[j].pb(i);
        }        
        dfs(1, 0);
        //cout<<f[1][m]<<' '<<g[1][m]<<endl;
        printf("%d\n", max(f[1][m], g[1][m]));
    }    
    return 0;
}

