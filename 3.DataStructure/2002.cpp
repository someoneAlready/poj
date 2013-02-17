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
#define repd(i, a, b) for (int i=(a); i>=(b); --i
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define fill(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define N 1000

struct P{
    int x,y;
    P(){}
    P(int x, int y):x(x),y(y){}
    void input(){scanf("%d%d", &x, &y); }
    bool operator<(const P &p)const{
        return x==p.x?y<p.y:x<p.x;
    }
    bool operator==(const P &p)const{
        return (x==p.x) && (y==p.y);
    }
    P operator -(const P& p)const{
        return P(x-p.x, y-p.y);
    }
    void out(){
        cout<<x<<' '<<y<<endl;
    }
};

int i,j,k,m,n,l;
P a[N+10];

template<int SZ>
class Hash{
    int h[SZ+10];
public:
    void init(){fill(h, -1); }
    int gao(P &p){
        return ((ll)abs(p.x)*131%SZ+abs(p.y))%SZ;
    }
    void ins(P &p, int i){
        int k=gao(p);
        while (h[k]!=-1 && !(p==a[h[k]]))
            k=(k+1)%SZ;
        h[k]=i;
    }
    int find(P p){
        int k=gao(p);
        while (h[k]!=-1 && !(p==a[h[k]]))
            k=(k+1)%SZ;
        return h[k];
    }
    
};

Hash<1000003> hash;

int main(){
    while (~scanf("%d", &n) && n){
        hash.init();
        rep(i, n) a[i].input();
        sort(a, a+n);
        rep(i, n) hash.ins(a[i], i);
        
        ll ans=0;
        rep(i, n) repf(j, i+1, n-1){
            P w=a[j]-a[i], u=a[i]-a[j];
            if (w.x>0 && w.y>=0){
                P x(w.y+a[i].x, -w.x+a[i].y);
                P y(-u.y+a[j].x, u.x+a[j].y);                
                if (hash.find(x)!=-1 && hash.find(y)!=-1) ans++;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
