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
#define N 1000

int i,j,k,m,n,l;
double a[N+10], b[N+10];
int f[N+10], g[N+10];

void gao(double *a, int *f){
    a[0]=f[0]=0;
    repf(i, 1, n)
        repf(j, 0, i-1) if (a[j]<a[i])
            checkmax(f[i], f[j]+1);
}

int dp(){
    int ret=0;
    repf(i, 1, n) repf(j, i+1, n)
        checkmax(ret, f[i]+ g[n+1-j]);
    return n-ret;
}

int main(){
    while (~scanf("%d", &n)){
        fill(f, 0), fill(g, 0);
        repf(i, 1, n) scanf("%f", &a[i]);
        memcpy(b, a, sizeof(a)), reverse(b+1, b+1+n);
        gao(a, f), gao(b, g);
        printf("%d\n", dp());
    }
    return 0;
}

