/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const __int128 INF=(1LL<<62)-1LL+(1LL<<62);
int T_T;
__int128 a,b,c,d,v,t,p;
template<typename Ty>
void read1n(Ty &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
__int128 gcd(__int128 n,__int128 m)
{
	__int128 t;
	while(m)
	{
		t=n%m;
		n=m;
		m=t;
	}
	return n;
}
void calc(__int128 last,__int128 &ans,__int128 limit)
{
	__int128 i,an,cn,nex;
	for(i=an=cn=0;i<p&&i<=limit;i=nex)
	{
		if(i%a==0)
		{
			if(last<i)
			{
				ans--;
				last=i+v;
			}
			ans+=b;
		}
		if(i%c==0)
		{
			if(last<i)
			{
				ans--;
				last=i+v;
			}
			ans+=d;
		}
		if((an+1)*a<(cn+1)*c)
			nex=(++an)*a;
		else if((cn+1)*c<(an+1)*a)
			nex=(++cn)*c;
		else
		{
			an++; cn++;
			nex=an*a;
		}
	}
	return;
}
int st[200];
void write1n(__int128 x)
{
	st[0]=0;
	if(!x) st[++st[0]]=0;
	for(;x;x/=10) st[++st[0]]=x%10;
	while(st[0]) putchar('0'+st[st[0]--]);
	return;
}
int main()
{
	__int128 ans,cnt,last;
	read1n(T_T);
	while(T_T--)
	{
		ans=cnt=0;
		last=-1;
		read1n(a); read1n(b);
		read1n(c); read1n(d);
		read1n(v); read1n(t);
		p=a*c/gcd(a,c);
		calc(last,cnt,t);
		last=max(-a,-c)+v;
		ans+=cnt; cnt=0;
		t-=p;
		if(0<=t)
		{
			calc(last,cnt,t);
			last=max(-a,-c)+v;
			ans+=cnt*(t/p); cnt=0;
			calc(last,cnt,t%p);
			last=max(-a,-c)+v;
			ans+=cnt; cnt=0;
		}
		//printf("%lld\n",ans);
		write1n(ans);
		if(T_T) putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

