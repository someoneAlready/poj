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
#define N 10000
#define M 26

struct P{
	int tp, k;	//0 num; 1 alpha; 2 inner node;
	P(){}
	P(int tp, int k):tp(tp), k(k){}
};

int i,j,k,m,n,l,x;
vector<P> e[N+10];
double a[M+10][M+10];
char t[N+10], *s;

void dfs(int i, double p){
	cout<<i<<' '<<p<<endl;
	rep(j, sz(e[i])) if (e[i][j].tp==2) dfs(e[i][j].k, p/sz(e[i]));
	else if (e[i][j].tp==0) a[x][n]+=e[i][j].k*p;
	else a[x][e[i][j].k]-=p;
}

void getinfo(){
	clr(a, 0);
	for (x=0; x<n; ++x){
		rep(i, N) e[i].clear();
		gets(t); while (strlen(t)==0) gets(t);
		s=strchr(t, '(')+1;
		int m=strlen(s), k=0, flag=0;
		int idx=0; a[x][x]=1;
		rep(i, m) if (isdigit(s[i])){
		   	k=k*10+'0'; if (flag==0) flag=1;
		}
		else{
			if (flag!=0) e[idx].pb(P(0, flag*k)), flag=k=0;
			if (isalpha(s[i])) e[idx].pb(P(1, s[i]-'a'));
			else if (s[i]=='(') e[idx].pb(P(2, idx+1)), idx++;
			else if (s[i]==')') idx--;
			else if (s[i]=='-') flag=-1;
		}
		dfs(0, 1);
	}
}

int main(){
	int test=0;
	while (~scanf("%d", &n) && n){
		getinfo();
		rep(i, n){ rep(j, n+1) cout<<a[i][j]<<' ';
			cout<<endl;
		}
	}
	return 0;
}


