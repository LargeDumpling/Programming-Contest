const double eps = 1e-8;
//const double pi = std::acos(-1.0);
//��
class Point
{
public:
    double x, y;
    Point(){};
    Point(double x, double y):x(x),y(y){};

    static double xmult(const Point &ps, const Point &pe, const Point &po)
    {
        return (ps.x - po.x) * (pe.y - po.y) - (pe.x - po.x) * (ps.y - po.y);
    }

    //���ԭ��Ĳ�˽������������[_Off]
    //����ԭ�������������ɵ�ƽ���ı������
    double operator *(const Point &_Off) const
    {
        return x * _Off.y - y * _Off.x;
    }
    //���ƫ��
    Point operator - (const Point &_Off) const
    {
        return Point(x - _Off.x, y - _Off.y);
    }
        //���ƫ��
    Point operator + (const Point &_Off) const
    {
        return Point(x + _Off.x, y + _Off.y);
    }
    //��λ����ͬ(double����)
    bool operator == (const Point &_Off) const
    {
        return std::fabs(_Off.x - x) < eps && std::fabs(_Off.y - y) < eps;
    }
    //��λ�ò�ͬ(double����)
    bool operator != (const Point &_Off) const
    {
        return ((*this) == _Off) == false;
    }
    //���������ƽ��
    double dis2(const Point &_Off) const
    {
        return (x - _Off.x) * (x - _Off.x) + (y - _Off.y) * (y - _Off.y);
    }
    //��������
    double dis(const Point &_Off) const
    {
        return std::sqrt((x - _Off.x) * (x - _Off.x) + (y - _Off.y) * (y - _Off.y));
    }
    Point rotate(double theta) {
        //x*cosA-y*sinA  x*sinA+y*cosA
        return Point(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta));
    }
    void debug() {
        printf("%.8f %.8f\n", x, y);
    }
};

//�����ʾ������
class PVector
{
public:
    Point s, e;//�����ʾ�����[s]���յ�[e]
    double a, b, c;//һ��ʽ,ax+by+c=0

    PVector(){}
    PVector(const Point &s, const Point &e):s(s),e(e){}

    void debug() {
        printf("(%.8f, %.8f) -> (%.8f, %.8f)\n", s.x, s.y, e.x, e.y);
    }
    //�������Ĳ��,��������[_Off]
    //[���������λ���ж�]
    double operator *(const Point &_Off) const
    {
        return (_Off.y - s.y) * (e.x - s.x) - (_Off.x - s.x) * (e.y - s.y);
    }
    //�����������Ĳ��,����������[_Off]
    double operator *(const PVector &_Off) const
    {
        return (e.x - s.x) * (_Off.e.y - _Off.s.y) - (e.y - s.y) * (_Off.e.x - _Off.s.x);
    }
    //�������ʾת��Ϊһ���ʾ
    bool pton()
    {
        a = s.y - e.y;
        b = e.x - s.x;
        c = s.x * e.y - s.y * e.x;
        return true;
    }

    //-----------���ֱ�ߣ�������-----------
    //����������ߣ��ұߵ�С�ںŸĳɴ��ںż���,�ڶ�Ӧֱ���������=�ţ�
    //��������[_Off],����[_Ori]
    friend bool operator<(const Point &_Off, const PVector &_Ori)
    {
        return (_Ori.e.y - _Ori.s.y) * (_Off.x - _Ori.s.x)
            < (_Off.y - _Ori.s.y) * (_Ori.e.x - _Ori.s.x);
    }

    friend bool operator>(const Point &_Off, const PVector &_Ori)
    {
        return (_Ori.e.y - _Ori.s.y) * (_Off.x - _Ori.s.x)
             > (_Off.y - _Ori.s.y) * (_Ori.e.x - _Ori.s.x);
    }

