#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char tex[100050];
int sa[100050],height[100050],n;
void build_sa()
{
	int c[100050],num[100050],bsa[100050],m=25,p;
	memset(c,0,sizeof(c));
	memset(num,0,sizeof(num));
	memset(bsa,0,sizeof(bsa));
	for(int i=0;i<n;i++)
		c[num[i+1]=tex[i]-97]++;
	for(int i=1;i<=m;i++)
		c[i]+=c[i-1];
	for(int i=n;i;i--)
		sa[c[num[i]]--]=i;
	for(int k=1;k<n;k<<=1)
	{
		memset(c,0,sizeof(c));
		p=0;
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
			break;
		m=p;
	}
	return;
}
void build_height()
{
	int k=0,rank[100050];
	for(int i=0;i<=n;i++)
		rank[sa[i]]=i;
	for(int i=1,j;i<=n;i++)
	{
		if(k)
			k--;
		j=sa[rank[i]-1];
		while(tex[i+k-1]==tex[j+k-1])
			k++;
		height[rank[i]]=k;
	}
	return;
}
int main()
{
	int maxlen=-2147483647,star=0;
	scanf("%s",tex);
	n=strlen(tex);
	build_sa();
	build_height();
	for(int i=1;i<=n;i++)
		if(height[i]>maxlen)
			maxlen=height[i],star=sa[i]-1;
	printf("%d\n",maxlen);
	for(int i=star;i-star<maxlen;i++)
		printf("%c",tex[i]);
	return 0;
}


