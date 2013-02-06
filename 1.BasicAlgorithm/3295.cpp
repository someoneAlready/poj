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
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define pb push_back
#define sz(a) ((int)(a).size())
#define mid(x, y) ((x+y)/2)
#define fill(a, b) memset(a, b, sizeof(a))
#define N 100

int i,j,k,m,n,l;
char s[N+10];
map<char,int>mp;

int gao(int &k){
	++k;
	if (strchr("pqrst",s[k])!=NULL) return mp[s[k]];
	switch(s[k]){
		case 'K':
			return gao(k) & gao(k);
			break;
		case 'A':
			return gao(k) | gao(k);		
			break;
		case 'N':
			return 1-gao(k);
			break;
		case 'C':
			return (1-gao(k) | gao(k));
			break;
		case 'E':
			return 1- (gao(k) ^ gao(k));
	}
		
}

bool gao(){
	mp.clear();
	rep(p, 2) rep(q, 2) rep(r, 2) rep(s, 2) rep(t, 2){
		mp['p']=p, mp['q']=q, mp['r']=r, mp['s']=s, mp['t']=t;
		k=-1;
	   	if (!gao(k)) return false;
	}
	return true;
}
int main(){
	while (gets(s)!=NULL){		
		if (s[0]=='0') break;
		if (gao()) puts("tautology");
		else puts("not");
	}
	return 0;
}


