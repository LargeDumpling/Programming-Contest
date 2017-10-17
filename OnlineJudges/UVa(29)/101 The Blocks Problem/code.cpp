#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int n,vec[30][30];
void find_block(const int &a,int &p,int &b)
{
	for(p=0;p<n;p++)
		for(b=1;b<=vec[p][0];b++)
			if(vec[p][b]==a)
				return;
	return;
}
void clear(const int &p,const int &h)
{
	int t;
	for(int i=h+1;i<=vec[p][0];i++)
	{
		t=vec[p][i];
		vec[t][++vec[t][0]]=t;
	}
	vec[p][0]=h;
	return;
}
void pile(const int &p1,const int &p2,const int &h)
{
	for(int i=h;i<=vec[p2][0];i++)
		vec[p1][++vec[p1][0]]=vec[p2][i];
	vec[p2][0]=h-1;
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,p1,p2,h1,h2;
	char tex1[6],tex2[6];
	scanf("%d",&n);
	for(int i=0;i<n;i++)vec[i][++vec[i][0]]=i;
	for(int k=1;;k++)
	{
		scanf("%s",tex1);
		if(tex1[1]=='u')
			break;
		scanf("%d%s%d",&a,tex2,&b);
		find_block(a,p1,h1);
		find_block(b,p2,h2);
		if(p1==p2)
			continue;
		if(tex1[1]=='o')clear(p1,h1);
		if(tex2[1]=='n')clear(p2,h2);
		pile(p2,p1,h1);
	}
	for(int i=0;i<n;i++)
	{
		printf("%d:",i);
		if(vec[i][0])
			for(int j=1;j<=vec[i][0];j++)
				printf(" %d",vec[i][j]);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
