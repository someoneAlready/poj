#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define pb push_back

#define S 200
#define A 50
#define C 50

int i,j,k,m,n,l;
char s[S*2+10], ups[S*2+10];
char upc[C+10][2][S+10], c[C+10][2][S+10], a[A+10][2][S+10];
bool v[A+10];

void gao(char *u, char *v){
	int n =strlen(s);
	int x = 0, j=0, k=0;
	rep(i, n) if (s[i]=='"')
		x++;
	else if (x==1) u[j++]=s[i];
	else if (x==3) v[k++]=s[i];
	u[j]=0, v[k]=0;
}

int main(){

	scanf("%d%d\n", &n, &m);
	rep(i, n){
		gets(s);
		gao(c[i][0], c[i][1]);
		int x=strlen(c[i][0]), y=strlen(c[i][1]);
		memcpy(upc[i][0], c[i][0], sizeof(c[i][0]));
		memcpy(upc[i][1], c[i][1], sizeof(c[i][1]));		
		rep(j, x) upc[i][0][j] = toupper(upc[i][0][j]);
		rep(j, y) upc[i][1][j] = toupper(upc[i][1][j]);
	}
	rep(i, m){
		gets(s);
		gao(a[i][0], a[i][1]);
	}
	while (gets(s)){
		if (strcmp(s, "#")==0){
			puts(s);
		   	clr(v, 0); continue;
		}
		else{
			int l=strlen(s);
                        
            memcpy(ups, s, sizeof(s));
            rep(i, l) ups[i] = toupper(ups[i]);

			rep(i, l){
				bool f=0;
				rep(j, n)
					if (strstr(s+i, c[j][0])==s+i){
						printf("%s", c[j][1]), f=1;
						i += strlen(c[j][0])-1;
						break;
					}
					else if(strstr(s+i, upc[j][0])==s+i){
						printf("%s", upc[j][1]), f=1;
						i += strlen(upc[j][0])-1;
						break;                        
                    }
                    else if (strstr(s+i+1,c[j][0]+1)==s+i+1 && (s[i])==toupper(c[j][0][0])){
                        printf("%c%s", toupper(c[j][1][0]), c[j][1]+1), f=1;
						i += strlen(upc[j][0])-1;
						break;                                                
                    }
                    
				if (f) continue;
				rep(j, m) if (!v[j] && strstr(s+i, a[j][0])==s+i){
					printf("%s (%s)", a[j][1], a[j][0]), v[j]=1;
					i += strlen(a[j][0])-1;
					f = 1;
					break;
				}
				if (!f) putchar(s[i]);
			}
			puts("");
		}
	}

	return 0;
}


