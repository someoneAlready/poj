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

struct node{
	int to, l, t;
	node *next;
};

struct E{
	int to, w;
	E(){}
	E(int to, int w):to(to),w(w){}
};

int i,j,k,m,n,l,t;
node *a[N+10];
node pool[M+10];
vector<E> L[N+10], T[N+10];
int ll[N+10], tt[N+10];
int idx;

void add(int i, int j, int l, int t){
	node *p=pool+idx++;
	p->to=to, p->l=l, p->t=t, p->next=a[i];
	a[i]=p;
}


void dfs(int i, int t, int l){
	for (node *p=a[i]; p; p=p->next){
	}
}

void gao(vector<E> a[N+10], int d[N+10]){
	queue<int> q;
	
}


int main(){
	scanf("%d%d%d", &t, &n, &m);
	repf(i, 1, n) a[i]=NULL;
	while (m--) 
		scanf("%d%d%d%d", &i, &j, &k, &l), add(i, j, k, l),
		L[j].pb(E(i, k)), T[j].pb(E(i, l));
	gao(L, ll), gao(T, tt);

	dfs(1, t, 0);
	return 0;
}