    //����ֱ����,��������[_Off]
    bool lhas(const Point &_Off) const
    {
        return std::fabs((*this) * _Off) < eps;
    }
    //�����߶���,��������[_Off]
    bool shas(const Point &_Off) const
    {
        return lhas(_Off)
            && _Off.x - std::min(s.x, e.x) > -eps && _Off.x - std::max(s.x, e.x) < eps
            && _Off.y - std::min(s.y, e.y) > -eps && _Off.y - std::max(s.y, e.y) < eps;
    }

    //�㵽ֱ��/�߶εľ���
    //������ ��[_Off], �Ƿ����߶�[isSegment](Ĭ��Ϊֱ��)
    double dis(const Point &_Off, bool isSegment = false)
    {
        //��Ϊһ��ʽ
        pton();

        //��ֱ�ߴ���ľ���
        double td = (a * _Off.x + b * _Off.y + c) / sqrt(a * a + b * b);

        //������߶��жϴ���
        if(isSegment)
        {
            double xp = (b * b * _Off.x - a * b * _Off.y - a * c) / ( a * a + b * b);
            double yp = (-a * b * _Off.x + a * a * _Off.y - b * c) / (a * a + b * b);
            double xb = std::max(s.x, e.x);
            double yb = std::max(s.y, e.y);
            double xs = s.x + e.x - xb;
            double ys = s.y + e.y - yb;
            if(xp > xb + eps || xp < xs - eps || yp > yb + eps || yp < ys - eps)
                td = std::min(_Off.dis(s), _Off.dis(e));
        }

        return fabs(td);
    }

    //����ֱ�߶ԳƵĵ�
    Point mirror(const Point &_Off) const
    {
        //ע����תΪһ��ʽ
        Point ret;
        double d = a * a + b * b;
        ret.x = (b * b * _Off.x - a * a * _Off.x - 2 * a * b * _Off.y - 2 * a * c) / d;
        ret.y = (a * a * _Off.y - b * b * _Off.y - 2 * a * b * _Off.x - 2 * b * c) / d;
        return ret;
    }
    //����������д���
    static PVector ppline(const Point &_a, const Point &_b)
    {
        PVector ret;
        ret.s.x = (_a.x + _b.x) / 2;
        ret.s.y = (_a.y + _b.y) / 2;
        //һ��ʽ
        ret.a = _b.x - _a.x;
        ret.b = _b.y - _a.y;
        ret.c = (_a.y - _b.y) * ret.s.y + (_a.x - _b.x) * ret.s.x;
        //����ʽ
        if(std::fabs(ret.a) > eps)
        {
            ret.e.y = 0.0;
            ret.e.x = - ret.c / ret.a;
            if(ret.e == ret. s)
            {
                ret.e.y = 1e10;
                ret.e.x = - (ret.c - ret.b * ret.e.y) / ret.a;
            }
        }
        else
        {
            ret.e.x = 0.0;
            ret.e.y = - ret.c / ret.b;
            if(ret.e == ret. s)
            {
                ret.e.x = 1e10;
                ret.e.y = - (ret.c - ret.a * ret.e.x) / ret.b;
            }
        }
        return ret;
    }

    //------------ֱ�ߺ�ֱ�ߣ�������-------------
    //ֱ���غ�,������ֱ������[_Off]
    bool equal(const PVector &_Off) const
    {
        return lhas(_Off.e) && lhas(_Off.s);
    }
    //ֱ��ƽ�У�������ֱ������[_Off]
    bool parallel(const PVector &_Off) const
    {
        return std::fabs((*this) * _Off) < eps;
    }
    //��ֱ�߽��㣬������Ŀ��ֱ��[_Off]
    Point crossLPt(PVector _Off)
    {
        //ע�����ж�ƽ�к��غ�
        Point ret = s;
        double t = ((s.x - _Off.s.x) * (_Off.s.y - _Off.e.y) - (s.y - _Off.s.y) * (_Off.s.x - _Off.e.x))
                / ((s.x - e.x) * (_Off.s.y - _Off.e.y) - (s.y - e.y) * (_Off.s.x - _Off.e.x));
        ret.x += (e.x - s.x) * t;
        ret.y += (e.y - s.y) * t;
        return ret;
    }

