/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
    2018-07-23    File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
struct jz
{
	int l,r;
	bool operator<(const jp &X)const
	{
	}
}s[MAXN];
int T_T,n,ans;
char str[MAXN];
int main()
{
    int len;
    scanf("%d",&T_T);
    while(T_T--)
    {
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            s[i].l=s[i].r=0;
            scanf("%s",str);
            len=strlen(str);
            int cnt=0;
            for(int j=0;j<len;j++)
            {
                if(cnt&&str[j]==')')
                {
                    cnt--;
                    ans++;
                }
                else if(!cnt&&str[j]==')')
                    s[i].l++;
                else if(str[j]=='(')
                    cnt++;
            }
            s[i].r=cnt;
        }
        sort(s+1,s+n+1,cmp);
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt<=s[i].l)
            {
                ans+=cnt;
                cnt=0;
            }
            else if(s[i].l<cnt)
            {
                ans+=s[i].l;
                cnt-=s[i].l;
            }
            cnt+=s[i].r;
        }
        printf("%d\n",ans*2);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

