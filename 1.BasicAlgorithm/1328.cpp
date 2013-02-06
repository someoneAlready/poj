#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstdio>
#include <cmath>

using namespace std;
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define fill(a, b) memset(a, b, sizeof(a))
#define pb push_back

int i,j,k,m,n,l;
int x, y, d;

const double eps=1e-7;
int sgn(double d){
	return d<-eps?-1:d>eps;
}

struct P{
	int id; double x;
	P(){}
	P(int id, double x):id(id),x(x){}
	bool operator <(const P& p)const{
		if (sgn(x-p.x)!=0) return x<p.x;		
		return id%2<p.id%2;
	}
};

int solve(){
	int ret=0;
	vector<P> v;
	rep(i, n){
		scanf("%d%d", &x, &y);
		if (y<=d){
			double delta=sqrt(d*d*1.-y*y);
			v.pb(P(i*2, x-delta));
			v.pb(P(i*2+1, x+delta));
		}
		else
			ret=-1;
	}
	if (ret==-1) return ret;
	sort(v.begin(), v.end());
	stack<int> s;
	vector<bool> done(n, false);	

	rep(i, n*2){
		k=v[i].id/2;
		if (v[i].id%2==0) s.push(k);
		else{
		   	if(!done[k]){
				while (!s.empty()){
					done[s.top()]=true;
					s.pop();
				}
				ret++;
			}
		}
	}
	return ret;
}

int main(){
	int test=0;
	while (~scanf("%d%d", &n, &d) && n+d){
		printf("Case %d: %d\n", ++test, solve());
	}
	return 0;
}
