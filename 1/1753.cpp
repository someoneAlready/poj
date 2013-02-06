#include <iostream>
#include <queue>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

int i,j,k,m,n,l;
char s[100];
bool v[(1<<16)+10];

struct P{
	bool it[4][4];
	int dep;
	int val(){
		int ret=0;
		for (int i=0; i<4; ++i)
			for (int j=0; j<4; ++j)
				ret=ret*2+it[i][j];
		return ret;
	}

	bool input(){
		int i=0;
		dep=0;
		while (gets(s)!=NULL){
			if (strchr("bw", s[0])==NULL) continue;
			for (int j=0; j<4; j++)
				it[i][j]= (s[j]=='w'?0:1);
			i++;
			if (i==4) {
		   	   return true;
			}
		}
		return false;
	}
}a;

int dir[5][2]={{0,0}, {-1,0}, {1,0}, {0,-1}, {0,1}};
P gao(P a, int i, int j){
	P b=a;
	for (int d=0; d<5; ++d){
		int x=i+dir[d][0], y=j+dir[d][1];
		if (x>=0 && y>=0 && x<4 && y<4) b.it[x][y]=!b.it[x][y];
	}
	b.dep++;
	return b;
}

void gao(){
	memset(v, 0, sizeof(v));
	queue<P> q;
	P b;
	q.push(a);
	if (a.val()==0 || a.val()==((1<<16)-1)){
	   cout<<0<<endl;	
	   return;
	}
	v[a.val()]=true;
	while (!q.empty()){
		a=q.front(), q.pop();
		for (int i=0; i<4; ++i)
			for (int j=0; j<4; ++j){
				b=gao(a, i, j);
				if (!v[b.val()]){
					q.push(b);
					v[b.val()]=true;
					if (b.val()==0 || b.val()==((1<<16)-1)){
						cout<<b.dep<<endl;
						return;
					}
				}
			}
	}
	cout<<"Impossible"<<endl;
}

int main(){
	while (a.input()){
		gao();
	}
	return 0;
}
