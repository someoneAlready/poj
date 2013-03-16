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
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
template <class T> void checkmax(T &t, T x){if (x > t) t = x;}
template <class T> void checkmin(T &t, T x){if (x < t) t = x;}
template <class T> void _checkmax(T &t, T x){if (t == -1 || x > t) t = x;}
template <class T> void _checkmin(T &t, T x){if (t == -1 || x < t) t = x;}
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define fill(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>

int i,j,k,m,n,l;
char s[100];
struct P{
    int c, e;
    P(){}
    P(int c, int e):c(c),e(e){}
    bool operator <(const P&p)const{ return e>p.e; }                
};

int str2Digit(char *s){
    int ret=0, n=strlen(s);
    rep(i, n) ret=ret*10+s[i]-'0';
    return ret;
}

vp gao(){
    vp ret;
    while (~scanf("%s", s) && strcmp(s, "END")!=0){
        if (strcmp(s, "LOOP")==0){
            scanf("%s", s);
            if (strcmp(s, "n")==0){
                vp ret2=gao();
                rep(i, sz(ret2)) ret.pb(P(ret2[i].c, ret2[i].e+1));
            }
            else{
                int k=str2Digit(s);
                vp ret2=gao();
                rep(i, sz(ret2)) ret.pb(P(ret2[i].c*k, ret2[i].e));
            }
        }
        else if (strcmp(s, "OP")==0){
            scanf("%s", s);
            if (strcmp(s, "n")==0) ret.pb(P(1,1));
            else ret.pb(P( str2Digit(s), 0));
        }
    }
    return ret;    
}

int main(){
    int tests;
    scanf("%d", &tests);
    repf(test, 1, tests){        
        scanf("%s", s);
        vp ret=gao(), a;
        sort(all(ret));
        rep(i, sz(ret)){
            if (!i || ret[i].e!=ret[i-1].e) a.pb(ret[i]);
            else a[sz(a)-1].c+=ret[i].c;
        }
        
        printf("Program #%d\n", test);
        printf("Runtime = ");
        bool first=true;
        rep(i, sz(a)){
            if (a[i].c<=0) continue;
            if (first) first=false;
            else putchar('+');
            if (a[i].e==0) printf("%d", a[i].c);
            else{
                if (a[i].c!=1) printf("%d*", a[i].c);
                printf("n");
                if (a[i].e!=1) printf("^%d", a[i].e);
            }
        }
        if (first) putchar('0');
        printf("\n\n"); 
    }
    
    return 0;
}

