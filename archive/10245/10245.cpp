#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

const int    MAX_N = 10000;
const double INF   = 10000.0;

struct Point
{
  double x, y;
  void read() { scanf("%lf %lf", &x, &y); }
  void print() { printf("(%.3f, %.3f)\n", x, y); }
};

int n; // number of points
vector<Point> p;   // the array of points
vector<Point> tmp; // array for merge sort

bool compareByX(const Point &A, const Point &B)
{
  if ( A.x != B.x ) return A.x < B.x;
  else              return A.y < B.y;
}

double dist(const Point &A, const Point &B)
{
  double dx = A.x - B.x;
  double dy = A.y - B.y;
  return sqrt(dx*dx + dy*dy);
}

bool readPoints()
{
  scanf("%d", &n);
  if ( n==0 ) 
    return false;
  else {
    p.clear();
    p.resize(n);
    for ( int i=0; i<n; ++i ) {
      p[i].read();
    }
    return true;
  }
}

double closestPair(int L, int R)
{
  double closest_dist = INF;
  if ( L==R ) { // 1 point
    closest_dist = INF;
  }
  else if ( L+1==R ) { // 2 points
    // sort py[]
    if ( p[L].y > p[R].y ) swap(p[L], p[R]);
    closest_dist = dist(p[L], p[R]);
  }
  else if ( L+2==R ) { // 3 points
    Point &A = p[L  ];
    Point &B = p[L+1];
    Point &C = p[L+2];
    double closest_dist = min( dist(A,B), min( dist(A,C), dist(B,C) ) );
    if ( p[L  ].y > p[L+1].y ) swap(p[L  ], p[L+1]);
    if ( p[L+1].y > p[L+2].y ) swap(p[L+1], p[L+2]);
    if ( p[L  ].y > p[L+1].y ) swap(p[L  ], p[L+1]);
  }
  else {
    int    M  = (L+R)/2;
    double Mx = p[M].x;
    double delta = min(closestPair(L  ,M),
		       closestPair(M+1,R));

    int i = L;
    int j = M+1;
    int k = 0;
    while ( i<=M && j<=R ) {
      if ( p[i].y <= p[j].y ) tmp[k++] = p[i++];
      else                    tmp[k++] = p[j++];
    }
    while ( i<=M ) tmp[k++] = p[i++];
    while ( j<=R ) tmp[k++] = p[j++];
    for ( int t=0; t<k; ++t ) p[L+t] = tmp[t];

/*
    for ( int t=0; t<k; ++t ) {
      printf("  tmp[%d] = ", t);
      tmp[t].print();
    }
*/

    vector<Point> strip;
    for ( int t=0; t<k; ++t )
      if ( fabs(Mx - tmp[t].x) <= delta )
	strip.push_back( tmp[t] );

    closest_dist = delta;
    for ( int t=0; t<strip.size(); ++t )
      for ( int s=t+1; s<=t+7 && s<strip.size(); ++s )
	closest_dist = min(closest_dist, dist(strip[t], strip[s]));
  }

/*
  printf("closest_dist(%d, %d) = %.3f\n", L, R, closest_dist);
  for ( int t=L; t<=R; ++t ) {
    printf("  ");
    p[t].print();
  }
  putchar('\n');
*/

  return closest_dist;
}

bool existsOverlapping()
{
  for ( int i=0; i<n-1; ++i ) {
    Point &A = p[ i ];
    Point &B = p[i+1];
    if ( A.x==B.x && A.y==B.y )
      return true;
  }
  return false;
}

int main()
{
  while ( readPoints() ) {
    sort(p.begin(), p.end(), compareByX);
    if ( existsOverlapping() ) {
      puts("0.0000");
    }
    else {
      tmp.clear();
      tmp.resize(n);
      double closest_dist = closestPair(0, n-1);
      if ( closest_dist < INF )
	printf("%.4f\n", closest_dist);
      else
	puts("INFINITY");
    }
  }
}
