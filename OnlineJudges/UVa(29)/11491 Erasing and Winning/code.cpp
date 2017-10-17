/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History: 
    2015-11-26    File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,d,L[100050],R[100050];
char numb[100050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(scanf("%d%d",&n,&d)&&n&&d)
	{
		scanf("%s",numb+1);
		R[0]=1;
		for(int i=1;i<=n;i++)L[i]=i-1,R[i]=i+1;
		L[n+1]=n;
		for(int i=1;i<=n&&d;i=R[i])
		{
			while(L[i]&&numb[L[i]]<numb[i]&&d)
			{
				R[L[L[i]]]=i;
				L[i]=L[L[i]];
				//R[L[i]]=R[i];
				//L[R[i]]=L[i];
				d--;
			}
		}
		for(int i=L[n+1];i&&d;i=L[i])
		{
			R[L[i]]=R[i];
			L[R[i]]=L[i];
			d--;
		}
		for(int i=R[0];i<=n;i=R[i])
			printf("%c",numb[i]);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

