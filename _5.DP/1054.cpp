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
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define N 5000

int i,j,k,m,n,l;

template<class T>
T gcd(T a, T b){ return b==0?a:gcd(b, a%b); }

struct P{
    int x, y;
    P(){}
    P(int x, int y):x(x),y(y){}
    void input(){ scanf("%d%d", &x, &y); }
    P operator +(const P&p)const { return P(x+p.x, y+p.y); }    
    P operator -(const P&p)const { return P(x-p.x, y-p.y); }
    P operator *(const int &k)const {return P(k*x, k*y); }
    bool operator!=(const P&p)const{ return x!=p.x || y!=p.y; }
    bool operator<(const P&p)const{ return x!=p.x?x<p.x:y<p.y; }
    bool ok(){ return x>0 && y>0 && x<=n && y<=m; }
    void out(){ cout<<x<<' '<<y<<endl; }
};

P a[N+10];
bool v[N+1][N+1];

int main(){
 //   while (~scanf("%d%d", &n, &m)){
        scanf("%d%d", &n, &m);
        scanf("%d", &l);
        rep(i, l) a[i].input(), v[a[i].x][a[i].y]=1;
        sort(a, a+l);
        

        
        int ans=2;    
        rep(i, l) repf(j, i+1, l-1){
            P p=a[j]-a[i];
            if ( (a[i]-p).ok() ) continue;
            P q=a[j]+p;
            k=2;
            while (q.ok() && v[q.x][q.y]) q=q+p, k++;
            if ( !q.ok()) checkmax(ans, k);
        }
        if (ans<3) puts("0");
        else printf("%d\n", ans);
  //  }
    return 0;
