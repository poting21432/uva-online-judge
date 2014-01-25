#include <cstdio>
#include <algorithm>

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    int A[3];
    scanf("%d %d %d", A, A+1, A+2);
    std::sort(A, A+3);
    printf("Case %d: %d\n", t, A[1]);
  }
}
