#include <cstdio>

int solve(int n)
{
  int m = 1;
  int len = 1;
  while ( m!=0 ) {
    m  = m*10+1;
    m %= n;
    ++len;
  }
  return len;
}

int main()
{
  int n;
  while ( ~scanf("%d", &n) )
    printf("%d\n", solve(n));
}
