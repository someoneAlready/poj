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
#define M 30
#define T 1000

int i,j,k,m,n,l,t;
double p[T+10][M+10];
double f[M+10][M+10];

int main(){
    while (~scanf("%d%d%d", &m, &t, &n) && m+t+n){
        fill(p, 0);
        repf(i, 1, t) repf(j, 1, m) cin>>p[i][j];
        double a=1., b=1.;
        repf(i, 1, t){

            
            
            f[0][0]=1;
            repf(j, 1, m){
                f[j][0]=f[j-1][0]*(1-p[i][j]);
                repf(k, 1, j)
                    f[j][k]=f[j-1][k-1]*p[i][j]+f[j-1][k]*(1-p[i][j]);
            }

            a*=(1-f[m][0]);
            double c=0;
            repf(j, 1, n-1) c+=f[m][j];
            b*=c;
        }

        printf("%.3f\n", a-b);
    }
    return 0;
}
