/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T;
int n,k,len,cnt[15],num[15],ans[15],ansn;
void  mIn()
{
	int last;
	for(int i=1;i<10;i++) if(cnt[i]!=0)
	{
		cnt[i]--;
		putchar('0'+i);
		last=i;
		break;
	}
	for(int i=0;i<10;i++)
		for(int j=1;j<=cnt[i];j++)
			putchar('0'+i);
	cnt[last]++;
	return;
}
void mAx()
{
	for(int i=9;0<=i;i--)
		for(int j=1;j<=cnt[i];j++)
			putchar('0'+i);
	return;
}
void DFS_mIn(int x,int nk)
{
	if(x==-1)
	{
		int sum=0;
		for(int i=len-1;0<=i;i--)
			sum=sum*10+num[i];
		if(sum<ansn)
		{
			memcpy(ans,num,sizeof(num));
			ansn=sum;
		}
		return;
	}
	if(nk==0) DFS_mIn(-1,nk);
	else if(x==len-1)
	{
		/*int mini=0;
		while(num[mini]==0) mini++;
		for(int i=mini+1;i<=x;i++) if(num[i]!=0&&num[i]<num[mini])
			mini=i;
		swap(num[x],num[mini]);
		DFS_mIn(x-1,nk-(int)(num[x]!=num[mini]));
		swap(num[x],num[mini]);*/
		for(int i=x;0<=i;i--) if(num[i]!=0)
		{
			swap(num[x],num[i]);
			DFS_mIn(x-1,nk-(int)(num[x]!=num[i]));
			swap(num[x],num[i]);
		}
	}
	else
	{
		/*int mini=0;
		for(int i=1;i<=x;i++) if(num[i]<num[mini])
			mini=i;
		swap(num[x],num[mini]);
		DFS_mIn(x-1,nk-(int)(num[x]!=num[mini]));
		swap(num[x],num[mini]);*/
		for(int i=x;0<=i;i--)
		{
			swap(num[x],num[i]);
			DFS_mIn(x-1,nk-(int)(num[x]!=num[i]));
			swap(num[x],num[i]);
		}
	}
	return;
}
void DFS_mAx(int x,int nk)
{
	if(x==-1)
	{
		int sum=0;
		for(int i=len-1;0<=i;i--)
			sum=sum*10+num[i];
		if(ansn<sum)
		{
			memcpy(ans,num,sizeof(num));
			ansn=sum;
		}
		return;
	}
	else if(nk==0) DFS_mAx(-1,nk);
	else
	{
		/*int maxi=0;
		for(int i=1;i<=x;i++) if(num[maxi]<num[i])
			maxi=i;
		swap(num[x],num[maxi]);
		DFS_mAx(x-1,nk-(int)(num[x]!=num[maxi]));
		swap(num[x],num[maxi]);*/
		for(int i=x;0<=i;i--)
		{
			swap(num[x],num[i]);
			DFS_mAx(x-1,nk-(int)(num[x]!=num[i]));
			swap(num[x],num[i]);
		}
	}
	return;
}
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d",&n,&k);
		memset(cnt,0,sizeof(cnt));
		len=0;
		for(int x=n;x;x/=10)
		{
			cnt[x%10]++;
			num[len++]=x%10;
		}
		if(10<=k)
		{
			mIn(); putchar(' ');
			mAx(); putchar('\n');
		}
		else
		{
			memcpy(ans,num,sizeof(num));
			ansn=n;
			DFS_mIn(len-1,k);
			for(int i=len-1;0<=i;i--)
				putchar('0'+ans[i]);
			putchar(' ');
			memcpy(ans,num,sizeof(num));
			ansn=n;
			DFS_mAx(len-1,k);
			for(int i=len-1;0<=i;i--)
				putchar('0'+ans[i]);
			putchar('\n');
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

