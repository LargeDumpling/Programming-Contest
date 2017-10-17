#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAX 210
using namespace std;
const double eps = 1E-8;
int sig(double d)
{
    return (d > eps) - (d < -eps);
}
struct Point
{
    double x,y;

};
Point point[MAX];
int n;

double cross(const Point& o,const Point& a,const Point &b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

//判断直线ab是否与线段cd相交
//0 不相交
//1 规范相交
//2 不规范相交
int segLineCross(const Point& a,const Point& b,const Point& c,const Point& d)
{
    int d1,d2;
    d1 = sig(cross(a,b,c));//模板抄错了，忘了sig函数

    d2 = sig(cross(a,b,d));//同上
    if((d1^d2)==-2)//注意加小括号，^的优先级比==低
        return 1;
    if(d1==0||d2 == 0)
        return 2;
    return 0;
}

bool Test(const Point & a,const Point &b)//判断直线ab是否与所有线段相交
{
    if(sig(a.x-b.x)==0 && sig(a.y-b.y)==0)//判断重复点
        return false;
    for(int i = 1; i <2*n; i+=2)
        if(segLineCross(a,b,point[i],point[i+1])==0)
            return false;
    return true;
}

bool Find()
{
    for(int i = 1; i < 2 * n; i++)
        for(int j = i + 1; j <=2 * n; j++)
            if(Test(point[i],point[j]))//应该是i和j错写成i和i+1了 ，悲剧
                return true;
    return false;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <=2 * n; i++)
        {
            cin >> point[i].x >> point[i].y;
        }

        if(Find())
            cout << "Yes!" << endl;
        else
            cout << "No!" << endl;

    }
    return 0;
}

