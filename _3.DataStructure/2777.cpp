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
#define N 100000

int i,j,k,m,n,l,t,o;
char s[100];

#define lson i*2, x, z
#define rson i*2+1, z+1, y

template<int SZ>
class SegTree{
	int a[SZ+10], mod[SZ+10];
	void update(int i){
		a[i*2]=a[i*2+1]=mod[i*2]=mod[i*2+1]=mod[i];
		mod[i]=0;
	}
public:
	void clear(){ clr(a, 0), clr(mod, 0); }
	void ins(int i, int x, int y, int l, int r, int c){
		if (x==l && y==r){
			a[i]=c;
			mod[i]=c;
			return;
		}
		if (mod[i]) update(i);

		int z=mid(x,y);
		if (r<=z) ins(lson, l, r, c);
		else if (l>z) ins(rson, l, r, c);
		else{
			ins(lson, l, z, c);
			ins(rson, z+1, r, c);
		}
		a[i]=a[i*2] | a[i*2+1];
	}
	int query(int i, int x, int y, int l, int r){
		if (x==l && y==r) return a[i];
		if (mod[i]) update(i);

		int z=mid(x, y);
		if (r<=z) return query(lson, l, r);
		else if (l>z) return query(rson, l, r);
		else return query(lson, l, z) | query(rson, z+1, r);
	}
};

SegTree<N*4+10> st;

int main(){
	while (~scanf("%d%d%d", &n, &t, &o)){
		st.clear();
		st.ins(1, 1, n, 1, n, 1);
		while (o--){
			scanf("%s", s);
			if (s[0]=='C'){
				scanf("%d%d%d", &i, &j, &k);
				if (i>j) swap(i,j);
				st.ins(1, 1, n, i, j, 1<<k-1);
			}
			else{
				scanf("%d%d", &i, &j);
				if (i>j) swap(i, j);
				k=st.query(1, 1, n, i, j);
				int ret=0;
				rep(i, t) if (k&(1<<i)) ret++;
				printf("%d\n", ret);
			}
		}
	}
	return 0;
}


