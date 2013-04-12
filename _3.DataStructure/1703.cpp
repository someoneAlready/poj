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

template<int SZ>
class UFS{
    int f[SZ+10];
public:
    void clear(int n){ repf(i, 1, n) f[i]=i; }
    int find(int i){
        if (f[i]==i) return i;
        return f[i]=find(f[i]);
    }
    void unions(int i, int j){
        i=find(i), j=find(j);
        f[i]=j;
    }
};

int i,j,k,m,n,l;
char s[100];
UFS<N> ufs;
int op[N+10];

int main(){
    int tests;
    scanf("%d", &tests);
    while (tests--){
        scanf("%d%d", &n, &m);
        ufs.clear(n);
        clr(op, 0);
        while (m--){
            scanf("%s%d%d", s, &i, &j);
            if (s[0]=='D'){
                if (op[i]) ufs.unions(op[i], j);
                if (op[j]) ufs.unions(op[j], i);
                op[i]=j, op[j]=i;
            }
            else if (s[0]=='A'){
               // cout<<ufs.find(i)<<' '<<ufs.find(j)<<endl;
                if (ufs.find(i)==ufs.find(j)) puts("In the same gang.");
                else{
                    if (op[i] && ufs.find(op[i])==ufs.find(j))
                        puts("In different gangs.");
                    else if (op[j] && ufs.find(op[j])==ufs.find(i))
                        puts("In different gangs.");
                    else 
                        puts("Not sure yet.");
                }
            }
        }
    }
    return 0;
}