    //------------�߶κ�ֱ�ߣ�������----------
    //�߶κ�ֱ�߽�
    //�������߶�[_Off]
    bool crossSL(const PVector &_Off) const
    {
        double rs = (*this) * _Off.s;
        double re = (*this) * _Off.e;
        return rs * re < eps;
    }

    //------------�߶κ��߶Σ�������----------
    //�ж��߶��Ƿ��ཻ(ע�����eps)���������߶�[_Off]
    bool isCrossSS(const PVector &_Off) const
    {
        //1.�����ų������ж��������߶�Ϊ�Խ��ߵ����������Ƿ��ཻ
        //2.�������飨����0ʱ�˵��غϣ�
        return (
            (std::max(s.x, e.x) >= std::min(_Off.s.x, _Off.e.x)) &&
            (std::max(_Off.s.x, _Off.e.x) >= std::min(s.x, e.x)) &&
            (std::max(s.y, e.y) >= std::min(_Off.s.y, _Off.e.y)) &&
            (std::max(_Off.s.y, _Off.e.y) >= std::min(s.y, e.y)) &&
            ((PVector(_Off.s, s) * _Off) * (_Off * PVector(_Off.s, e)) >= 0.0) &&
            ((PVector(s, _Off.s) * (*this)) * ((*this) * PVector(s, _Off.e)) >= 0.0)
            );
    }
};

class Polygon
{
public:
    const static long maxpn = 10010;
    Point pt[maxpn];//�㣨˳ʱ�����ʱ�룩
    long n;//��ĸ���

    Point& operator[](int _p)
    {
        return pt[_p];
    }

    //�����������������ڵ����˳ʱ�����ʱ��
    double area() const
    {
        double ans = 0.0;
        int i;
        for(i = 0; i < n; i ++)
        {
            int nt = (i + 1) % n;
            ans += pt[i].x * pt[nt].y - pt[nt].x * pt[i].y;
        }
        return std::fabs(ans / 2.0);
    }
    //���������ģ�������ڵ����˳ʱ�����ʱ��
    Point gravity() const
    {
        Point ans;
        ans.x = ans.y = 0.0;
        int i;
        double area = 0.0;
        for(i = 0; i < n; i ++)
        {
            int nt = (i + 1) % n;
            double tp = pt[i].x * pt[nt].y - pt[nt].x * pt[i].y;
            area += tp;
            ans.x += tp * (pt[i].x + pt[nt].x);
            ans.y += tp * (pt[i].y + pt[nt].y);
        }
        ans.x /= 3 * area;
        ans.y /= 3 * area;
        return ans;
    }
    Point centroid() const
    {
        Point ans;
        ans.x = ans.y = 0.0;
        int i;
        double area = 0.0;
        double bx = pt[0].x;
        double by = pt[0].y;
        for(i = 0; i < n; i ++)
        {
            int nt = (i + 1) % n;
            double tp = (pt[i].x - bx) * (pt[nt].y - by) - (pt[nt].x - bx) * (pt[i].y - by);
            area += tp;
            ans.x += tp * (pt[i].x + pt[nt].x - 2 * bx);
            ans.y += tp * (pt[i].y + pt[nt].y - 2 * by);
        }
        ans.x /= 3 * area;
        ans.y /= 3 * area;
        ans.x += bx;
        ans.y += by;
        return ans;
    }
    //�жϵ���͹������ڣ���������[_Off]
    bool chas(const Point &_Off) const
    {
        double tp = 0, np;
        int i;
        for(i = 0; i < n; i ++)
        {
            np = PVector(pt[i], pt[(i + 1) % n]) * _Off;
            if(tp * np < -eps)
                return false;
            tp = (std::fabs(np) > eps)?np: tp;
        }
        return true;
    }
    //�жϵ��Ƿ�������������[���߷�]��O(n)
    bool ahas(const Point &_Off) const
    {
        int ret = 0;
        double infv = 1e-10;//����ϵ���Χ
        PVector l = PVector(_Off, Point( -infv ,_Off.y));
        for(int i = 0; i < n; i ++)
        {
            PVector ln = PVector(pt[i], pt[(i + 1) % n]);
            if(fabs(ln.s.y - ln.e.y) > eps)
            {
                Point tp = (ln.s.y > ln.e.y)? ln.s: ln.e;
                if(fabs(tp.y - _Off.y) < eps && tp.x < _Off.x + eps)
                    ret ++;
            }
            else if(ln.isCrossSS(l))
                ret ++;
        }
        return (ret % 2 == 1);
    }
    //͹����α�ֱ�߷ָ�,������ֱ��[_Off]
    Polygon split(PVector _Off)
    {
        //ע��ȷ��������ܱ��ָ�
        Polygon ret;
        Point spt[2];
        double tp = 0.0, np;
        bool flag = true;
        int i, pn = 0, spn = 0;
        for(i = 0; i < n; i ++)
        {
            if(flag)
                pt[pn ++] = pt[i];
            else
                ret.pt[ret.n ++] = pt[i];
            np = _Off * pt[(i + 1) % n];
            if(tp * np < -eps)
            {
                flag = !flag;
                spt[spn ++] = _Off.crossLPt(PVector(pt[i], pt[(i + 1) % n]));
            }
            tp = (std::fabs(np) > eps)?np: tp;
        }
        ret.pt[ret.n ++] = spt[0];
        ret.pt[ret.n ++] = spt[1];
        n = pn;
        return ret;
    }

