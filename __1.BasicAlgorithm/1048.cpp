#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define pb push_back
#define N 100
#define M 10000

struct P{
    bool val;
    int a, b;
    bool oa, ob, oc, type;
};

int i,j,k,m,n,l, len[N+10];
char s[N+10][N+10], t[N+10];
bool first=1;

int d[4][2]={-1, 0, 1, 0, 0, 1, 0, -1};
char cc[5]="||--";

int E, idx=M;
P a[M+10];

inline bool next(int &i, int &j, int &pi, int &pj){
    rep(k, 4){
        int x=i+d[k][0], y=j+d[k][1];
        if (x<n && y<len[x] && !isspace(s[x][y]) && !(x==pi && y==pj)){
            if (s[x][y]=='|' || s[x][y]=='-')
                if (s[x][y]!=cc[k]) continue;
                
            if (s[i][j]=='|' && !(k<=1)) continue;
            else if (s[i][j]=='-' && !(k==2 || k==3)) continue;
            
            pi=i, pj=j;
            i=x, j=y; 
            return 1;
        }
    }    
    return 0;
}

int gao(int i, int j, int pi, int pj){

    while(1){
        if (isupper(s[i][j])){
            return s[i][j]-'A';
        }
        else{
            if (s[i][j]=='o')
                a[idx].oc=1, j--;
            if (s[i][j]==')' || s[i][j]=='>'){
                a[idx].type = (s[i][j]==')');
                int Idx = idx--;
                
                
                int x=i-1, y=j-3, u=i-1, v=j-2;
                if (s[x][y]=='o')
                    a[Idx].oa=1, next(x, y, u, v);
               
                
                a[Idx].a = gao(x, y, u, v);
                
                x=i+1, y=j-3, u=i+1, v=j-2;
                if (s[x][y]=='o')
                    a[Idx].ob=1, next(x, y, u, v);
                a[Idx].b = gao(x, y, u, v);
                
                return Idx;
            }
        }
        
       // cout<<i<<' '<<j<<' '<<pi<<' '<<pj<<endl;
        if (!next(i, j, pi, pj)) return 26;

    }
}

void gao(){
    clr(a, 0);
    idx=M;
    rep(i, n) len[i]= strlen(s[i]);
    a[26].val = 1;
    
    rep(i, n){
        rep(j, len[i]) if (s[i][j]=='?'){
            
            E = gao(i, j, -1, -1);
            return;
        }
    }
}

bool input(){
    n=0;
    while (gets(s[n])){
        if (s[n][0]=='*') break;
        ++n;
    }
    return n!=0;
}

void get(int i){
    if (i<26) return;
    get(a[i].a), get(a[i].b);
    bool x=a[a[i].a].val, y=a[a[i].b].val;
    if (a[i].oa) x=!x;
    if (a[i].ob) y=!y;
    if (a[i].type==1) a[i].val = (x&&y);
    else a[i].val = (x||y);
    if (a[i].oc) a[i].val = !a[i].val;
}

void output(){
    if (first) first=0;
    else puts("");
    while (gets(t)){
        if (t[0]=='*') break;
        if (!isdigit(t[i])) continue;
        rep(i, 26) a[i].val = (t[i]=='1');
        get(E);
        printf("%d\n", a[E].val?1:0);
    }
}

int main(){
    while (input())
        gao(), output();
    return 0;
}
