#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int A, B;
int a[10];
int b[10];

bool read()
{
  scanf("%d", &A);
  if ( A==0 ) return false;
  scanf("%d", &B);
  for ( int i=0; i<A; ++i ) scanf("%d", &a[i]);
  for ( int i=0; i<B; ++i ) scanf("%d", &b[i]);
  return true;
}

void solve()
{
  double max = 0.0;
  vector<double> ratios;
  for ( int i=0; i<A; ++i ) {
    for ( int j=0; j<B; ++j ) {
      double ratio = (double)b[j] / (double)a[i];
      ratios.push_back(ratio);
    }
  }

  sort(ratios.begin(), ratios.end());
  for ( int i=1; i<ratios.size(); ++i ) {
    double spread = ratios[i] / ratios[i-1];
    //printf("spread = %.2f\n", spread);
    if ( spread > max ) max = spread;
  }
  printf("%.2f\n", max);
}

int main()
{
  while ( read() )
    solve();
}
