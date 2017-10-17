#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int n,M,c,r,idx;
string word[105];
void write1n(const string &str)
{
	cout<<str;
	for(int i=M-str.length();i;i--)
		printf(" ");
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(true)
	{
		if(scanf("%d",&n)==-1)
			break;
		for(int i=1;i<=60;i++)putchar('-');
		putchar('\n');
		M=0;
		for(int i=1;i<=n;i++)
		{
			cin>>word[i];
			M=max(M,(int)word[i].length());
		}
		sort(word+1,word+n+1);
		c=(60-M)/(M+2)+1,r=(n-1)/c+1;
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				idx=(j-1)*r+i;
				if(idx>n)
					for(int k=(j==c)?M:M+2;k;k--)
						printf("  ");
				else
				{
					write1n(word[idx]);
					if(j!=c)
						printf("  ");
				}
			}
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

