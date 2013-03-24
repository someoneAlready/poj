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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
int i,j,k,m,n,l;

#define N 10000 
 
vi a[N+10];
int dfn[N+10], low[N+10], num[N+10]; 
int belong[N+10], s[N+10]; 
bool inS[N+10]; 
int Idx, now; 
 
void tar(int i){ 
    dfn[i]=low[i]=++now; 
    s[++s[0]]=i; 
    inS[i]=true; 
    rep(k, sz(a[i])){ 
        int j=a[i][k]; 
        if (dfn[j]==0){ 
            tar(j); 
            low[i]=min(low[i], low[j]); 
        } 
        else if (inS[j]) 
            low[i]=min(low[i], dfn[j]); 
    } 
 
    if (low[i]==dfn[i]){ 
        Idx++; 
        do{ 
            j=s[s[0]--]; 
            belong[j]=Idx, num[Idx]++;
            inS[j]=false; 
        } 
        while(j!=i);
    } 
} 

void tar(){
	now=Idx=s[0]=0;
	clr(dfn, 0), clr(inS, 0), clr(num, 0);
	repf(i, 1, n) if (dfn[i]==0){
	   	tar(i);
	}
}

int outDeg[N+10];
vi b[N+10];
bool v[N+10];

int dfs(int i){
	int ret=1;
	rep(k, sz(b[i])){
		int j=b[i][k];
		if (!v[j]) ret+=dfs(j);
	}
	return ret;
}

int solve(){
	clr(outDeg, 0), clr(v, 0);
	repf(i, 1, Idx) b[i].clear();
	repf(i, 1, n) rep(k, sz(a[i])){
		int j=a[i][k], ii=belong[i], jj=belong[j];
		if (ii!=jj) outDeg[ii]++, b[jj].pb(ii);
	}	
	vi vt;
	repf(i, 1, Idx) if (outDeg[i]==0) vt.pb(i);
	if (sz(vt)==1){
		if (dfs(vt[0])==Idx) return num[vt[0]];
		return 0;	
	}
	return 0;
}

int main(){
	while (~scanf("%d%d", &n, &m)){
		repf(i, 1, n) a[i].clear();
		while (m--) scanf("%d%d", &i, &j), a[i].pb(j);
		tar();
		printf("%d\n", solve());
	}	
	return 0;
}


