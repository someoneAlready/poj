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
#define N 200000

struct P{
	int p, val;
	void input(){ scanf("%d%d", &p, &val); }
};

int i,j,k,m,n,l;
P a[N+10];
int ans[N+10];

#define lson i*2, x, z
#define rson i*2+1, z+1, y
template<int SZ>
class SegTree{
public:
	int a[SZ+10];
	void clear(){ clr(a, 0); }

	int query(int i, int x, int y, int l, int r){
		if (l>r) return 0;
		if (x==l && y==r) return a[i];
		int z=mid(x, y);
		if (r<=z) return query(lson, l, r);
		else if (l>z) return query(rson, l, r);
		else return query(lson, l, z)+query(rson, z+1, r);
	}

	int ins(int i, int x, int y, int p){
		if (x==y){
			a[i]=1; return x;
		}
		int z=mid(x, y), ret;
		if (p<=z-x+1-a[i*2]) ret=ins(lson, p);
		else ret=ins(rson, p-(z-x+1-a[i*2]));
		a[i]=a[i*2]+a[i*2+1];
		return ret;
	}
};
SegTree<N*4+10> st;

int main(){
	while (~scanf("%d", &n)){
		repf(i, 1, n) a[i].input(), a[i].p++;
		st.clear(), clr(ans, 0);
		repd(i, n, 1){
			k=st.ins(1, 1, n, a[i].p);
			ans[k]=a[i].val;
		}
		repf(i, 1, n){
			if (i-1) putchar(' ');
			printf("%d", ans[i]);
		}
		putchar('\n');
	}
	return 0;
}


