/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-11-27	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,lenth,f[1050];
bool Pal[1050][1050];
char tex[1050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",tex+1);
		lenth=strlen(tex+1);
		for(int i=1;i<=lenth;i++)
			for(int j=1;j<=lenth;j++)
			{
				Pal[i][j]=true;
				for(int k=(j-i+1)>>1;k;k--)
					if(tex[i+k-1]!=tex[j-k+1])
					{
						Pal[i][j]=false;
						break;
					}
			}
		memset(f,127,sizeof(f));
		f[0]=0;
		for(int i=1;i<=lenth;i++)
			for(int j=0;j<i;j++)
				if(Pal[j+1][i])
					f[i]=min(f[i],f[j]+1);
		printf("%d\n",f[lenth]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

