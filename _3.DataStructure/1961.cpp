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
#define N 1000000

int i,j,k,m,n,l;
char s[N+10];
int f[N+10];

int main(){
    int test=0;
    while (~scanf("%d", &n) && n){
        scanf("%s", s);
        f[0]=f[1]=0;
        repf(i, 1, n-1){
            int j=f[i];
            while (j && s[i]!=s[j]) j=f[j];
            f[i+1]= s[i]==s[j]? j+1: 0;
        }
        printf("Test case #%d\n", ++test);


        repf(i, 2, n) 
            if (f[i] && i%(i-f[i])==0)
                printf("%d %d\n", i, i/(i-f[i]));
        putchar('\n');
    }
    return 0;
}

