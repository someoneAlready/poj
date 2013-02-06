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
#define N 100

int i,j,k,m,n,l;
int f[N+10][N+10];

int gao(int k){
	int ret=0;
	repf(i, 1, n){
		if (f[k][i]==-1) return -1;
		ret=max(ret, f[k][i]);
	}
	return ret;
}

int main(){
	while (~scanf("%d", &n) && n){
		memset(f, -1, sizeof(f));
		repf(i, 1, n){
			scanf("%d", &l);
			while (l--){
				scanf("%d%d", &j, &k);
				if (f[i][j]==-1 || f[i][j]>k)
					f[i][j]=k;
			}
		}
		repf(i, 1, n) f[i][i]=0;
		repf(k, 1, n)
			repf(i, 1, n) if (f[i][k]!=-1)
				repf(j, 1, n) if (f[k][j]!=-1)
					if (f[i][j]==-1 || f[i][k]+f[k][j]<f[i][j])
						f[i][j]=f[i][k]+f[k][j];
		pair<int,int> ans=make_pair(1, gao(1));
		repf(i, 2, n){
			int k=gao(i);
			if (k!=-1)
				if (ans.second==-1 || k<ans.second)
					ans=make_pair(i, k);
		}
		cout<<ans.first<<' '<<ans.second<<endl;
	}	
	return 0;
}


