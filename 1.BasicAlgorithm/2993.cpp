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
#define N 8

const char line[]="+---+---+---+---+---+---+---+---+";
int i,j,k,m,n,l;
char a[N+10][N+10], c;
char s[1000];

void gao(int flag){
	char *t=s+7;
	n=strlen(t);
	t[n++]=',';
	rep(i, n){
		if (t[i+3]==',')
			c=t[i], ++i;
		else c='p';
		if (flag) c=toupper(c);
		else c=tolower(c);
//		cout<<c<<' '<<t[i]<<' '<<t[i+1]<<endl;
		int x=9-(t[i+1]-'0'), y=t[i]-'a'+1;
		a[x][y]=c;
		i+=2;
	}
}

int main(){
	gets(s); gao(1);
	gets(s); gao(0);
	repf(i, 1, 8){
		puts(line);
		repf(j, 1, 8){
			putchar('|');
			c=(i+j)%2?':':'.';
			printf("%c%c%c",c,(a[i][j]?a[i][j]:c),c);
		}
		printf("|\n");
	}
	puts(line);
	return 0;
}


