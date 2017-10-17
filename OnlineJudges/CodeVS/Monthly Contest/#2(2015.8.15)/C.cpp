#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int D=10000000,MAXN=100000,MAXM=400000;
char in[D],*I=in,out[D/10],*O=out;
int n,m;
int L[MAXM],R[MAXM],sum[MAXM];
inline int readln()
{
    int x=0;bool a=false;char ch;
    for(ch=*(I++);ch<'0'||'9'<ch;ch=*(I++))if(ch=='-')a=true;
    for(;'0'<=ch&&ch<='9';ch=*(I++))x=(x<<3)+(x<<1)+ch-'0';
    if(a)x=-x;
    return x;
}
inline void writeln(int x)
{
    if(!x){*(O++)='0';return;}
    static int s[33];
    if(x<0){*(O++)='-';x=-x;}
    for(;x;x/=10)s[++s[0]]=x%10;
    while(s[0])*(O++)=s[s[0]--]+'0';
    return;
}
void build(int root,int l,int r)
{
	L[root]=l;
	R[root]=r;
	if(l==r){sum[root]=readln();return;}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	sum[root]=sum[root<<1]+sum[root<<1|1];
	return;
}
void change(int root,int pos,int x)
{
	if(L[root]==pos&&pos==R[root]){sum[root]=x;return;}
	else if(pos<=R[root<<1])change(root<<1,pos,x);
	else if(pos>R[root<<1])change(root<<1|1,pos,x);
	sum[root]=sum[root<<1]+sum[root<<1|1];
	return;
}
void CHANGE(int root,int l,int r)
{
	if(!sum[root])return;
	else if(L[root]==R[root]){sum[root]=log(sum[root]);return;}
	else if(r<=R[root<<1])CHANGE(root<<1,l,r);
	else if(l>R[root<<1])CHANGE(root<<1|1,l,r);
	else if(l<=R[root<<1]&&R[root<<1]<r)CHANGE(root<<1,l,r),CHANGE(root<<1|1,l,r);
	sum[root]=sum[root<<1]+sum[root<<1|1];
	return;
}
int query(int root,int l,int r)
{
	if(!sum[root])return 0;
	else if(l<=L[root]&&R[root]<=r)return sum[root];
	else if(r<=R[root<<1])return query(root<<1,l,r);
	else if(l>R[root<<1])return query(root<<1|1,l,r);
	else if(l<=R[root<<1]&&R[root<<1]<r)return query(root<<1,l,r)+query(root<<1|1,l,r);
	return 0;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
    fread(in,1,D,stdin);
    int a,b,c;
    n=readln(),m=readln();
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
    	a=readln(),b=readln(),c=readln();
    	if(a==1)
	    	change(1,b,c);
	    else if(a==2)
	    	CHANGE(1,b,c);
	    else if(a==3)
	    {
	    	writeln(query(1,b,c));
	    	*(O++)='\n';
	    }
    }
    fwrite(out,1,O-out,stdout);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
