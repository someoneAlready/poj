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

int i,j,k,m,n,l;
int a[N+10], f[N+10], g[N+10];

#define ll i*2
#define rr i*2+1
#define lson ll, x, z
#define rson rr, z+1, y
template<int SZ>
class SegTree{
public:
	int sum[SZ], lMax[SZ], rMax[SZ], lMin[SZ], rMin[SZ];
	int Min[SZ], Max[SZ];
	void clear(){ 
		clr(sum, 0), clr(lMax, 0), clr(rMax, 0),
		fill(Max, Max+SZ, INT_MIN);
		fill(Min, Min+SZ, INT_MAX);
	}

	void ins(int i, int x, int y, int k, int val){
		if (x==y){
			sum[i]=lMax[i]=rMax[i]=lMin[i]=rMin[i]=val;
			return;
		}
		int z=mid(x, y);

		if (k<=z){
		   	ins(lson, k, val);
		}
		else{
		   	ins(rson, k, val);
		}

		sum[i]=sum[ll]+sum[rr];
		lMax[i]=max(sum[ll]+lMax[rr], lMax[ll]);
		rMax[i]=max(rMax[ll]+sum[rr], rMax[rr]);
		lMin[i]=min(sum[ll]+lMin[rr], lMin[ll]);
		rMin[i]=min(rMin[ll]+sum[rr], rMin[rr]);

		checkmax(Max[i], rMax[ll]+lMax[rr]);
		checkmin(Min[i], rMin[ll]+lMin[rr]);
	}
};

SegTree<N*4+10> st;

int main(){
	scanf("%d", &n);
	st.clear();
	repf(i, 1, n) scanf("%d", &k), st.ins(1, 1, n, i, k);
	scanf("%d", &m);
	while (m--){
		scanf("%d%d", &j, &k);
		st.ins(1, 1, n, j, k);
		int ans=max(st.sum[1]-st.Min[1], st.Max[1]);
		if (st.Max[1]==st.sum[1]) ans=st.sum[1]-st.Min[1];
		printf("%d\n", ans);
	}
	return 0;
}


