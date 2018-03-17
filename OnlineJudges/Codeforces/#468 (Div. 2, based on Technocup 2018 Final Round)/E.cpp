/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXL=5050;
char str[MAXL];
int an,len;
bool cap[MAXL];
struct jz
{
	int i,j;
	jz(const int &I=0,const int &J=0):i(I),j(J) { }
	bool operator<(const jz &X)const
	{
		if(str[i]==str[X.i]) return j==X.j?str[(i+j)%len]<str[(X.i+X.j)%len]:j<X.j;
		return str[i]<str[X.i];
	}
	bool operator==(const jz &X)const { return str[i]==str[X.i]&&j==X.j&&str[(i+j)%len]==str[(X.i+X.j)%len]; }
}A[MAXL*MAXL];
int main()
{
	int cnt=0;
	memset(cap,false,sizeof(cap));
	an=0;
	scanf("%s",str);
	len=strlen(str);
	for(int i=0;i<len;i++)
		for(int j=1;j<len;j++)
			A[++an]=jz(i,j);
	sort(A+1,A+an+1);
	for(int l=1,r;l<=an;l=r+1)
	{
		for(r=l;A[l]==A[r+1];)
		{
			r++;
		}
		if(l==r) cap[A[l].i]=true;
	}
	for(int i=0;i<len;i++) if(cap[i])
		cnt++;
	printf("%lf",(double)cnt/len);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

