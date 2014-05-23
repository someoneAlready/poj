#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define itr iterator

bool v[40];

void oo(int d, int k){
    int j = 10;
    k--;
    while(k){
        if (d<j) putchar('0');
        j*=10, k--;
    }
    printf("%d", d);
}

char st[100];

struct Date{
    int d, m, y;
    void in(){
        scanf("%s", st);
        d=m=y=0;
        int x=strlen(st), z=0;
        rep(i, x) if (isdigit(st[i])){
            if (z==0) d=d*10+st[i]-'0';
            else if (z==1) m=m*10+st[i]-'0';
            else y=y*10+st[i]-'0';
        }
        else z++;
    }
    void out(){
        oo(d, 2), putchar('/'), oo(m, 2), putchar('/');
        oo(y, 4);
    }
    bool operator == (const Date& date)const{
        return d==date.d && m==date.m && y==date.y;
    }
    bool operator <(const Date &date)const{
        if (y!=date.y) return y<date.y;
        if (m!=date.m) return m<date.m;
        return d<date.d;
    }
    int days(){
        if (m<=6) return 31;
        if (m<=11) return 30;
        if (v[y%33]) return 30;
        return 29;
    }
    void next(){
        ++d;
        if (d>days()){
            d=1;
            ++m;
            if (m>12)
                m=1, y++;
        }
    }
};

struct Time{
    int h, m, s, u;
    void in(){
        scanf("%s", st);
        h=m=s=u=0;
        int x=strlen(st), y=0;
        rep(i, x) if (isdigit(st[i])){
            if (y==0) h=h*10+st[i]-'0';
            else if (y==1) m=m*10+st[i]-'0';
            else if (y==2) s=s*10+st[i]-'0';
            else u=u*10+st[i]-'0';
        }
        else y++;
    }
    Time(){}
    Time(int h, int m, int s, int u):h(h),m(m),s(s),u(u){}
    void out(){
        oo(h, 2), putchar(':');
        oo(m, 2), putchar(':');
        oo(s, 2), putchar('.');                
        oo(u, 3);
    }
    bool operator ==(const Time& t)const{
        return h==t.h && m==t.m && s==t.s && u==t.u;
    }
    bool operator <(const Time& t)const{
        if (h!=t.h)return h<t.h;
        if (m!=t.m) return m<t.m;
        if (s!=t.s) return s<t.s;
        return u<t.u;
    }
    bool add(const Time &t){
        u += t.u, s+=t.s, m+=t.m, h+=t.h;
        s+=u/1000;
        m+=s/60;
        h+=m/60;
        
        u%=1000;
        s%=60;
        m%=60;

        if (h>=24){
            h%=24;
            return 1;
        }
        return 0;
    }
};

struct P{
    int id;
    Date date;
    Time begin, during;
    int type;
    void in(){
        type=0;
        scanf("%d", &id);
        date.in(), begin.in(), during.in();
    }
    bool operator <(const P&p)const{
        if (!(p.date==date)) return date<p.date;
        if (!(p.begin==begin)) return begin<p.begin;
        if (p.type!=type) return type>p.type;
        return id<p.id;
    }
    void out(){
        printf("%d ", id);
        date.out(), putchar(' ');
        begin.out(), putchar(' ');
    }
    void add(const Time &t){
        if (begin.add(t)) date.next();
    }
};

int i,j,k,m,n,l;

int main(){
    v[1]=v[5]=v[9]=v[13]=v[17]=v[22]=v[30]=1;
    int ts;
    scanf("%d", &ts);
    repf(te, 1, ts){
        scanf("%d%d", &n, &m);
        multiset<P> st;
        P p;
        rep(i, n) p.in(), st.insert(p);
        
        printf("Report for Test-Case #%d:\n", te);
        while (sz(st)){
            multiset<P>::itr it = st.begin();
            p = *it;
            st.erase(it);
            
            p.out();
            if (p.type==0){
                if (m>0){
                    p.add(p.during), p.type=1, m--;
                    puts("ACCEPTED");
                }
                else{
                    p.add(Time(0, 10, 0, 0));
                    puts("POSTPONED");
                }
                st.insert(p);
            }
            else{
                puts("LANDED");
                ++m;
            }
        }
        puts("");
    }

    return 0;
}
