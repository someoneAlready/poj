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
#define N 100

int i,j,k,m,n,l;
struct P{
    float x, y, z, r;
    void input(){ scanf("%f%f%f%f", &x, &y, &z, &r); }
};
P a[N+10];
struct E{
    int i,j; double d;
    E(){}
    E(int i, int j, double d):i(i),j(j),d(d){}  
    bool operator <(const E &e)const{return d<e.d;}
};

template<int SZ>
struct UFS{
    int f[SZ+10];
    UFS(){repf(i, 0, SZ) f[i]=i;}
    int find(int i){return f[i]==i?i:(f[i]=find(f[i])); }
    void unions(int i, int j){ f[find(i)]=find(j); }
};


int main(){
    while (~scanf("%d", &n) && n){
        rep(i, n) a[i].input();
        vector<E> e;
        rep(i, n) repf(j, i+1, n-1){
            double d=sqrt(SQR(a[i].x-a[j].x)+SQR(a[i].y-a[j].y)+SQR(a[i].z-a[j].z));
            d= (d<=a[i].r+a[j].r?0:d-a[i].r-a[j].r);
            e.pb(E(i,j,d));
        }
        sort(all(e));
        UFS<N> ufs;
        double ans=0; int tot=0;
        rep(i, sz(e)){
            if (ufs.find(e[i].i)!=ufs.find(e[i].j)){
                ans+=e[i].d, ufs.unions(e[i].i, e[i].j), tot++;
                if (tot==n-1) break;
            }
        }
        printf("%.3f\n", ans);
    }
    return 0;
}

