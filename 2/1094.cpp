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
#define pb push_back
#define fill(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator

#define N 26
#define M 100000

struct P{
	int x,y;
};

int i,j,k,m,n,l;
P e[M+10];
int inDeg[N+10], inDegBak[N+10];
vi a[N+10];
int v[N+10], inS[N+10];
int Idx;

int get(){
	char ch;
	do ch=getchar();
	while (!isupper(ch));
	return ch-'A';
}

bool find_cycle(int i){
	v[i]=++Idx;
	inS[i]=true;
	rep(j, sz(a[i])){
		int k=a[i][j];
		if (!v[k]){
		   	if (find_cycle(k)) return true;
		}
		else if (inS[k]) return true;
	}
	inS[i]=false;
	return false;
}

void gao(){
	fill(inDeg, 0);
	rep(i, n) a[i].clear();

	rep(i, m){
		a[e[i].x].pb(e[i].y);
		inDeg[e[i].y]++;
		
		memcpy(inDegBak, inDeg, sizeof(inDeg));
		vi ans;
		
		fill(v, 0);
		fill(inS, 0);
		Idx=0;
		rep(j, n) if (!v[j] && find_cycle(j)){
			printf("Inconsistency found after %d relations.\n", i+1); 
			return; 
		}	

		fill(v, 0);
		
		rep(w, n){
			vi k;

			rep(j, n) if (!inDeg[j] && !v[j])
				k.pb(j);	
			if (sz(k)==0){
				printf("Inconsistency found after %d relations.\n", i+1); 
				return;
			}
			else if (sz(k)==1){
				int l=k[0];
				ans.pb(l), v[l]=true;
				rep(j, sz(a[l]))
					inDeg[a[l][j]]--;
			}
			else{
				break;
			}		
		}

		if (sz(ans)==n){
			printf("Sorted sequence determined after %d relations: ", i+1);
			rep(j, n) putchar('A'+ans[j]);
			puts(".");
			return;
		}
		memcpy(inDeg, inDegBak, sizeof(inDeg));
	}
	puts("Sorted sequence cannot be determined.");
}

int main(){
	freopen("input.txt", "r", stdin);
	while (~scanf("%d%d", &n, &m) && n+m){
		rep(i, m) e[i].x=get(), e[i].y=get();
		gao();
	}
	return 0;
}


