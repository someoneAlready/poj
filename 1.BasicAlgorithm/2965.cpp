#include <iostream>
#include <queue>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

const int N=(1<<16)-1;

struct F{
	int x,y,k;
	F(){}
	F(int x,int y,int k):x(x),y(y),k(k){}
};

typedef pair<int,int> pii;

int i,j,k,m,n,l;
char s[100];
bool v[N+10];
F f[N+10];
int r[4]={0xf, 0xf0, 0xf00, 0xf000};
int c[4]={0x1111, 0x2222, 0x4444, 0x8888};
int tot;

struct P{
	bool it[4][4];	
	int dep;
	int val(){
		int ret=0;
		for (int i=3; i>=0; --i)
		   for (int j=3; j>=0; --j)	ret=ret*2+it[i][j];
		return ret;
	}

	bool input(){
		int i=0, j=0;
		dep=0;

		int ch;
		while ((ch=getchar())!=EOF){
			while (ch!='+' && ch!='-'){
				ch=getchar();
				if (ch==EOF) return false;
			}
			it[i][j++]=(ch=='-'?1:0);
			if (j==4){
				i++;
				j=0;
				if (i==4) return true;
			}
		}
		return false;
	}
}a;


void gao(){
	memset(v, 0, sizeof(v));
	queue<pii> q;
	while (!q.empty()) q.pop();
	
	k=a.val();
	q.push(make_pair(k, 0));
	v[k]=true;
	f[k]=F(-1,-1,-1);

	while (!q.empty()){
		pii k=q.front();
		q.pop();
		for (int i=0; i<4; ++i)
			for (int j=0; j<4; ++j){
				pii l=make_pair((k.first^r[i])^c[j]^(1<<(i*4+j)), k.second+1);
				if (!v[l.first]){
					v[l.first]=true;
					q.push(l);
					f[l.first]=F(i,j,k.first);
					if (l.first==N){
						printf("%d\n", l.second);
						int k=l.first;
						while (f[k].x!=-1){
							printf("%d %d\n", f[k].x+1, f[k].y+1);
							k=f[k].k;
						}
						return ;
					}
				}				
			}
	}
}

int main(){
//	while (a.input()){
	a.input();
		gao();
//	}
	return 0;
}
