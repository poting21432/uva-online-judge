#include <cstdio>

typedef unsigned long long ull;

ull ones[20] = {
  0ull,
  1ull,
  11ull,
  111ull,
  1111ull,
  11111ull,
  111111ull,
  1111111ull,
  11111111ull,
  111111111ull,
  1111111111ull,
  11111111111ull,
  111111111111ull,
  1111111111111ull,
  11111111111111ull,
  111111111111111ull,
  1111111111111111ull,
  11111111111111111ull,
  111111111111111111ull,
  1111111111111111111ull
};

int main()
{
  int n;
  while ( ~scanf("%d", &n) ) {
    for ( int i=1; i<=19; ++i ) {
      if ( ones[i] % n == 0 ) {
	printf("%d\n", i);
	break;
      }
    }
  }
}
