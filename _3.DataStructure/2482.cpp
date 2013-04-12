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
    int x, c;
    ll y, qy;
    void input(){ scanf("%d%lld%d", &x, &y, &c); }
    bool operator <(const P &p)const{
        if (x==p.x) return y<p.y;
        return x<p.x;
    }
    void out(){ cout<<x<<' '<<y<<endl;}
};

#define lson i*2, x, z
#define rson i*2+1, z+1, y
template<int SZ>
class SegTree{
public:    
    int sum[SZ*4+10], pre[SZ*4+10];
    void clear(){ clr(sum, 0), clr(pre, 0); }
    void ins(int i, int x, int y, int k, int val){
        if (x==y){
            sum[i]+=val, pre[i]+=val;
            return;
        }
        int z=mid(x, y);
        if (k<=z) ins(lson, k, val);
        else ins(rson, k, val);
        
        sum[i]=sum[i*2]+sum[i*2+1];
        pre[i]=max(pre[i*2], sum[i*2]+pre[i*2+1]);
    }
};

int i,j,k,m,n,l;
int x, y;
P a[N+10];
ll s[N*2+10];
SegTree<N*2+10> st;

void gao(){
    vector<ll> v; s[0]=0;
    rep(i, n) a[i].qy=a[i].y+y;
    rep(i, n) v.pb(a[i].y), v.pb(a[i].qy);
    sort(all(v));
    rep(i, sz(v)) if (i==0 || v[i]!=v[i-1])
        s[++s[0]]=v[i];
    rep(i, n) 
        a[i].y=lower_bound(s+1, s+1+s[0], a[i].y)-s,
        a[i].qy=lower_bound(s+1, s+1+s[0], a[i].qy)-s;
}

int main(){
    while (~scanf("%d%d%d", &n, &x, &y)){
        rep(i, n) a[i].input();        
        sort(a, a+n);
        
        gao();
        st.clear();
        int ans=-1, j=0;
        rep(i, n){
            while (a[i].x-a[j].x>=x){
                st.ins(1, 1, s[0], a[j].y, -a[j].c);
                st.ins(1, 1, s[0], a[j].qy, a[j].c);                
                j++;
            }

            st.ins(1, 1, s[0], a[i].y, a[i].c);
            st.ins(1, 1, s[0], a[i].qy, -a[i].c);
            _checkmax(ans, st.pre[1]);
        }
        printf("%d\n", ans);
    }
    return 0;
}