    //-------------͹��-------------
    //Grahamɨ�跨�����Ӷ�O(nlg(n)),���Ϊ��ʱ��
    //#include <algorithm>
    static bool graham_cmp(const Point &l, const Point &r)//͹��������
    {
        return l.y < r.y || (l.y == r.y && l.x < r.x);
    }
    Polygon& graham(Point _p[], int _n)
    {
        int i, len;
        std::sort(_p, _p + _n, Polygon::graham_cmp);
        n = 1;
        pt[0] = _p[0], pt[1] = _p[1];
        for(i = 2; i < _n; i ++)
        {
            while(n && Point::xmult(_p[i], pt[n], pt[n - 1]) >= 0)
                n --;
            pt[++ n] = _p[i];
        }
        len = n;
        pt[++ n] = _p[_n - 2];
        for(i = _n - 3; i >= 0; i --)
        {
            while(n != len && Point::xmult(_p[i], pt[n], pt[n - 1]) >= 0)
                n --;
            pt[++ n] = _p[i];
        }
        return (*this);
    }

    //͹����ת����(ע������˳ʱ�����ʱ������)
    //����ֵ͹��ֱ����ƽ������Զ��������ƽ����
    double rotating_calipers()
    {
        int i = 1;
        double ret = 0.0;
        pt[n] = pt[0];
        for(int j = 0; j < n; j ++)
        {
            while(fabs(Point::xmult(pt[j], pt[j + 1], pt[i + 1])) > fabs(Point::xmult(pt[j], pt[j + 1], pt[i])) + eps)
                i = (i + 1) % n;
            //pt[i]��pt[j],pt[i + 1]��pt[j + 1]�����Ƕ����
            ret = std::max(ret, std::max(pt[i].dis(pt[j]), pt[i + 1].dis(pt[j + 1])));
        }
        return ret;
    }

