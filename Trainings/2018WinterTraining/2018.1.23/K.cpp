/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char str[26][10]={
	".-"
		,"-..."
		,"-.-."
		,"-.."
		,"."
		,"..-."
		,"--."
		,"...."
		,".."
		,".---"
		,"-.-"
		,".-.."
		,"--"
		,"-."
		,"---"
		,".--."
		,"--.-"
		,".-."
		,"..."
		,"-"
		,"..-"
		,"...-"
		,".--"
		,"-..-"
		,"-.--"
		,"--.."};
char T[1050];
int len;
int main()
{
	int l,r;
	bool flag;
	while(gets(T+1))
	{
		len=strlen(T+1);
		T[0]=T[len+1]='/';
		l=r=0;
		while(l<=len)
		{
			for(r=l+1;r<=len+1;r++)
				if(T[r]=='/')
					break;
			if(r==l+1) putchar(' ');
			else for(int i=0,j;i<26;i++)
			{
				flag=true;
				for(j=0;flag&&j<r-l-1;j++)
					if(T[l+j+1]!=str[i][j])
						flag=false;
				if(flag&&str[i][j]=='\0')
				{
					putchar('A'+i);
					break;
				}
			}
			l=r;
		}
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
