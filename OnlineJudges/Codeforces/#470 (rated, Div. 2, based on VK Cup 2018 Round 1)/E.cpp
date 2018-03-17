/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-11	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=131072;
int S[2][MAXN],pre[2][MAXN],len1,len2;
char A[MAXN],B[MAXN];
int main()
{
	int a,b,c,d,Q;
	scanf("%s%s",A+1,B+1);
	len1=strlen(A+1); len2=strlen(B+1);
	for(int i=1;i<=len1;i++)
	{
		S[0][i]+=(A[i]!='A');
		if(A[i]=='A') pre[0][i]=pre[0][i-1];
		else pre[0][i]=i;
	}
	for(int i=1;i<=len1;i++)
		S[0][i]+=S[0][i-1];
	for(int i=1;i<=len2;i++)
	{
		S[1][i]+=(B[i]!='A');
		if(B[i]=='A') pre[1][i]=pre[1][i-1];
		else pre[1][i]=i;
	}
	for(int i=1;i<=len2;i++)
		S[1][i]+=S[1][i-1];
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int cnt1=(S[1][d]-S[1][c-1])-(S[0][b]-S[0][a-1]),cnt2=(b-max(pre[0][b],a-1))-(d-max(pre[1][d],c-1));
		if(cnt1<0||(cnt1%2)) putchar('0');
		else if(cnt2<0) putchar('0');
		else if(cnt2%3==0||cnt1!=0) putchar('1');
		else putchar('0');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

