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
#define N 2000

int i,j,k,m,n,l;
char s[N+10];
struct bigNum{
	int it[N+10];
	bigNum(){
		fill(it, 0), it[0]=1;		
	}
	bigNum(int n){
		fill(it, 0);
		while (n){
			it[++it[0]]=n%10;
			n/=10;
		}
		if (!it[0]) it[0]=1;
	}
	bigNum(char *s){
		fill(it, 0);
		int n=strlen(s);
		repd(i, n-1, 0)
			it[++it[0]]=s[i]-'0';
	}
	bigNum operator *(const bigNum & b){
		bigNum ret;
		ret.it[0]=it[0]+b.it[0];
		repf(i, 1, it[0]) repf(j, 1, b.it[0])
			ret.it[i+j-1]+=it[i]*b.it[j];
		repf(i, 1, ret.it[0])
			ret.it[i+1]+=ret.it[i]/10, ret.it[i]%=10;
		while (ret.it[0]>1 && ret.it[ret.it[0]]==0) ret.it[0]--;
		return ret;
	}
	bool operator >(const bigNum & b){
		if (it[0]!=b.it[0]) return it[0]>b.it[0];
		repd(i, it[0], 1) if (it[i]!=b.it[i])
			return it[i]>b.it[i];
		return false;
	}
	void out(){
		repd(i, it[0], 1) printf("%d", it[i]);
		putchar('\n');
	}
};

bigNum pow(int x, int y){
	bigNum ret(1);
	rep(i, y) ret=ret*bigNum(x);
	return ret;
}

int main(){
	while (~scanf("%d%s", &n, s)){
		bigNum S(s);
		int x=1, y=INT_MAX-2;
		while (x!=y){
			int z=mid(x+1, y);
			if (pow(z, n)>S) y=z-1; 
			else x=z;
		}
		printf("%d\n", x);
	}
	return 0;
}

