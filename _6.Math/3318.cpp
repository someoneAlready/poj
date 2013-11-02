#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <ctime>
#include <cctype>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define pb push_back
#define N 500
#define e 1000

int i,j,k,m,n,l;

struct Mat{
	ll a[N+10][N+10];
	void in(){
		rep(i, n) rep(j, n) scanf("%lld", &a[i][j]);
	}
};

struct Mat2{
	ll a[N+10];
	Mat2(){ clr(a, 0); }
	Mat2 operator *(const Mat& mt)const{
		Mat2 ret;
		rep(j, n) rep(k, n)
			ret.a[j]+=a[k]*mt.a[k][j];
		return ret;
	}
	bool operator ==(const Mat2& mt)const{
		rep(i, n) if (a[i]!=mt.a[i]) return false;
		return true;
	}
};

Mat2 X;
Mat A, B, C;

int main(){
	scanf("%d", &n);
	{
		A.in(), B.in(), C.in();
		
		rep(i, n) X.a[i]=rand()%e;

		Mat2 ret=(X*A)*B, ret2=(X*C);

		if (ret==ret2) puts("YES");
		else puts("NO");
	}
	return 0;
}