    //͹����ת����(ע��������ʱ������)
    //����ֵ��͹������̾���
    double rotating_calipers(Polygon &_Off)
    {
        int i = 0;
        double ret = 1e10;//inf
        pt[n] = pt[0];
        _Off.pt[_Off.n] = _Off.pt[0];
        //ע��͹��������ʱ��������pt[0]�����½ǵ��λ��
        while(_Off.pt[i + 1].y > _Off.pt[i].y)
            i = (i + 1) % _Off.n;
        for(int j = 0; j < n; j ++)
        {
            double tp;
            //��ʱ��ʱΪ >,˳ʱ�����෴
            while((tp = Point::xmult(pt[j], pt[j + 1], _Off.pt[i + 1]) - Point::xmult( pt[j], pt[j + 1], _Off.pt[i])) > eps)
                i = (i + 1) % _Off.n;
            //(pt[i],pt[i+1])��(_Off.pt[j],_Off.pt[j + 1])����������߶�
            ret = std::min(ret, PVector(pt[j], pt[j + 1]).dis(_Off.pt[i], true));
            ret = std::min(ret, PVector(_Off.pt[i], _Off.pt[i + 1]).dis(pt[j + 1], true));
            if(tp > -eps)//���������TLE������ò�Ҫ������ж�
            {
                ret = std::min(ret, PVector(pt[j], pt[j + 1]).dis(_Off.pt[i + 1], true));
                ret = std::min(ret, PVector(_Off.pt[i], _Off.pt[i + 1]).dis(pt[j], true));
            }
        }
        return ret;
    }

    //-----------��ƽ�潻-------------
    //���Ӷ�:O(nlog2(n))
    //#include <algorithm>
    //��ƽ����㼫�Ǻ���[�������Ч�ʿ����ó�Ա������¼]
    static double hpc_pa(const PVector &_Off)
    {
        return atan2(_Off.e.y - _Off.s.y, _Off.e.x - _Off.s.x);
    }
    //��ƽ�潻������[����˳��: 1.���� 2.ǰ���ֱ���ں�������]
    static bool hpc_cmp(const PVector &l, const PVector &r)
    {
        double lp = hpc_pa(l), rp = hpc_pa(r);
        if(fabs(lp - rp) > eps)
            return lp < rp;
        return Point::xmult(l.s, r.e, r.s) < 0.0;
    }
    //���ڼ����˫�˶���
    PVector dequeue[maxpn];
    //��ȡ��ƽ�潻�Ķ���Σ�����εĺˣ�
    //��������������[l]����������[ln];(��ƽ�淽����������ߣ�
    //�������к����n[�����ض���εĵ�����]Ϊ0�򲻴��ڰ�ƽ�潻�Ķ���Σ������������������������
    Polygon& halfPanelCross(PVector _Off[], int ln)
    {
        int i, tn;
        n = 0;
        std::sort(_Off, _Off + ln, hpc_cmp);
        //ƽ����������ߵ�ɸѡ
        for(i = tn = 1; i < ln; i ++)
            if(fabs(hpc_pa(_Off[i]) - hpc_pa(_Off[i - 1])) > eps)
                _Off[tn ++] = _Off[i];
        ln = tn;
        int bot = 0, top = 1;
        dequeue[0] = _Off[0];
        dequeue[1] = _Off[1];
        for(i = 2; i < ln; i ++)
        {
            if(dequeue[top].parallel(dequeue[top - 1]) ||
                dequeue[bot].parallel(dequeue[bot + 1]))
                return (*this);
            while(bot < top &&
                Point::xmult(dequeue[top].crossLPt(dequeue[top - 1]), _Off[i].e, _Off[i].s) > eps)
                top --;
            while(bot < top &&
                Point::xmult(dequeue[bot].crossLPt(dequeue[bot + 1]), _Off[i].e, _Off[i].s) > eps)
                bot ++;
            dequeue[++ top] = _Off[i];
        }

        while(bot < top &&
            Point::xmult(dequeue[top].crossLPt(dequeue[top - 1]), dequeue[bot].e, dequeue[bot].s) > eps)
            top --;
        while(bot < top &&
            Point::xmult(dequeue[bot].crossLPt(dequeue[bot + 1]), dequeue[top].e, dequeue[top].s) > eps)
            bot ++;
        //���㽻��(ע�ⲻֱͬ���γɵĽ�������غ�)
        if(top <= bot + 1)
            return (*this);
        for(i = bot; i < top; i ++)
            pt[n ++] = dequeue[i].crossLPt(dequeue[i + 1]);
        if(bot < top + 1)
            pt[n ++] = dequeue[bot].crossLPt(dequeue[top]);
        return (*this);
    }
};
class Circle
{
public:
    Point c;//Բ��
    double r;//�뾶
    double db, de;//Բ��������㣬 Բ�������յ�(��ʱ��0-360)

