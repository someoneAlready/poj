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
#define N 32000
#define M 15000

struct P{
    int x, y;
    void input(){ scanf("%d%d", &x, &y); }
    bool operator <(const P &p)const{ return x<p.x; }
};

#define lson i*2, x, z
#define rson i*2+1, z+1, y
template<int SZ>
class SegTree{
    int a[SZ+10];
public:   
    void clear(){ clr(a, 0); }
    void ins(int i, int x, int y, int p){
        a[i]++;
        if (x==y) return;
        int z=mid(x, y);
        if (p<=z) ins(lson, p);
        else ins(rson, p);
    }
    int query(int i, int x, int y, int l, int r){
        if (x==l && y==r) return a[i];
        int z=mid(x, y);
        if (r<=z) return query(lson, l, r);
        else if (l>z) return query(rson, l, r);
        else return query(lson, l, z)+query(rson, z+1, r);
    }
};

int f[M+10];
int i,j,k,m,n,l;
P a[M+10];
SegTree<N*4+10> st;

int main(){
    while (~scanf("%d", &n)){
        int x=-1, y=-1;
        rep(i, n) 
            a[i].input(), _checkmin(x, a[i].y), _checkmax(y, a[i].y);
        sort(a, a+n);
        st.clear(), clr(f, 0);
        i=0, j=0;
        while (i<n){
            
            while (i<n-1 && a[i].x==a[i+1].x) i++;
            repf(k, j, i) st.ins(1, x, y, a[k].y);
            repf(k, j, i) f[st.query(1, x, y, x, a[k].y)]++;
            j=++i;
        }
        repf(i, 1, n) printf("%d\n", f[i]);
    }
    return 0;
}

