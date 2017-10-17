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

//�ж�ֱ��ab�Ƿ����߶�cd�ཻ
//0 ���ཻ
//1 �淶�ཻ
//2 ���淶�ཻ
int segLineCross(const Point& a,const Point& b,const Point& c,const Point& d)
{
    int d1,d2;
    d1 = sig(cross(a,b,c));//ģ�峭���ˣ�����sig����

    d2 = sig(cross(a,b,d));//ͬ��
    if((d1^d2)==-2)//ע���С���ţ�^�����ȼ���==��
        return 1;
    if(d1==0||d2 == 0)
        return 2;
    return 0;
}

bool Test(const Point & a,const Point &b)//�ж�ֱ��ab�Ƿ��������߶��ཻ
{
    if(sig(a.x-b.x)==0 && sig(a.y-b.y)==0)//�ж��ظ���
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
            if(Test(point[i],point[j]))//Ӧ����i��j��д��i��i+1�� ������
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

