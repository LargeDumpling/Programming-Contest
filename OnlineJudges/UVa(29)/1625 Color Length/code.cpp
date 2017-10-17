/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-11-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,lena,lenb,sta[26],stb[26],eda[26],edb[26],f[1050][1050];
char A[1050],B[1050];
bool check(int i,int j,int k)
{
	return (sta[k]<=i||stb[k]<=j)
		&& (i<eda[k]||j<edb[k]);
}
int calc(int i,int j)
{
	int num=0;
	for(int k=0;k<26;k++)
		if(check(i,j,k))
			num++;
	return num;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",A+1,B+1);
		memset(f,0,sizeof(f));
		memset(sta,0,sizeof(sta));
		memset(stb,0,sizeof(stb));
		memset(eda,0,sizeof(eda));
		memset(edb,0,sizeof(edb));
		lena=strlen(A+1);
		lenb=strlen(B+1);
		for(int i=1;i<=lena;i++)
			if(!sta[A[i]-'A'])
				sta[A[i]-'A']=i;
		for(int i=lena;i;i--)
			if(!eda[A[i]-'A'])
				eda[A[i]-'A']=i;
		for(int i=1;i<=lenb;i++)
			if(!stb[B[i]-'A'])
				stb[B[i]-'A']=i;
		for(int i=lenb;i;i--)
			if(!edb[B[i]-'A'])
				edb[B[i]-'A']=i;
		for(int i=0;i<26;i++)
		{
			if(!sta[i])sta[i]=2147483647;
			if(!stb[i])stb[i]=2147483647;
			if(!eda[i])eda[i]=-1;
			if(!edb[i])edb[i]=-1;
		}
		memset(f,127,sizeof(f));
		f[0][0]=0;
		for(int i=0;i<=lena;i++)
			for(int j=0;j<=lenb;j++)
			{
				/*a=calc(i+1,j);
				b=calc(i,j+1);*/
				a=calc(i,j);
				f[i+1][j]=min(f[i+1][j],f[i][j]+a);
				f[i][j+1]=min(f[i][j+1],f[i][j]+a);
			}
		printf("%d\n",f[lena][lenb]);
		/*for(int i=0;i<=lena;i++)
		{
			for(int j=0;j<=lenb;j++)
				printf("(%d,%d)=%d ",i,j,f[i][j]);
			printf("\n");
		}*/
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

