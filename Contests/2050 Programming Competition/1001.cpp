/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-04-13	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char str[100050];
int main()
{
	int T_T,len;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%s",str);
		len=strlen(str);
		if(len%4) puts("No");
		else
		{
			bool flag=true;
			for(int i=0;i<len&&flag;i++)
			{
				if(i%4==0&&str[i]!='2')
					flag=false;
				else if(i%4==1&&str[i]!='0')
					flag=false;
				else if(i%4==2&&str[i]!='5')
					flag=false;
				else if(i%4==3&&str[i]!='0')
					flag=false;
			}
			if(flag) puts("Yes");
			else puts("No");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

