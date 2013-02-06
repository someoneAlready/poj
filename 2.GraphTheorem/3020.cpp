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
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define fill(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 100
#define g(i,j) ((i&1)^(j&1)) 
#define w(i,j) (i*m+j)

int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int i,j,k,m,n,l;
int a[N+10][N+10];
vi e[N*N+10];
int f[N*N+10], v[N*N+10];

bool find(int i){
	rep(j, sz(e[i])){
		int k=e[i][j];
		if (!v[k]){
			v[k]=1;
			if (f[k]==-1 || find(f[k])){
				f[k]=i;
				return true;
			}
		}
	}
	return false;
}

int main(){
	int tests;
	scanf("%d", &tests);
	while (tests--){
		int tot=0;
		scanf("%d%d", &n, &m);
		rep(i, n) rep(j, m){
			char ch=getchar();
			while (strchr("*o", ch)==NULL) ch=getchar();
			a[i][j]=ch;
			if (a[i][j]=='*') tot++;
		}	
		rep(i, n*m) e[i].clear();

		rep(i, n) rep(j, m) if (a[i][j]=='*' && g(i,j)){ 
			rep(k, 4){
				int x=i+dir[k][0], y=j+dir[k][1];
				if (x>=0 && y>=0 && x<n && y<m && a[x][y]=='*')
					e[w(i,j)].pb(w(x,y));
			}			
		}
		int hungray=0;
		fill(f, -1);
		rep(i, n) rep(j, m) if (g(i,j)){
			fill(v, 0);
			if (find(w(i,j))) hungray++;
		}
		cout<<tot-hungray<<endl;
	}
	return 0;
}


