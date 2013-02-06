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

char str[]="KQRBNP";

struct P{
	int t,x,y;
	P(){}
	P(char c, int x, int y):x(9-x),y(y){
		c=toupper(c);
		t=strchr(str, c)-str;
	}
};

int i,j,k,m,n,l;
char t[100];
vector<P> W, B;

bool cmpW(P a, P b){
	if (a.t!=b.t) return a.t<b.t;
	if (a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}

bool cmpB(P a, P b){
	if (a.t!=b.t) return a.t<b.t;
	if (a.x!=b.x) return a.x>b.x;
	return a.y<b.y;
}

int main(){
	repf(i, 1, 8){
		gets(t), gets(t);
		char *s=t;
		repf(j, 1, 8){
			s=s+1;;
			while (*s!='|'){
				if (isupper(*s)) W.pb(P(*s, i, j));
				else if (islower(*s)) B.pb(P(*s, i, j));
				s++;
			}
		}
	}	
	gets(t);
	sort(W.begin(), W.end(), cmpW);
	sort(B.begin(), B.end(), cmpB);
	printf("White: "); 
	rep(i, sz(W)){
		if (i) putchar(',');
		if (W[i].t!=5) putchar(str[W[i].t]);
		printf("%c%d",W[i].y+'a'-1,W[i].x);
	}
	putchar('\n');

	printf("Black: ");
	rep(i, sz(B)){
		if (i) putchar(',');
		if (B[i].t!=5) putchar(str[B[i].t]);
		printf("%c%d", B[i].y+'a'-1,B[i].x);
	}
	putchar('\n');
	return 0;
}


