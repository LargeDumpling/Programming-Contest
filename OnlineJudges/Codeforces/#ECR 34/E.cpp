/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-12-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int k,n,num[26];
char str[10050];
bool flag=false;
int step(int a,int b)
{
	int cnt=0,tem[4];
	for(int i=0;i<n;i++)
		if(str[a*n+i]!=str[b*n+i])
		{
			if(cnt==4) return -1;
			tem[cnt++]=i;
		}
	if(cnt==0) return 0;
	if(cnt==1) return -1;
	if(cnt==2) return 1;
	if(cnt==3) return 2;
	for(int i=0;i<3;i++)
		for(int j=i+1;j<4;j++)
			if(str[a*n+tem[i]]==str[b*n+tem[j]]&&str[a*n+tem[j]]==str[b*n+tem[i]])
				return 2;
	return -1;
}
bool check(int x)
{
	int cnt[26];
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<n;i++)
		cnt[str[x*n+i]-'a']++;
	for(int i=0;i<26;i++)
		if(cnt[i]!=num[i])
			return false;
	return true;
}
bool check(int a,int b)
{
	for(int i=0;i<n;i++)
		str[k*n+i]=str[i];
	str[(k+1)*n]='\0';
	swap(str[k*n+a],str[k*n+b]);
	for(int i=0;i<k;i++)
	{
		int tem=step(i,k);
		if(tem==1||(flag&&tem==0));
		else return false;
		/*if(step(i,k)==1||(flag&&))
			return false;*/
	}
	return true;
}
int main()
{
	bool exist=true;
	scanf("%d%d",&k,&n);
	for(int i=0;i<k;i++)
		scanf("%s",str+i*n);
	if(k==1)
	{
		swap(str[0],str[1]);
		printf("%s",str);
		return 0;
	}
	for(int i=0;i<n;i++)
		num[str[i]-'a']++;
	for(int i=0;i<26;i++)
		if(2<=num[i])
			flag=true;
	for(int i=1;i<k;i++)
		exist&=check(i);
	if(exist)
	{
		for(int i=0;i<k&&exist;i++)
			for(int j=i+1;j<k&&exist;j++)
			{
				int tem=step(i,j);
				if(tem==0||tem==2||(tem==1&&flag));
				else exist=false;
			}
		if(!exist) puts("-1");
		else
		{
			exist=false;
			int tem[5]={0};
			for(int i=0;i<n;i++)
				if(str[i]!=str[n+i])
					tem[++tem[0]]=i;
			for(int i=1;i<=tem[0]&&!exist;i++)
				for(int j=i+1;j<=tem[0]&&!exist;j++)
					if(check(tem[i],tem[j]))
						exist=true;
			if(exist) puts(str+k*n);
			else puts("-1");
		}
	}
	else puts("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

