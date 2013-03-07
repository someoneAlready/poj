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
#define N 1000001

int i,j,k,m,n,l;
vi a, prm, semi;
bool v[N+10], x[N+10];

int main(){
	repf(i, 1, N) if (i%4==1) a.pb(i);
	repf(i, 1, sz(a)-1) if (!v[a[i]]){
		prm.pb(a[i]);
		repf(j, 1, sz(a)-1){
			if (a[i]*a[j]>N) break;
			v[a[i]*a[j]]=true;
			if (a[j]<=a[i] && !v[a[j]])
				x[a[i]*a[j]]=true;
		}
	}
	repf(i, 1, N) if (x[i]) semi.pb(i);

	while (~scanf("%d", &n) && n){
		int x=0, y=sz(semi)-1;
		while (x!=y){
			int z=mid(x+1,y);
			if (semi[z]<=n) x=z;
			else y=z-1;
		}
		cout<<n<<' ';
		if (n<25) cout<<0<<endl;
		else cout<<x+1<<endl;
	}
	return 0;
}


