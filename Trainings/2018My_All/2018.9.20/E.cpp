/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
int T_T,n;
char str[MAXN];
int f[MAXN],ans;
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d",&n);
		scanf("%s",str+1);
		if(n<3) puts("0");
		else
		{
			f[0]=0;
			for(int i=1;i<=n;i++)
			{
				f[i]=f[i-1];
				if(str[i-3]=='C'&&str[i-2]=='C'&&str[i-1]=='P'&&str[i]=='C')
					f[i]++;
			}
			ans=f[n];
			for(int i=3;i<=n;i++)
			{
				if(str[i-2]=='C'&&str[i-1]=='P'&&str[i]=='C')
				{
					if(i==3||str[i-3]=='P')
					{
						ans++;
						break;
					}
				}
				else if(str[i-2]=='C'&&str[i-1]=='C'&&str[i]=='C')
				{
					if(str[i+1]!='P'||str[i+2]!='C')
					{
						ans++;
						break;
					}
				}
				else if(str[i-2]=='C'&&str[i-1]=='C'&&str[i]=='P')
				{
					if(str[i+1]!='C')
					{
						ans++;
						break;
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

