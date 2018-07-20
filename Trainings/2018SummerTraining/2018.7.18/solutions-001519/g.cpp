#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(x) (x).begin(),(x).end()
#define VAR(v,init) __typeof(init) v=init
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)

template<class T>
inline int size(const T&a) { return a.size(); }

const double EPS = 1e-3;

/////////////////////////////////////////

double sq(double x) {
    return x*x;
}

bool almost_equal(double a, double b) {
    if (a > b + EPS) return false;
    if (b > a + EPS) return false;
    return true;
}

/////////////// points and operations on them ////////////////////

typedef pair<double,double> Point;

Point midpoint(Point u, Point v) {
    return Point((u.first + v.first)/2, (u.second + v.second)/2);
}

double dist_sq(Point u, Point v) {
    return sq(u.first-v.first) + sq(u.second-v.second);
}


///////////// vectors and operations on them ////////////////////

typedef pair<double,double> Vector;

Vector create_vector(Point u, Point w) {
    return Vector(w.first - u.first, w.second - u.second);
}

Vector perpendicular(Vector v) {
    return Vector(v.second,-v.first);
}

////////////// intersection of two lines

Point intersection(Point a, Vector va, Point b, Vector vb) {
    double t = (a.first - b.first) * va.second - (a.second - b.second) * va.first;
    t /= vb.first * va.second - vb.second * va.first;
    return Point(b.first + t * vb.first, b.second + t * vb.second);
}

//////////// circles

struct Circle {
    Point center;
    double r_sq;
    
    bool contains(Point p) {
	return dist_sq(center,p) <= r_sq + EPS;
    }
    
    void verify_on_the_circle(Point p) {
	if (!almost_equal(dist_sq(p,center),r_sq)) {
	    printf("ERROR: point not on a circle!!!\n");
	    exit(1);
	}
    }
    
    Circle(Point c, Point b) {
	center = c;
	r_sq = dist_sq(c,b);
    }

    Circle() {}
};


/////////// circle on given points

Circle circumcircle(const vector<Point> &p, int k) {
    Circle solution;
    if (k<0) {
	printf("Error: circle on <0 points\n");
	exit(1);
    } else if (k==0) {
	solution = Circle(Point(0,0),Point(0,0));
    } else if (k==1) {
	solution = Circle(p[0],p[0]);
    } else if (k==2) {
	solution = Circle(midpoint(p[0],p[1]),p[0]);
    } else if (k==3) {
	Point m1 = midpoint(p[0],p[1]);
	Vector v1 = perpendicular(create_vector(p[0],p[1]));
	Point m2 = midpoint(p[1],p[2]);
	Vector v2 = perpendicular(create_vector(p[1],p[2]));
	solution = Circle(intersection(m1,v1,m2,v2), p[0]);
    } else {
	printf("Error: circle on >3 points\n");
	exit(1);
    }
    REP(i,k) solution.verify_on_the_circle(p[i]);
    return solution;
}

Circle find_circle(vector<Point> &points, int known, int length) {
    Circle c = circumcircle(points, known);
    FOR(i, known, length-1) {
	int random_index = i + rand() % (length - i);
	swap(points[i], points[random_index]);
	if (not c.contains(points[i])) {
	    swap(points[known],points[i]);
	    c = find_circle(points, known + 1, i + 1);
	}
    }
    return c;
}

int main() {
    srand(192343);
	vector<Point> points;

	int T;
	scanf("%d",&T);
	int n;
	scanf("%d",&n);
	
	REP(i,n) {
	    int a, b;
	    scanf("%d%d", &a, &b);
	    points.push_back(Point(b,a*T+b));
	}
	Circle all = find_circle(points,0,size(points));
	printf("%.2f\n",all.r_sq);
}