    //-------Բ---------

    //�ж�Բ�ڶ������
    bool inside(const Polygon &_Off) const
    {
        if(_Off.ahas(c) == false)
            return false;
        for(int i = 0; i < _Off.n; i ++)
        {
            PVector l = PVector(_Off.pt[i], _Off.pt[(i + 1) % _Off.n]);
            if(l.dis(c, true) < r - eps)
                return false;
        }
        return true;
    }

    //�ж϶������Բ�ڣ��߶κ��������ƣ�
    bool has(const Polygon &_Off) const
    {
        for(int i = 0; i < _Off.n; i ++)
            if(_Off.pt[i].dis2(c) > r * r - eps)
                return false;
        return true;
    }

    //-------Բ��-------
    //Բ������Բ�صõ�Բ����������Բ[_Off]
    Circle operator-(Circle &_Off) const
    {
        //ע��Բ�����ཻ��Բ�Ĳ����غ�
        double d2 = c.dis2(_Off.c);
        double d = c.dis(_Off.c);
        double ans = std::acos((d2 + r * r - _Off.r * _Off.r) / (2 * d * r));
        Point py = _Off.c - c;
        double oans = std::atan2(py.y, py.x);
        Circle res;
        res.c = c;
        res.r = r;
        res.db = oans + ans;
        res.de = oans - ans + 2 * pi;
        return res;
    }
    //Բ������Բ�صõ�Բ����������Բ[_Off]
    Circle operator+(Circle &_Off) const
    {
        //ע��Բ�����ཻ��Բ�Ĳ����غ�
        double d2 = c.dis2(_Off.c);
        double d = c.dis(_Off.c);
        double ans = std::acos((d2 + r * r - _Off.r * _Off.r) / (2 * d * r));
        Point py = _Off.c - c;
        double oans = std::atan2(py.y, py.x);
        Circle res;
        res.c = c;
        res.r = r;
        res.db = oans - ans;
        res.de = oans + ans;
        return res;
    }

    //��Բ��һ�����������
    //��������[_Off](������Բ��),���أ���������(���ߵ�s��Ϊ_Off,e��Ϊ�е�)
    std::pair<PVector, PVector>  tangent(const Point &_Off) const
    {
        double d = c.dis(_Off);
        //����Ƕ�ƫ�Ƶķ�ʽ
        double angp = std::acos(r / d), ango = std::atan2(_Off.y - c.y, _Off.x - c.x);
        Point pl = Point(c.x + r * std::cos(ango + angp), c.y + r * std::sin(ango + angp)),
            pr = Point(c.x + r * std::cos(ango - angp), c.y + r * std::sin(ango - angp));
        return std::make_pair(PVector(_Off, pl), PVector(_Off, pr));
    }

    //����ֱ�ߺ�Բ����������
    //������ֱ��[_Off](����ʽ)�������������㣬ע��ֱ�߱����Բ����������
    std::pair<Point, Point> cross(PVector _Off) const
    {
        _Off.pton();
        //��ֱ�ߴ���ľ���
        double td = fabs(_Off.a * c.x + _Off.b * c.y + _Off.c) / sqrt(_Off.a * _Off.a + _Off.b * _Off.b);

        //���㴹������
        double xp = (_Off.b * _Off.b * c.x - _Off.a * _Off.b * c.y - _Off.a * _Off.c) / ( _Off.a * _Off.a + _Off.b * _Off.b);
        double yp = (- _Off.a * _Off.b * c.x + _Off.a * _Off.a * c.y - _Off.b * _Off.c) / (_Off.a * _Off.a + _Off.b * _Off.b);

        double ango = std::atan2(yp - c.y, xp - c.x);
        double angp = std::acos(td / r);

        return std::make_pair(Point(c.x + r * std::cos(ango + angp), c.y + r * std::sin(ango + angp)),
            Point(c.x + r * std::cos(ango - angp), c.y + r * std::sin(ango - angp)));
    }
};

