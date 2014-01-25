#include <cstdio>
#include <algorithm>

using namespace std;

int solve(int M, int N)
{
  if ( M>N ) swap(M, N);
  if ( M==1 ) return N;
  else if ( M==2 ) {
    if   ( (N-1)%4==0 ) return N+1;
    else                return 4 * (1 + (N-1)/4);
  }
  else return (M*N+1)/2;
}

int main()
{
  int M, N;
  while ( ~scanf("%d %d", &M, &N) && !(M==0 && N==0) )
    printf("%d knights may be placed on a %d row %d column board.\n", solve(M,N), M, N);
}
