#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define pb push_back

int i,j,k,m,n,l;
#define e 10000

struct Mat{
	int a[2][2];
	Mat(){ clr(a, 0); }
	Mat operator *(const Mat&m)const{
		Mat ret;
		rep(i, 2) rep(j, 2) rep(k, 2)
			ret.a[i][j]+=a[i][k]*m.a[k][j];
		rep(i, 2) rep(j, 2) ret.a[i][j]%=e;
		return ret;
	}
};

int main(){
	while (~scanf("%d", &n) && n!=-1){
		Mat a, x;
		rep(i, 2) a.a[i][i]=1;
		x.a[0][0]=x.a[0][1]=x.a[1][0]=1;

		while (n){
			if (n&1) a=a*x;
			x=x*x;
			n>>=1;
		}
		cout<<a.a[0][1]<<endl;
	}
	return 0;
}
