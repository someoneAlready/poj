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
int ans, tot;
bool v[N+10];

void dfs(int i, int now){
    if (now<ans) return;
    if (i==n){
        int tmp=0;
        rep(j, n) if (v[j])
        rep(k, n) if (!v[k]) tmp+=a[j][k];
        checkmax(ans, tmp);
        return;
    }
    dfs(i+1, now);

    rep(j, n) if (v[j]) now-=a[i][j];    
    v[i]=true;
    dfs(i+1, now);
    v[i]=false; 
}

int main(){
    while (~scanf("%d", &n)){
        tot=ans=0;
        rep(i, n) rep(j, n) scanf("%d", &a[i][j]), tot+=(i>j?0:a[i][j]);
        fill(v, 0);
        dfs(0, tot);
        printf("%d\n", ans);
    }
    return 0;
}
