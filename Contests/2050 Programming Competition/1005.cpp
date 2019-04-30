/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
    2019-04-13    File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,len;
char str[10050];
int main()
{
    int cnt,a,b,q;
	bool flag;
    scanf("%d",&T_T);
    while(T_T--)
    {
        scanf("%s",str);
        len=strlen(str);
        cnt=a=b=q=0;
		flag=false;
        for(int i=0;i<len;i++)
        {
            if(str[i]=='A') a++;
            else if(str[i]=='B') b++;
            else if(str[i]=='?') q++;
            if(a+q>=11&&2<=a+q-b)
                flag=true;
            if(b+q>=11&&2<=b+q-a)
                flag=true;
            if(flag)
            {
                cnt++;
                a=b=q=0;
                flag=false;
            }
        }
        printf("%d\n",cnt);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

