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
#define eps 1e-8
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
#define N 20
int sgn(double d){ return d<-eps?-1:d>eps; }

struct P{
	double x,y;
	P() {}
	P(double x, double y):x(x),y(y){}
	void input(){ scanf("%lf%lf", &x, &y); }
	P operator -(const P &p){ return P(x-p.x, y-p.y); }
	double operator *(const P &p){ return x*p.y-y*p.x; }
	bool operator <(const P &p)const{ return x<p.x; }
	void out(){ cout<<x<<' '<<y<<endl;}
};

P a[N*2+10];
int i,j,k,m,n,l;
double ans;
bool flag;

bool gao(P p1, P p2, P p3, P p4, P &c){
	double d1=(p2-p1)*(p3-p1), d2=(p2-p1)*(p4-p1);
	double d3=(p4-p3)*(p1-p3), d4=(p4-p3)*(p2-p3);
	int s1=sgn(d1), s2=sgn(d2), s3=sgn(d3), s4=sgn(d4);
	if (s1*s2>0 || s3*s4>0) return false;
	c=P((p3.x*d2-p4.x*d1)/(d2-d1), (p3.y*d2-p4.y*d1)/(d2-d1));
	return true;
}

void gao(P _p, P _q){
	double k=(_p.y-_q.y)/(_p.x-_q.x);
	rep(i, n-1){
		P p(a[i].x, k*(a[i].x-_p.x)+_p.y), q(a[i+1].x, k*(a[i+1].x-_p.x)+_p.y), c;
		if (sgn(p.y-a[i].y)>0 || sgn(p.y-a[i+n].y)<0) return;
		if (sgn(q.y-a[i+1].y)>0){
		   	gao(a[i], a[i+1], p, q, c), checkmax(ans, c.x);
			return;
		}
		else if (sgn(q.y-a[i+n+1].y)<0){
		   	gao(a[i+n], a[i+n+1], p, q, c), checkmax(ans, c.x);
			return;
		}
	}
	ans=a[n-1].x;
}

int main(){
	while (~scanf("%d", &n) && n){
		rep(i, n) a[i].input(), a[i+n]=P(a[i].x, a[i].y-1);

		ans=a[0].x;
		rep(i, 2*n) repf(j, i+1, 2*n-1) if (a[i].x!=a[j].x){
			gao(a[i], a[j]);
		}
		
		if (ans!=a[n-1].x) printf("%.2f\n", ans);
		else puts("Through all the pipe.");
	}
	return 0;
}


