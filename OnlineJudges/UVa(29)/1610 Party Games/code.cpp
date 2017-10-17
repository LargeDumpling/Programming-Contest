/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History: 
    2015-11-25    File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
string name[1050];
void solve(const string &A,const string &B)
{
	char ch[35];
	for(int i=0;;i++)
	{
		if(A[i]!=B[i])
		{
			if(i+1==A.size())
				printf("%c",A[i]);
			else if(B[i]-A[i]>1||i+1!=B.size())
				printf("%c",A[i]+1);
			else
			{
				printf("%c",A[i]);
				for(int j=i+1;j<A.size();j++)
				{
					if(j+1==A.size())
					{
						printf("%c",A[j]);
						return;
					}
					else if(A[j]!='Z')
					{
						printf("%c",A[j]+1);
						return;
					}
					printf("Z");
				}
			}
			return;
		}
		printf("%c",A[i]);
	}
	return;
}
int main()
{
    freopen("code.in","r",stdin);
    freopen("code.out","w",stdout);
	while(scanf("%d",&n)==1&&n)
	{
		for(int i=1;i<=n;i++)cin>>name[i];
		sort(name+1,name+n+1);n>>=1;
		solve(name[n],name[n+1]);
		printf("\n");
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

