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
#define N 500

int i,j,k,m,n,l;
int f[N+10][N+10];
int yey[N+10][N+10], blo[N+10][N+10];

int main(){
    while (~scanf("%d%d", &n, &m) && n+m){
        clr(yey, 0), clr(f, 0), clr(blo, 0);
        repf(i, 1, n) repf(j, 1, m) 
            scanf("%d", &yey[i][j]), yey[i][j]+=yey[i][j-1];
        repf(i, 1, n) repf(j, 1, m)
            scanf("%d", &blo[i][j]), blo[i][j]+=blo[i][j-1];            
        repf(i, 1, n)
            repf(j, 0, m)
                repf(k, 0, j)
                    checkmax(f[i][j], f[i-1][k]+yey[i][j]+blo[i][m]-blo[i][j]);
        int ans=0;
        repf(j, 0, m) checkmax(ans, f[n][j]);
        printf("%d\n", ans);
    }
    return 0;
}

