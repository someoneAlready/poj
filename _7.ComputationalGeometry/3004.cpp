#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

#define sqr(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define pb push_back
#define N 500

#define eps 1e-8
int sgn(double d){ return d<-eps?-1:d>eps; }

const double pi=acos(-1.);
template <class T> void checkmax(T &a, T b){ if (b>a) a=b; }
template <class T> void checkmin(T &a, T b){ if (b<a) a=b; }

struct P{
	int t, i;
	double k;
	P(){}
	P(int t, double e, int i):t(t),i(i){
		k=fmod(e+2*pi, 2*pi);
	}
	bool operator<(const P&p)const{
		if (sgn(k-p.k)!=0) return k<p.k;
		return t<p.t;
	}
};

int i,j,k,m,n,l;
vector<P> v;
bool mk[N+10];

int gao(){
	if (sz(v)==0) return 0;

	sort(v.begin(), v.end());
	int ret=INT_MAX;
	rep(i, sz(v)){
		m=0;
		int cnt=1;
		stack<int> s;
		clr(mk, 0);
		rep(e, sz(v)){
			int j=(i+e)%sz(v);
			if (v[j].t==0){
				mk[v[j].i]=1;
				s.push(v[j].i);
			}
			else if (mk[v[j].i]){
				cnt++;
				while (!s.empty())
					mk[s.top()]=0, s.pop();
			}
		}
		checkmin(ret, cnt);
	}
	return ret;
}

int main(){
	int ts;
	scanf("%d", &ts);
	while (ts--){
		int d;
		scanf("%d%d", &n, &d);
		v.clear();
		while (n--){
			int x, y;
			scanf("%d%d", &x, &y);
			if (sqr(x)+sqr(y)<=sqr(d)) continue;
			double a, e;
			a=atan2(y, x), e=asin(d/sqrt(1.*sqr(x)+sqr(y)));
			v.pb(P(0, a-e, m)), v.pb(P(1, a+e, m++));
		}
		printf("%d\n", gao());
	}
	return 0;
}
