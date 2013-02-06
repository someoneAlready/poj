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
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 2000

int i,j,k,m,n,l;
char s[N+10][10];
char f[N+10][N+10];
bool v[N+10];
int dist[N+10];

struct P{
	int to, w;
	P(){}
	P(int to, int w):to(to),w(w){}
	bool operator<(const P& p)const{
		if (w!=p.w) return w<p.w;
		return to<p.to;
	}
};

int prim(){
	set<P> st;
	fill(v, v+n, false);	
	fill(dist, dist+n, (int)1e8);
	
	st.insert(P(0,0)), v[0]=false, dist[0]=0;
	int ret=0;

	while (st.size()){
		set<P>::itr it=st.begin();
		int i=it->to; ret+=it->w;
		st.erase(it);

		v[i]=true;
		rep(k, n) if (!v[k]) if (f[i][k]<dist[k]){
			it=st.find(P(k,dist[k]));
			if (it!=st.end()) st.erase(it);
			dist[k]=f[i][k], st.insert(P(k, dist[k]));
		}
	}
	return ret;
}

int diff(char *s, char *t){
	int n=strlen(s), ret=0;
	rep(i, n) if (s[i]!=t[i]) ret++;
	return ret;
}

int main(){
	while (~scanf("%d", &n) && n){
		rep(i, n) scanf("%s", s[i]);
		rep(i, n)
			repf(j, i+1, n-1) f[i][j]=f[j][i]=diff(s[i],s[j]);

		printf("The highest possible quality is 1/%d.\n", prim());
	}
	return 0;
}


