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
#define N 100000

struct P{
    int i, loc, times;
    P(){}
    P(int i, int loc, int times):i(i),loc(loc),times(times){}
    bool operator <(const P&p)const {return i<p.i; }
};

int i,j,k,m,n,l;
int a[N+10];
P s[N+10];

#define lson i*2, x, z
#define rson i*2+1, z+1, y
template<int SZ>
class SegTree{
    int a[SZ*4+10];
public:
    void clear(){ clr(a, 0); }
    void ins(int i, int x, int y, int k, int val){
        if (x==y){
            a[i]=val;
            return;
        }
        int z=mid(x, y);
        if (k<=z) ins(lson, k, val);
        else ins(rson, k, val);
        a[i]=max(a[i*2], a[i*2+1]);
    }
    int qry(int i, int x, int y, int l, int r){
        if (x==l && y==r){
            return a[i];
        }
        int z=mid(x, y);
        if (r<=z) return qry(lson, l, r);
        else if (l>z) return qry(rson, l, r);
        else return max( qry(lson, l, z), qry(rson, z+1, r) );
    }
};

SegTree<N> st;



int main(){
    while (~scanf("%d", &n) && n){
        scanf("%d", &m);
        repf(i, 1, n) scanf("%d", &a[i]);
        int sCnt=0;
        repf(i, 1, n) 
            if (i==1 || a[i]!=a[i-1]) s[++sCnt]=P(a[i], i, 1);
            else s[sCnt].times++;
              
        st.clear();  
        repf(i, 1, sCnt) st.ins(1, 1, sCnt, i, s[i].times);
        
        while (m--){
            scanf("%d%d", &i, &j);
            int x=lower_bound(s+1, s+1+sCnt, P(a[i],0,  1))-s;
            int y=lower_bound(s+1, s+1+sCnt, P(a[j],0, 1))-s;

            int ans;
            if (x==y) ans=j-i+1;
            else ans=max(s[x].times-(i-s[x].loc), j-s[y].loc+1);
            if (x+1<=y-1) checkmax(ans, st.qry(1, 1, sCnt, x+1, y-1));
            printf("%d\n", ans);

        }
    }
    return 0;
}

