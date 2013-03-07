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
#define M 15*25*N

int i,j,k,m,n,l;
int c[N+10], g[N+10];
int f[N+10][M*2+10];

int main(){
    while (~scanf("%d%d", &n, &m)){
        repf(i, 1, n) scanf("%d", &c[i]);
        repf(i, 1, m) scanf("%d", &g[i]);
        fill(f, 0);
        f[0][0+M]=1;
        repf(i, 1, m) repf(k, 1, n) repf(j, -M, M-g[i]*c[k])
            f[i][j+g[i]*c[k]+M]+=f[i-1][j+M];
        printf("%d\n", f[m][0+M]);
    }
    return 0;
}

