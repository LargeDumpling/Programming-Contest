/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<bitset>
#include<algorithm>
using namespace std;
const int MAXN=2000;
bitset<2000> s[MAXN];
char str[MAXN];
int main()
{
	freopen("E.txt","r",stdin);
	bool flag=true;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n&&flag;i++)
	{
		scanf("%s",str);
		for(int j=0;j<n;j++) if(str[j]=='1')
			s[i][j]=1;
		for(int j=0;j<i;j++)
		{
			bitset<2000> tem=s[i]&s[j];
			if(1<tem.count())
			{
				flag=false;
				break;
			}
		}
	}
	if(flag) puts("Yes");
	else puts("No");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

