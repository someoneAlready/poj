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
#define N 500000
#define M 708 

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

struct P{
	char name[11]; 
	int k;
	void input(){scanf("%s%d", name, &k);}
};

int i,j,k,m,n,l;
bool v[M+10];
int f[N+10], g[N+10];
vi prm;
SegTree<N*4+10> st;
P a[N+10];

void init(){
	repf(i, 2, M){
		if (!v[i]){
			prm.pb(i);
			repf(j, 2, M/i) v[i*j]=1;
		}
	}
}

int main(){
	init();	
	while (~scanf("%d%d", &n, &k)){
		repf(i, 1, n) a[i].input();
		st.clear();
		
		repd(i, n, 1){
			k=st.ins(1, 1, n, k);
			g[n+1-i]=k;
			if (i-1){
				j=k-st.query(1, 1, n, 1, k);
				j+=a[k].k<0?1:0;
				k=(j+a[k].k)%(i-1);
				k=(k-1+i-1)%(i-1)+1;
			}
		}

		int ans=1, mm=0;
		repf(i, 1, n){
			int k=i, t=1;
			rep(j, sz(prm)) if (k%prm[j]==0){
				l=1;
				while (k%prm[j]==0) k/=prm[j], l++;
				t*=l;
			}
			else if (prm[j]>n) break;

			if (k!=1) t*=2;
			if (t>mm) mm=t, ans=i;
		}

		printf("%s %d\n", a[g[ans]].name, mm);
	}	
	return 0;
}


