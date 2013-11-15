#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>
#include <cctype>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define pb push_back

#define N 40000

int i,j,k,m,n,l;

struct P{
	ll x, y, k;
	void in(){
		scanf("%lld%lld%lld", &x, &y, &k);
	}
	bool operator <(const P&p)const{
		return k<p.k; 
	}
};

#define lson i*2, x, z
#define rson i*2+1, z, y
#define mid(x, y) (((x)+(y))>>1)

ll x[N*6+10];
ll tot=0;

template <int SZ>
struct ST{
	ll a[SZ*4+10];
	void clear(){ clr(a, 0); }
	void ins(int i, int x, int y, int l, int r, ll k){
		if (x==l && y==r){
			a[i] = k;
			return;
		}
		int z = mid(x, y);
		if (a[i]){
			a[i*2] = a[i*2+1] = a[i];
			a[i] = 0;
		}
		if (r<=z) ins(lson, l, r, k);
		else if (l>=z) ins(rson, l, r, k);
		else ins(lson, l, z, k), ins(rson, z, r, k);
	}
	ll qry(int i, int x, int y){
		if (a[i]){
			return (::x[y]-::x[x])*a[i];
		}
		if (x==y || x+1==y) return 0;
		int z = mid(x, y);
		return qry(lson) + qry(rson);
	}
};

P a[N+10];
ST<N*6> st;

ll gao(){
	sort(a, a+n);
	st.clear();
	rep(l, n){
		i = lower_bound(x+1, x+1+x[0], a[l].x) - x;
		j = lower_bound(x+1, x+1+x[0], a[l].y) - x;
		st.ins(1, 1, x[0], i, j, a[l].k);
	}
	return st.qry(1, 1, x[0]);
}

int main(){
	scanf("%d", &n);
	rep(i, n) a[i].in();
	rep(i, n){
		x[++x[0]] = a[i].x - 1;
		x[++x[0]] = a[i].x;
		x[++x[0]] = a[i].x + 1;

		x[++x[0]] = a[i].y - 1;
		x[++x[0]] = a[i].y;
		x[++x[0]] = a[i].y + 1;
	}
	sort(x+1, x+1+x[0]);
	k = x[0];
	x[0] = 1;
	repf(i, 2, k) if (x[i]!=x[x[0]])
		x[++x[0]] = x[i];


	cout << gao() << endl;
	return 0;
}

