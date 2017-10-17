#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,L,s[81],cnt;
void print(int len)
{
 	for(int i= 0; i < len; i++)
	{
   	   if(i % 64 == 0 && i > 0)
		   printf("\n");
   	   else if(i % 4 == 0 && i > 0)
		   printf(" ");
   	   printf("%c", 'A'+s[i+1]); // Êä³ö·½°¸
    }
    printf("\n%d\n", len);
    return;
}
bool check(int len)
{
	bool flag;
	for(int i=1;i+i<=len;i++)
	{
		flag=false;
		for(int j=0;j<i;j++)
		{
			if(s[len-j]!=s[len-i-j])
				flag=true;
		}
		if(!flag)
			return true;
	}
	return false;
}
bool DFS(int x)
{
	if(x==0)
	{
		for(int i=0;i<L;i++)
		{
			s[1]=i;
			if(DFS(1))
				return true;
		}
		return false;
	}
	if(++cnt==n)
	{
		print(x);
		return true;
	}
	for(int i=0;i<L;i++)
	{
		s[x+1]=i;
		if(check(x+1))
			continue;
		if(DFS(x+1))
			return true;
	}
	return false;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(scanf("%d%d",&n,&L)==2)
	{
		cnt=0;
		DFS(0);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

