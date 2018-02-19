/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-17	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
struct jz
{
	char u,v;
}ans[MAXN];
int n,f[30],an=0;
char A[MAXN],B[MAXN];
int fInd(int x)
{
	if(f[x]!=f[f[x]]) f[x]=fInd(f[x]);
	return f[x];
}
void mErge(int a,int b)
{
	a=fInd(a); b=fInd(b);
	f[b]=a;
	return;
}
int main()
{
	for(int i=1;i<=26;i++) f[i]=i;
	scanf("%d%s%s",&n,A,B);
	for(int i=0;i<n;i++) if(fInd(A[i]-'a'+1)!=fInd(B[i]-'a'+1))
	{
		an++;
		ans[an].u=A[i];
		ans[an].v=B[i];
		mErge(A[i]-'a'+1,B[i]-'a'+1);
	}
	printf("%d\n",an);
	for(int i=1;i<=an;i++)
		printf("%c %c\n",ans[i].u,ans[i].v);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

