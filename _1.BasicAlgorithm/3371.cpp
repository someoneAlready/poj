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
#define N 1000000

int i,j,k,m,n,l;
char s[N+10];

int gao(string &t){
    int ret=0;
    if (sz(t)<=3) return 1;

        if (t.substr(sz(t)-2)=="es" || t.substr(sz(t)-2)=="ed") t.erase(sz(t)-2, 2);
        else if (t[sz(t)-1]=='e' && t[sz(t)-2]!='l') t.erase(sz(t)-1, 1); 
    if (sz(t)<=3) return 1;

    rep(i, sz(t)){
        if (strchr("aeiouy", t[i])!=NULL && (!i || strchr("aeiouy", t[i-1])==NULL)) ret++;
    }

    return ret;
}

double solve(){
    int words=0, sentences=0, syllables=0;
    while (~scanf("%s", s)){
        n=strlen(s);           
        string t;
        rep(i, n+1){
            if (i<n && isalpha(s[i])) t+=tolower(s[i]);
            else{
                if (i==n || (i<n && strchr(".,?!:;", s[i])!=NULL)){
                    if (i<n && s[i]!=',') sentences++;
                    if (t!=""){
                   //     cout<<t<<' '<<gao(t)<<endl;
                        words++;
                        syllables+=gao(t);
                        t="";
                    }
                }
            }
            
        }

    }

    return 206.835-1.015*words/sentences-84.6*syllables/words;
}

int main(){
   
    printf("%.2f\n", solve());
   
    return 0;
}

