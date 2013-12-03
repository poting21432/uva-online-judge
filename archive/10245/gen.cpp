#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

struct Point
{
  double x, y;
  void read() { scanf("%lf %lf", &x, &y); }
  void print() { printf("(%.3f, %.3f)\n", x, y); }
};

double dist(const Point &A, const Point &B)
{
  double dx = A.x - B.x;
  double dy = A.y - B.y;
  return sqrt(dx*dx + dy*dy);
}

vector<Point> p;

double randomFloat()
{
  static bool first_called = true;
  if ( first_called ) {
    first_called = false;
    srand(time(NULL));
  }
  int k = rand() % 4000000;
  return (double)k / 100.0;
  //return rand() % 10;
}

int main()
{
  fprintf(stderr, "N = ");
  int N;
  scanf("%d", &N);
  printf("%d\n", N);
  for ( int i=0; i<N; ++i ) {
    double x = randomFloat();
    double y = randomFloat();
    Point Q;
    Q.x = x;
    Q.y = y;
    p.push_back(Q);
    printf("%.2f %.2f\n", x, y);
  }
  puts("0");

  double ans = 10000.0;
  for ( int i=0; i<N; ++i )
    for ( int j=i+1; j<N; ++j ) {
      double d = dist(p[i], p[j]);
      if ( d < ans ) ans = d;
    }
  fprintf(stderr, "%.4f (ans)\n", ans);
}
