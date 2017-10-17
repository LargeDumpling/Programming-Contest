#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define min(a,b) (a<b?a:b)
using namespace std;
const int len=1000050;
char A[len];
char B[2*len];
int p[2*len],n,m,r,id,longest;
int JP()
{	
	memset(B,'\0',sizeof(B));
	n=strlen(A);
	r=id=longest=0;
	memset(p,0,sizeof(p));
	for(int i=0;i<n;i++)
	{
		B[2*i]='#';
		B[2*i+1]=A[i];
	}
	m=2*n;
	B[0]='@';
	B[m]='#';
	for(int i=1;i<=m;i++)
	{
		if(r>i)
			p[i]=min(p[2*id-i],r-i);
		else
			p[i]=0;
		while(B[i-p[i]-1]==B[i+p[i]+1])
			p[i]++;
		if(i+p[i]>r)
		{
			r=i+p[i];
			id=i;
		}
	}
	for(int i=0;i<=m;i++)
		if(i&1 && ((p[i]/2)*2+1)>longest)
			longest=(p[i]/2)*2+1;
		else if(!(i&1) && ((p[i]+1)/2)*2>longest)
			longest=((p[i]+1)/2)*2;
	return longest;
}
bool strcnmp(char a[],char b[])
{
	int n=strlen(a),m=strlen(b);
	if(n!=m)
		return false;
	for(int i=0;i<n;i++)
		if(a[i]!=b[i])
			return false;
	return true;
}
int main()
{
	char end[]="END";
	for(int i=1;;i++)
	{
		memset(A,'\0',sizeof(A));
		scanf("%s",A);
		if(strcnmp(A,end))
			break;
		printf("Case %d: %d\n",i,JP());
	}
	return 0;
}

