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
int T_T,l[15],r[15],d[15];
int num[3],ans;
char str[15];
void make_chain()
{
	d[0]=d[10]=0;
	l[0]=0; l[10]=9;
	r[0]=1; r[10]=10;
	for(int i=1;i<=9;i++)
	{
		l[i]=i-1;
		r[i]=i+1;
		if(str[i]=='g') d[i]=1;
		else if(str[i]=='a') d[i]=2;
		else if(str[i]=='o') d[i]=3;
	}
	return;
}
int calc()
{
	int ans=0,cnt;
	for(int t=0,i,j;t<3;t++)
	{
		cnt=0;
		for(i=0;i!=10&&d[i]!=num[t];i=r[i]);
		for(j=i;j!=10&&cnt<3;j=r[j])
			if(d[i]==d[j])
			{
				cnt++;
				if(cnt==3)
					break;
			}
		if(cnt==3)
		{
			r[l[i]]=r[j];
			l[r[j]]=l[i];
			ans++;
		}
	}
	return ans;
}
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%s",str+1);
		ans=0;
		num[0]=1;
		num[1]=2;
		num[2]=3;
		do
		{
			make_chain();
			ans=max(ans,calc());
		}while(next_permutation(num,num+3));
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

