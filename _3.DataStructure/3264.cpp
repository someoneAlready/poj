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
#define N 50000

int high, low;

#define lson i*2, x, z
#define rson i*2+1, z+1, y
template<int SZ>
class SegTree{
    int H[SZ*4+10], L[SZ*4+10];
public:
    void clear(){ fill(H, H+SZ*4+10, 0), fill(L, L+SZ*4+10, INT_MAX); }
    void ins(int i, int x, int y, int k, int val){
        if (x==y){
            H[i]=L[i]=val;
            return;
        }
        int z=mid(x, y);
        if (k<=z) ins(lson, k, val);
        else ins(rson, k, val);
        H[i]=max(H[i*2], H[i*2+1]);
        L[i]=min(L[i*2], L[i*2+1]);
    }
    void qry(int i, int x, int y, int l, int r){
        if (x==l && y==r){
            _checkmax(high, H[i]), _checkmin(low, L[i]);            
            return;
        }
        int z=mid(x, y);
        if (r<=z) qry(lson, l, r);
        else if (l>z) qry(rson, l, r);
        else qry(lson, l, z), qry(rson, z+1, r);
    }
};

int i,j,k,m,n,l;
SegTree<N> st;
int a[N+10];

int main(){
    while (~scanf("%d%d", &n, &m)){
        st.clear();
        repf(i, 1, n) scanf("%d", &a[i]), st.ins(1, 1, n, i, a[i]);
        while (m--){
            scanf("%d%d", &i, &j);
            high=low=-1;
            st.qry(1, 1, n, i, j);
            printf("%d\n", high-low);
        }
    }
    return 0;
}