class Triangle
{
public:
    Point a, b, c;//����
    Triangle(){}
    Triangle(Point a, Point b, Point c): a(a), b(b), c(c){}

    //�������������
    double area()
    {
        return fabs(Point::xmult(a, b, c)) / 2.0;
    }

    //��������������
    //���أ����ԲԲ��
    Point circumcenter()
    {
        PVector u,v;
        u.s.x = (a.x + b.x) / 2;
        u.s.y = (a.y + b.y) / 2;
        u.e.x = u.s.x - a.y + b.y;
        u.e.y = u.s.y + a.x - b.x;
        v.s.x = (a.x + c.x) / 2;
        v.s.y = (a.y + c.y) / 2;
        v.e.x = v.s.x - a.y + c.y;
        v.e.y = v.s.y + a.x - c.x;
        return u.crossLPt(v);
    }

    //��������������
    //���أ��ڽ�ԲԲ��
    Point incenter()
    {
        PVector u, v;
        double m, n;
        u.s = a;
        m = atan2(b.y - a.y, b.x - a.x);
        n = atan2(c.y - a.y, c.x - a.x);
        u.e.x = u.s.x + cos((m + n) / 2);
        u.e.y = u.s.y + sin((m + n) / 2);
        v.s = b;
        m = atan2(a.y - b.y, a.x - b.x);
        n = atan2(c.y - b.y, c.x - b.x);
        v.e.x = v.s.x + cos((m + n) / 2);
        v.e.y = v.s.y + sin((m + n) / 2);
        return u.crossLPt(v);
    }

    //���������δ���
    //���أ��ߵĽ���
    Point perpencenter()
    {
        PVector u,v;
        u.s = c;
        u.e.x = u.s.x - a.y + b.y;
        u.e.y = u.s.y + a.x - b.x;
        v.s = b;
        v.e.x = v.s.x - a.y + c.y;
        v.e.y = v.s.y + a.x - c.x;
        return u.crossLPt(v);
    }

    //��������������
    //���أ�����
    //������������������ƽ������С�ĵ�
    //�������ڵ����߾���֮�����ĵ�
    Point barycenter()
    {
        PVector u,v;
        u.s.x = (a.x + b.x) / 2;
        u.s.y = (a.y + b.y) / 2;
        u.e = c;
        v.s.x = (a.x + c.x) / 2;
        v.s.y = (a.y + c.y) / 2;
        v.e = b;
        return u.crossLPt(v);
    }

    //���������η����
    //���أ������������������֮����С�ĵ�
    Point fermentPoint()
    {
        Point u, v;
        double step = fabs(a.x) + fabs(a.y) + fabs(b.x) + fabs(b.y) + fabs(c.x) + fabs(c.y);
        int i, j, k;
        u.x = (a.x + b.x + c.x) / 3;
        u.y = (a.y + b.y + c.y) / 3;
        while (step > eps)
        {
            for (k = 0; k < 10; step /= 2, k ++)
            {
                for (i = -1; i <= 1; i ++)
                {
                    for (j = -1; j <= 1; j ++)
                    {
                        v.x = u.x + step * i;
                        v.y = u.y + step * j;
                        if (u.dis(a) + u.dis(b) + u.dis(c) > v.dis(a) + v.dis(b) + v.dis(c))
                            u = v;
                    }
                }
            }
        }
        return u;
    }
};

