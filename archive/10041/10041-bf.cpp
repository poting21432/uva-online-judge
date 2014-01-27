#include <cstdio>
#include <climits>
#include <cstdlib>

using namespace std;

int n;
int a[500];

int sumDist(int center)
{
  int sum = 0;
  for ( int i=0; i<n; ++i )
    sum += abs(center-a[i]);
  return sum;
}

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    scanf("%d", &n);
    for ( int i=0; i<n; ++i ) scanf("%d", &a[i]);

    int min = INT_MAX;
    for ( int center=0; center<=30000; ++center ) {
      int d = sumDist(center);
      if ( d < min ) min = d;
    }
    printf("%d\n", min);
  }
}
