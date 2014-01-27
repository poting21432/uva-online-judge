#include <cstdio>
#include <map>

using namespace std;

typedef unsigned long long ull;

ull c(int n, int k)
{
  ull result = 1ull;
  if ( k > n-k ) k = n-k;
  for ( int i=0; i<k; ++i ) {
    result *= n-i;
    result /= i+1;
  }
  return result;
}

int main()
{
  int n, k;
  while ( scanf("%d %d", &n, &k) && !(n==0 && k==0) ) {
    printf("%llu\n", c(n,k));
  }
}
