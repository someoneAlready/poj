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
#define itr iterator
#define N 100
#define M 10000

struct E{
    int to, w;
    E(){}
    E(int to, int w):to(to), w(w){}
};

struct P{
    int to, l, t;
    P(){}
    P(int to, int l, int t):to(to),l(l),t(t){}
};

int i,j,k,m,n,l,li,ti,t,ans;
vector<E> vl[N+10], vt[N+10];
vector<P> a[N+10];
int dL[N+10], dT[N+10];
bool v[N+10];
mii mp[N+10];


void dfs(int i, int t, int l){

    if (t-dT[i]<0 || (ans!=-1 && l+dL[i]>=ans)) return;           
    if (i==n){
        _checkmin(ans, l); return;
    }
    
	mii::itr it=mp[i].lower_bound(t);
	if (it!=mp[i].end() && l>=it->second) return;

	while(1){
		mii::itr it=mp[i].upper_bound(t); 
		if (it==mp[i].begin() || it==mp[i].end()) break;
		it--;
		if (it->second>=l) mp[i].erase(it);
		else break;
	}
	
	mp[i][t]=l;
    
        
    rep(k, sz(a[i])){
        P &p=a[i][k];
        dfs(p.to, t-p.t, l+p.l);
    }
}

void gao(vector<E> a[], int d[N+10]){
    queue<int> q; clr(d, -1), clr(v, 0);
    q.push(n), d[n]=0, v[n]=1;
    
    while (!q.empty()){
        int i=q.front(); q.pop(), v[i]=false;
        rep(k, sz(a[i])){
            E &e=a[i][k];
            if (d[e.to]==-1 || d[e.to]>d[i]+e.w){
                d[e.to]=d[i]+e.w;
                if (!v[e.to])
                    v[e.to]=1, q.push(e.to);
            }
        }
    }
}

int main(){
    while (~scanf("%d%d%d", &t, &n, &m)){
        repf(i, 1, n) a[i].clear(), vl[i].clear(), vt[i].clear(), mp[i].clear();
        while (m--){
            scanf("%d%d%d%d", &i, &j, &li, &ti);
            a[i].pb(P(j, li, ti)), vl[j].pb(E(i, li)), vt[j].pb(E(i, ti));
        }
        gao(vl, dL), gao(vt, dT);
        ans=-1;
        
        dfs(1, t, 0);
        printf("%d\n", ans);
    }
    return 0;
}
