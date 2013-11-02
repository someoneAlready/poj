#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define pb push_back
#define N 10

ll i,j,k,m,n,l;
ll ten[N+10];
ll f[N+10];

ll gao(ll n){
	vi v;
	ll ret=0;
	if (n==0) v.pb(0);

	while (n){
		v.pb(n%10), n/=10;
	}
	int k=0;
	repd(i, sz(v)-1, 0){
		repf(j, 0, v[i]-1){
			if (j==0) k++;
			
			ret+=ten[i]*k;
			ret+=f[i];

			if (j==0) k--;
		}
		if (v[i]==0) k++;
	}
	repf(i, 1, sz(v)-1) ret-=ten[i];
	return ret;
}

int main(){
	ten[0]=1;
	repf(i, 1, N) ten[i]=ten[i-1]*10;

	repf(i, 1, N){
		f[i]=10*f[i-1]+ten[i-1];
	}
	while (~scanf("%lld%lld", &m, &n) && m>=0 && n>=0){
		cout<<gao(n+1)-gao(m)<<endl;
	}
	return 0;
}
