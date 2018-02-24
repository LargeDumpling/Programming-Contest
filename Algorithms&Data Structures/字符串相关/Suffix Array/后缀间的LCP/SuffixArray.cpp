#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
void build_sa(char tex[],int sa[])
{
	int c[100050],num[100050],bsa[100050],n=strlen(tex),m=25,p;
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++)
		c[num[i+1]=tex[i]-97]++;
	for(int i=1;i<=m;i++)
		c[i]+=c[i-1];
	for(int i=n;i;i--)
		sa[c[num[i]]--]=i;
	for(int k=1;k<n;k<<=1)
	{
		p=0;
		memset(c,0,sizeof(c));
		for(int i=n-k+1;i<=n;i++)
			bsa[++p]=i;
		for(int i=1;i<=n;i++)
			if(sa[i]>k)
				bsa[++p]=sa[i]-k;
		for(int i=1;i<=n;i++)
			c[num[bsa[i]]]++;
		for(int i=1;i<=m;i++)
			c[i]+=c[i-1];
		for(int i=n;i;i--)
			sa[c[num[bsa[i]]]--]=bsa[i];
		swap(num,bsa);
		num[sa[1]]=p=1;
		for(int i=2;i<=n;i++)
			num[sa[i]]=bsa[sa[i]]==bsa[sa[i-1]]&&bsa[sa[i]+k]==bsa[sa[i-1]+k]?p:++p;
		if(p>=n)
			return;
		m=p;
	}
}
int main()
{
	char tex[100050];
	int sa[100050],n;
	scanf("%s",tex);
	n=strlen(tex);
	build_sa(tex,sa);
	for(int i=1;i<=n;i++)
		printf("%d ",sa[i]);
	return 0;
}

