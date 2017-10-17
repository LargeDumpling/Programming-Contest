/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-06-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXC=1000050;
int n,A,cnt[MAXC];
bool exist[MAXC];
int main()
{
	//freopen("D.in","r",stdin);
	//freopen("D.out","w",stdout);
	int c;
	memset(exist,true,sizeof(exist));
	memset(cnt,0,sizeof(cnt));
	scanf("%d%d",&n,&A);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c);
		if(exist[c])
		{
			if(c!=A)
			{
				if(cnt[c]<cnt[A])
					exist[c]=false;
				else cnt[c]++;
			}
			else cnt[c]++;
		}
	}
	int p=1;
	while((!exist[p]||p==A||cnt[p]<cnt[A])&&p<=1000000) p++;
	if(p==1000001) p=-1;
	printf("%d",p);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

