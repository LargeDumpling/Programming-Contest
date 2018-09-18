/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-17	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jz
{
	long long num[105][105];
	jz() { }
}d[17],ans;
int n,m;
jz mult(const jz &A,const jz &B)
{
	jz C;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			C.num[i][j]=0;
			for(int k=1;k<=m;k++) if(C.num[i][j]<A.num[i][k]+B.num[k][j])
				C.num[i][j]=A.num[i][k]+B.num[k][j];
		}
	return C;
}
template<typename Ty>
bool read1n(Ty &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch==-1) return false;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return true;
}
int main()
{
	long long res;
	while(read1n(n))
	{
		memset(ans.num,0,sizeof(ans.num));
		res=0;
		n--;
		read1n(m);
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				read1n(d[0].num[i][j]);
		for(int i=1;i<17;i++)
			//d[1]=mult(d[0],d[0]);
			d[i]=mult(d[i-1],d[i-1]);
		for(int i=0;i<17;i++) if((n>>i)&1)
			ans=mult(d[i],ans);
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++) if(res<ans.num[i][j])
				res=ans.num[i][j];
		printf("%lld\n",res);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

