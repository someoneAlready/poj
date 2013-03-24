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
#define N 1000 
struct E{
    int i,j;
    E(){}
    E(int i,int j):i(i),j(j){}
};

int i,j,k,m,n,l;
bool g[N+10][N+10];

vi a[N+10], bcc[N+10];
int pre[N+10], bccno[N+10], low[N+10];
bool iscut[N+10];
int dfs_clock, bcc_cnt;
stack<E> s;

void dfs(int i, int fa){
    pre[i]=low[i]=++dfs_clock;
    int child=0;
    rep(k, sz(a[i])){
        int j=a[i][k];
        if (!pre[j]){
            s.push(E(i,j)), child++;
            dfs(j, i), checkmin(low[i], low[j]);
            if (low[j]>=pre[i]){
                iscut[i]=true, bcc_cnt++, bcc[bcc_cnt].clear();
                for(;;){
                    E e=s.top(); s.pop();
                    if (bccno[e.i]!=bcc_cnt) bcc[bcc_cnt].pb(e.i);
                    if (bccno[e.j]!=bcc_cnt) bcc[bcc_cnt].pb(e.j);
                    bccno[e.i]=bccno[e.j]=bcc_cnt;
                    if (e.i==i && e.j==j) break;
                }
            }
        }
        else if (j!=fa && pre[j]<pre[i])
            s.push(E(i,j)), checkmin(low[i], pre[j]);
    }
    if (fa<0 && child==1) iscut[i]=0;
}


void find_bcc(int n){
    dfs_clock=bcc_cnt=0;
    clr(pre, 0), clr(iscut, 0), clr(bccno, 0);
	repf(i, 1, n) if (!pre[i])
    	dfs(i, -1);
}

bool ans[N+10];
int v[N+10];

bool dfs(int i, int fa, int c){
    rep(k, sz(a[i])){
        int j=a[i][k];
        if (j!=fa && bccno[j]==c){
            if (v[j]==-1){
             	v[j]=1-v[i];
				if (dfs(j, i, c)) return true;
            }
            else if (v[i]==v[j]) return true;
        }
    }
    return false;
}

int solve(){
    clr(ans, 0);
    repf(i, 1, bcc_cnt){
        rep(j, sz(bcc[i])) bccno[bcc[i][j]]=i;
        clr(v, -1), v[bcc[i][0]]=1;
        if (dfs(bcc[i][0], -1, i))
            rep(j, sz(bcc[i])) ans[bcc[i][j]]=true;
    }

    int ret=0;
    repf(i, 1, n) if (!ans[i]) ret++;
    return ret;
}

int main(){
    while (~scanf("%d%d", &n, &m) && n+m){
        clr(g, 1);
        while (m--) 
            scanf("%d%d", &i, &j), g[i][j]=g[j][i]=false;
		repf(i, 1, n) a[i].clear();
		repf(i, 1, n) repf(j, i+1, n)
		   if (g[i][j])	a[i].pb(j), a[j].pb(i);
		
        find_bcc(n);
        printf("%d\n", solve());
    }
    return 0;
}

