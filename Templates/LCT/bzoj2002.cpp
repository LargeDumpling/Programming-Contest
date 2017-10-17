#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
using namespace std;
 
const int Maxn = 200010;
 
int ch[Maxn][2],p[Maxn],sz[Maxn],tl[Maxn];
int n,m;
 
const int D=15000000;
char in[D],out[300010*10],*I=in,*O=out;
#define gc (*I++)
#define pc(x) ((*O++)=x)
template <typename Q> 
void gt(Q&x) {
    static char c,f;
    for(c=gc,f=0;!isdigit(c);c=gc)if(c=='-') f=1;
    for(x=0;isdigit(c);c=gc) x=x*10+c-'0';
    f && (x=-x);
}
template <typename Q>
void pt(Q x){
    static char stk[20];
    static int top;
    top=0;
    if(x==0) pc('0');
    for(;x;x/=10) stk[++top] = x%10+'0';
    for(int i=top;i;i--) pc(stk[i]);
}
 
bool isroot(int x){
    return ch[p[x]][0]!=x && ch[p[x]][1]!=x;
}
 
void update(int x) {
    if(x==0) return;
    sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
}
 
void rotate(int x) {
    int y=p[x],z=p[y];
    int l=ch[y][1]==x,r=l^1;
    if(!isroot(y)) ch[z][ch[z][1]==y]=x;
    p[ch[x][r]]=y;
    p[y]=x;
    p[x]=z;
     
    ch[y][l]=ch[x][r];
    ch[x][r]=y;
     
    update(y);
    update(x);
}
 
void splay(int x){
    for(;!isroot(x);){
        int y=p[x],z=p[y];
        if(!isroot(y)){
            if( (ch[y][1]==x)^(ch[z][1]==y) )
                rotate(x);else rotate(y);
        }
        rotate(x);
    }
}
 
void access(int x){
    for(int t=0;x;x=p[t=x]){
        splay(x);
        ch[x][1]=t;
        update(x);
    }
}
 
int getroot(int x){
    for(access(x),splay(x);ch[x][0];x=ch[x][0]);
    return x;
}
 
void cut(int x){
    access(x);
    splay(x);
    p[ch[x][0]]=0;
    ch[x][0]=0;
    update(x);  
}
 
void join(int x,int y) {
    cut(x);
    p[x]=y;
    update(y);
}
 
void init(){
    gt(n);
    for(int i=1;i<=n;i++) {
        sz[i]=1;
        gt(tl[i]);
        p[i]=min(tl[i]+i,n+1);
        tl[i]=p[i];
    }
    sz[n+1]=1;
}
 
void work() {
    gt(m);
    int cmd,a,b;
    for(int i=1;i<=m;i++) {
        gt(cmd),gt(a),a++;
        if(cmd==1) {
            access(a);
            splay(a);
            pt(sz[a]-1);
            pc('\n');
        }else{
            gt(b);
            int y=min(a+b,n+1);
            if(y==tl[a]) continue;
            join(a,tl[a]=y);
        }
    }
}
             
    
int main() {
#ifdef DEBUG
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    fread(in,1,D,stdin);
 
    init();
    work();
     
    return printf(out),0;
}
