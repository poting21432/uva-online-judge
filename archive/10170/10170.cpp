#include <cstdio>

typedef unsigned long long ull;

void search(ull S, ull D)
{
  ull L = 1;
  ull R = 0;
  for ( int G=S; ; ++G ) {
    R += G;
    if ( L<=D && D<=R ) {
      printf("%d\n", G);
      break;
    }
    L = R+1;
  }
}

int main()
{
  ull S, D;
  while ( ~scanf("%llu %llu", &S, &D) )
    search(S, D);
}
