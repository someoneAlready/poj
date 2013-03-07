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
#define itr iterator
#define N 100
#define M 1000000

int i,j,k,m,n,l;
char s[N+10];
vi prm;
bool v[M+10];

void init(){
	fill(v, 0), prm.clear();
	repf(i, 2, M) if (!v[i]){
		prm.pb(i);
		repf(j, 2, M/i) v[i*j]=true;
	}
}

void add(vi &v, vi &a){
	k=0;
	repd(j, sz(v)-1, 0) k=k*10+v[j];
	a.pb(k), v.clear();
}

void solve(){
	n=strlen(s);
	vi v, a;
	repd(i, n-1, 0){
		v.pb(s[i]-'0');
		if (sz(v)==6){
			add(v, a);
		}
	}
	if (sz(v)) add(v, a);

	rep(i, sz(prm)){
		ll m=prm[i], k=0;
		if (m>=l) break;
		repd(j, sz(a)-1, 0) k=(k*1000000+a[j])%m;


		if (k==0){
			printf("BAD %lld\n", m);
			return; 
		}
	}
	puts("GOOD");
}

int main(){
	init();
	while (~scanf("%s%d", s, &l) && strcmp(s,"0")!=0 && l){
		solve();
	}
	return 0;
}


