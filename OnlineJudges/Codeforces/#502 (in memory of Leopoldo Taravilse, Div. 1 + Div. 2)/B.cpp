/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
char A[MAXN],B[MAXN];
int n;
long long ans,a,b,c,d;
int main()
{
	scanf("%d",&n);
	scanf("%s%s",A,B);
	a=b=c=d=ans=0;
	for(int i=0;i<n;i++)
	{
		if(B[i]=='0')
		{
			if(A[i]=='0') a++;
			else if(A[i]=='1') b++;
		}
		else if(B[i]=='1')
		{
			if(A[i]=='0') c++;
			else if(A[i]=='1') d++;
		}
	}
	ans=a*b+a*d+b*c;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
