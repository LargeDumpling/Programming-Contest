/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,len[15],ans,anslen=-1;
int cnt[1024];
char str[15][20];
void pre_calc()
{
	cnt[0]=0;
	for(int i=1;i<1024;i++)
		cnt[i]=cnt[i>>1]+(i&1);
	return;
}
bool check(int S)
{
	char tem[2][25];
	int l=cnt[S],c[2]={0,0},st[2]={0,0};
	for(int i=0;i<len[0];i++)
	{
		if((ans>>i)&1)
			tem[0][++c[0]]=str[0][i];
		if((S>>i)&1)
			tem[1][++c[1]]=str[0][i];
	}
	for(int i=1;i<=l;i++)
	{
		tem[0][i+l]=tem[0][i];
		tem[1][i+l]=tem[1][i];
	}
	int i=1,j=2,k;
	while(i<=l&&j<=l)
	{
		for(k=0;k<=l&&tem[0][i+k]==tem[0][j+k];k++);
		if(k==l) break;
		if(tem[0][i+k]>tem[0][j+k])
		{
			i=i+k+1;
			if(i==j) i++;
		}
		else
		{
			j=j+k+1;
			if(i==j) j++;
		}
	}
	st[0]=min(i,j);
	i=1; j=2;
	while(i<=l&&j<=l)
	{
		for(k=0;k<=l&&tem[1][i+k]==tem[1][j+k];k++);
		if(k==l) break;
		if(tem[1][i+k]>tem[1][j+k])
		{
			i=i+k+1;
			if(i==j) i++;
		}
		else
		{
			j=j+k+1;
			if(i==j) j++;
		}
	}
	st[1]=min(i,j);
	for(int k=0;k<l;k++)
	{
		if(tem[0][st[0]+k]<tem[1][st[1]+k])
			return false;
		else if(tem[0][st[0]+k]>tem[1][st[1]+k])
			return true;
	}
	return false;
}
int main()
{
	int limit,num[15],mat[15];
	bool flag;
	pre_calc();
	while(scanf("%d",&n)!=-1)
	{
		anslen=-1;
		for(int i=0;i<n;i++)
		{
			scanf("%s",str[i]);
			len[i]=strlen(str[i]);
			for(int j=len[i];0<=j;j--)
				str[i][j+len[i]]=str[i][j];
		}
		limit=1<<len[0];
		for(int S=1;S<limit;S++)
		{
			if(cnt[S]<anslen)
				continue;
			num[0]=0;
			for(int i=0;i<len[0];i++) if((S>>i)&1)
				num[++num[0]]=i;
			flag=true;
			for(int i=1,j;flag&&i<n;i++)
			{
				flag=false;
				for(int k=0;k<len[i]*2&&(!flag);k++) if(str[i][k]==str[0][num[1]])
				{
					j=0;
					for(int l=k;l<len[i]*2&&(!flag);l++) if(str[i][l]==str[0][num[j+1]])
					{
						mat[++j]=l;
						if(j==num[0])
						{
							if(mat[num[0]]-mat[1]+1<=len[i])
								flag=true;
							break;
						}
					}
				}
			}
			if(!flag) continue;
			if(anslen<cnt[S])
			{
				ans=S;
				anslen=cnt[S];
			}
			else if(check(S))
				ans=S;
		}
		if(anslen==-1) puts("0");
		else
		{
			char tem[25];
			int i=1,j=2,k,st,l=cnt[ans],cc=0;
			for(int i=0;i<len[0];i++)
				if((ans>>i)&1)
					tem[++cc]=str[0][i];
			for(int i=1;i<=l;i++)
				tem[i+l]=tem[i];
			while(i<=l&&j<=l)
			{
				for(k=0;k<=l&&tem[i+k]==tem[j+k];k++);
				if(k==l) break;
				if(tem[i+k]>tem[j+k])
				{
					i=i+k+1;
					if(i==j) i++;
				}
				else
				{
					j=j+k+1;
					if(i==j) j++;
				}
			}
			st=min(i,j);
			for(int i=0;i<l;i++)
				putchar(tem[st+i]);
			putchar('\n');
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

