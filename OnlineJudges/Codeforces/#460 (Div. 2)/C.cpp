/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char str[5050];
int l[5050],r[5050],f[5050],cnt[5050],len,n=0,ans=0;
int fInd(int x)
{
	if(f[x]==x) return x;
	if(f[x]!=fInd(f[x]))
		f[x]=fInd(f[x]);
	return f[x];
}
void merge(int a,int b)
{
	a=fInd(a); b=fInd(b);
	if(a==b) return;
	if(a<b) swap(a,b);
	f[b]=a;
	return;
}
int main()
{
	gets(str+1);
	len=strlen(str+1);
	for(int i=0;i<5050;i++)
		f[i]=i;
	for(int i=2;i<=len;i++)
	{
		if((str[i-1]=='('||str[i-1]=='?')
				&&(str[i]==')'||str[i]=='?'))
		{
			n++;
			l[n]=i-1;
			r[n]=i;
			cnt[i]=cnt[i-2]+1;
			merge(i-2,i);
		}
	}
	for(int k=4;k<=len;k+=2)
		for(int i=1;i<=n;i++)
		{
			l[i]--;
			r[i]++;
			if(1<=l[i]&&r[i]<=len&&(str[l[i]]=='('||str[l[i]]=='?')
					&&(str[r[i]]==')'||str[r[i]]=='?'))
			{
				if(fInd(r[i])!=fInd(l[i]-1))
				{
					cnt[r[i]]+=cnt[l[i]-1]+1;
					merge(r[i],l[i]-1);
				}
			}
			/*else
			{
				swap(l[i],l[n]);
				swap(r[i],r[n]);
				n--;
				i--;
			}*/
		}
	for(int i=1;i<=len;i++)
		ans+=cnt[i];
		/*if(f[i]==i)
			ans+=size[i]*size[i+1]/2;*/
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

