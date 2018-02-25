/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,k,sn;
char A[MAXN],B[MAXN],set[MAXN];
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",A);
	for(int i=0;i<k;i++)
		B[i]=A[i];
	B[k]='\0';
	sn=0;
	for(int i=0;i<n;i++)
		set[++sn]=A[i];
	sort(set+1,set+sn+1);
	sn=unique(set+1,set+sn+1)-set-1;
	if(k<=n)
	{
		int j;
		for(int i=k-1,m;0<=i;i--)
		{
			if((m=lower_bound(set+1,set+sn+1,A[i])-set)!=sn)
			{
				B[i]=set[m+1];
				j=i+1;
				break;
			}
		}
		for(;j<k;j++)
			B[j]=set[1];
	}
	else for(int i=n;i<k;i++)
		B[i]=set[1];
	printf("%s",B);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

