/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-04-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,Q;
long long s[MAXN],sm[MAXN],S[MAXN],l,r;
template<typename Ty>
void read1n(Ty &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
long long calc()
{
	long long sum=0,len=r-l+1LL;
	sum=len;
	int p=upper_bound(sm+1,sm+n+1,len)-sm;
	sum+=S[p-1]+(long long)(n-p+1)*len;
	return sum;
}
int main()
{
	read1n(n);
	for(int i=1;i<=n;i++)
		read1n(s[i]);
	sort(s+1,s+n+1);
	s[0]=s[1];
	S[0]=0;
	for(int i=1;i<=n;i++)
		sm[i]=s[i]-s[i-1];
	sort(sm+1,sm+n+1);
	for(int i=1;i<=n;i++)
		S[i]=S[i-1]+sm[i];
	read1n(Q);
	while(Q--)
	{
		read1n(l); read1n(r);
		printf("%I64d ",calc());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

