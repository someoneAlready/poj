#include <iostream>
#include <algorithm>
#include <queue>
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
#define pb push_back
#define sz(a) ((int)(a).size())
#define N 1000
#define M 26
#define Q 100000

int i,j,k,m,n,l;
char a[N+10][N+10];

struct P{
    int x, y;
    P(){}
    P(int x, int y):x(x),y(y){}
    bool ok(){
        return x>=0 && y>=0 && x<n && y<n;
    }
    char e(){return tolower(a[x][y]); }
    P operator +(const P&p)const{return P(x+p.x, y+p.y); }
    bool operator ==(const P&p)const{ return x==p.x && y==p.y; }
};

P d[4] = {P(-1, 0), P(0, 1), P(1, 0), P(0, -1)};
//            0        1        2        3
// +1: turn right;   -1: turn left

struct S{
    int dir;
    bool delay, alive;
    P q[Q+10];
    int head, tail;
    void clear(){
        head = 1;
        tail = 0;
        delay=alive=0;
    }
    bool move(char c, int k){
        P x = q[tail] + d[k];

        if (x.ok() && x.e()=='.'){
            a[q[head].x][q[head].y] = '.';
            head = (head+1)%Q;
            a[q[tail].x][q[tail].y] = c;
            tail = (tail+1)%Q;
            q[tail] = x;
            a[x.x][x.y] = toupper(c);
 
            dir = k;
            return true;
        }
        return false;
    }
    void move(char c){
        if (delay)
            delay = 0;
        else{
            if (move(c, dir)) return;
            if (move(c, (dir+1)%4)) return;
            if (move(c, (dir+3)%4)) return;
            delay = 1;
        }
    }
};
S s[M];

void gao(P p, int i){
    P pre(-1, -1);
    s[i].alive = 1;
    stack<P> stk;
    
    while (1){
        stk.push(p);
        bool f = 1;
        rep(k, 4){
            P q = p + d[k];
            if (q.ok() && !(q==pre) && q.e()==(i+'a')){
                pre = p, p = q; 
                if (sz(stk)==1) s[i].dir = (k+2)%4;
                f = 0;
                break;
            }
        }
        if (f) break;
    }
    while (sz(stk)) s[i].tail=(s[i].tail+1)%Q, s[i].q[s[i].tail] = stk.top(),  stk.pop();
    
}

int main(){
    scanf("%d%d", &n, &m);
        rep(i, n) rep(j, n){
            a[i][j]=getchar();
            while (!isalpha(a[i][j]) && strchr(".#", a[i][j])==NULL)
                a[i][j] = getchar();
        }
        rep(i, M) s[i].clear();
        rep(i, n) rep(j, n) if (isupper(a[i][j])){
            gao(P(i,j), a[i][j]-'A');
        }
        while (m--){
            rep(i, M) if (s[i].alive) s[i].move(i+'a');
        }
        rep(i, n) puts(a[i]);

    return 0;
}
