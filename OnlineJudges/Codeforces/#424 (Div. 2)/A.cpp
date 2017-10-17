/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-07-13	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,dir,a[105];
bool ans=true;
int main()
{
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dir=1;
	for(int i=2;i<=n;i++)
	{
		if(dir==1)
		{
			if(a[i-1]==a[i])
				dir=0;
			else if(a[i-1]>a[i])
				dir=-1;
		}
		else if(dir==0)
		{
			if(a[i-1]<a[i])
			{
				ans=false;
				break;
			}
			else if(a[i-1]>a[i])
				dir=-1;
		}
		else if(dir==-1)
		{
			if(a[i-1]<=a[i])
			{
				ans=false;
				break;
			}
		}
	}
	if(ans) printf("YES");
	else printf("NO");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

