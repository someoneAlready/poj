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

#define eps 1e-12
const double pi=acos(-1.);
int i,j,k,m;
double l, n, c;

int main(){
	while (cin>>l>>n>>c && l>=0 && n>=0 && c>=0){
		double _l=(1+n*c)*l; 
		_l/=2., l/=2.;
		double x=0, y=pi;
		while (y-x>eps){
			double z=mid(x,y);
			double __l=z/sin(z)*l;
			if (__l<_l) x=z+eps;
			else y=z;
		}
		if (x==0) printf("%.3f\n", 0.); 
		else{
			printf("%.3f\n", l/sin(x)*(1-cos(x)));
		}
	}
	return 0;
}


