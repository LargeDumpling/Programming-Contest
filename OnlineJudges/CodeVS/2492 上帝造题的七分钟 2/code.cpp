#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int D=10000000,MAXN=100050,MAXM=100050;
char in[D],*I=in,out[D/10],*O=out;
int L[4*MAXN],R[4*MAXN],n,m;
long long sum[4*MAXN];
bool tag[4*MAXN];
inline long long readln()
{
	long long x=0;bool a=false;char ch;
	for(ch=*(I++);ch<'0'||'9'<ch;ch=*(I++))if(ch=='-')a=true;
	for(;'0'<=ch&&ch<='9';ch=*(I++))x=(x<<1)+(x<<3)+ch-'0';
	if(a)x=-x;
	return x;
}
inline void writeln(long long x)
{
	static int s[50]={0};
	if(x==0){*(O++)='0';return;}
	if(x<0){*(O++)='-';x=-x;}
	for(;x;x/=10)
		s[++s[0]]=x%10;
	while(s[0])
		*(O++)=(s[s[0]--])+'0';
	return;
}
void build(int root,int l,int r)
{
	L[root]=l;R[root]=r;
	if(l==r)
	{
		sum[root]=readln();
		if(sum[root]==1||!sum[root])tag[root]=true;
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	sum[root]=sum[root<<1]+sum[root<<1|1];
	tag[root]=tag[root<<1]&tag[root<<1|1];
	return;
}
void change(int root,int l,int r)
{
	if(tag[root])return;
	if(L[root]==R[root])
	{
		sum[root]=sqrt(sum[root]);
		if(sum[root]==1||!sum[root])
			tag[root]=true;
		return;
	}
	if(r<=R[root<<1])change(root<<1,l,r);
	else if(l>R[root<<1])change(root<<1|1,l,r);
	else if(l<=R[root<<1]&&R[root<<1]<r)change(root<<1,l,r),change(root<<1|1,l,r);
	sum[root]=sum[root<<1]+sum[root<<1|1];
	tag[root]=tag[root<<1]&tag[root<<1|1];
	return;
}
long long query(int root,int l,int r)
{
	if(l<=L[root]&&R[root]<=r)
		return sum[root];
	if(r<=R[root<<1])return query(root<<1,l,r);
	else if(l>R[root<<1])return query(root<<1|1,l,r);
	else if(l<=R[root<<1]&&R[root<<1]<r)return query(root<<1,l,r)+query(root<<1|1,l,r);
	return 0;
}
int main()
{
	long long a,b,c;
	fread(in,1,D,stdin);
	n=readln();
	build(1,1,n);
	m=readln();
	for(int i=1;i<=m;i++)
	{
		a=readln(),b=readln(),c=readln();
		if(b>c)
		{
		    b+=c;
		    c=b-c;
		    b-=c;
		}
		if(!a)change(1,b,c);
		else if(a)
		{
			writeln(query(1,b,c));
			*(O++)='\n';
		}
	}
	fwrite(out,1,O-out,stdout);
	return 0;
}

