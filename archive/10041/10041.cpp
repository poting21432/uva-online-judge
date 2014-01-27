#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n;
int a[500];

int sumDist(int center)
{
  int sum = 0;
  for ( int i=0; i<n; ++i )
    sum += abs(center - a[i]);
  return sum;
}

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    scanf("%d", &n);
    int sum = 0;
    for ( int i=0; i<n; ++i ) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    sort(a, a+n);
    printf("%d\n", sumDist(a[n/2]));
  }
}
