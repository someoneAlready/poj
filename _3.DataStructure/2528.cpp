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
#define M 10000
#define N (M*3+10)

int i,j,k,m,n,l;
bool v[M+10];

#define root 1, 1, m 
#define lson i*2, x, z
#define rson i*2+1, z+1, y

template<int SZ>
class SegTree{
	short int a[SZ+10];
inline	void update(int i){
		a[i*2]=a[i*2+1]=a[i];
		a[i]=0;
	}	
inline	void ins(int i, int x, int y, int l, int r, int k){
		if (x==l && y==r){
		   	a[i]=k; return; 
		}
		if (a[i]>0) update(i);
		a[i]=0;

		int z=mid(x, y);
		if (r<=z) ins(lson, l, r, k);
		else if (l>z) ins(rson, l, r, k);
		else ins(lson, l, z, k), ins(rson, z+1, r, k);
	}
inline	void color(int i, int x, int y){
		if (a[i]==-1) return;
		if (a[i]>0){
			v[a[i]]=1; return;
		}

		if (x==y) return;
		int z=mid(x, y);
		color(lson), color(rson);
	}
public:
	void clear(){ clr(a, -1); }
	void ins(int l, int r, int k){ ins(root, l ,r, k); }
	void color(){ color(root); }
};

SegTree<N*4+10> st;

struct P{
	int x, y;
	void input(){ scanf("%d%d", &x, &y); }
};
P a[M+10];
mii x2i, i2x;
int s[N+10], t[N+10];

int main(){
	int tests;
	scanf("%d", &tests);
	while (tests--){
		scanf("%d", &n);

		repf(i, 1, n) a[i].input();

		s[0]=t[0]=0;
		repf(i, 1, n) s[++s[0]]=a[i].x, s[++s[0]]=a[i].y, s[++s[0]]=a[i].y+1;
		sort(s+1, s+1+s[0]);
		repf(i, 1, s[0]) if (i==1 || s[i]!=s[i-1]) t[++t[0]]=s[i];
		m=t[0];



		st.clear();
		repf(i, 1, n){
			st.ins(lower_bound(t+1, t+1+m, a[i].x)-t,
				lower_bound(t+1, t+1+m, a[i].y)-t, i);
		}

		int ans=0; clr(v, 0);
		st.color();
		repf(i, 1, n) if (v[i]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}


