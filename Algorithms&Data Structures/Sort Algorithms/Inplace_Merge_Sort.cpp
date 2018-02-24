#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,num[100050];
void swap(int &a,int &b)
{
	a^=b;
	b=a^b;
	a^=b;
	return;
}
void mEmswap(int *p,int LenA,int LenB)
{
	for(int i=LenA/2-1;i>=0;i--)
		swap(*(p+i),*(p+LenA-1-i));
	for(int i=LenB/2-1;i>=0;i--)
		swap(*(p+LenA+i),*(p+LenA+LenB-i-1));
	for(int i=(LenA+LenB)/2-1;i>=0;i--)
		swap(*(p+i),*(p+LenA+LenB-i-1));
	return;
}
void in_place_merge(int *num,int LenA,int LenB)
{
	int i=0,j=LenA,Lenth=LenA+LenB,index;
	while(j<Lenth)
	{
		while(i<j&&num[i]<=num[j])i++;
		index=j;
		while(j<Lenth&&num[j]<=num[i])j++;
		mEmswap(num+i,index-i,j-index);
		i+=(j-index);
	}
	return;
}
void in_place_merge_sort(int *begin,int *end)
{
	if(begin!=end)
	{
		int *mid=begin+(end-begin)/2;
		in_place_merge_sort(begin,mid);
		in_place_merge_sort(mid,end);
		in_place_merge(begin,mid-begin,end-mid);
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("Inplace_Merge_Sort.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	in_place_merge_sort(num+1,num+n+1);
	for(int i=1;i<=n;i++)
		printf("%d ",num[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

