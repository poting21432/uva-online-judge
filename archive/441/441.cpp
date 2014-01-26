#include <cstdio>

int A, a[13];
int B, b[6 ];

void backtrack(int i)
{
  //printf("backtrack(i=%d)\n", i);
  if ( i>A ) {
    return;
  }
  else if ( B==6 ) {
    printf("%d", b[0]);
    for ( int j=1; j<6; ++j ) printf(" %d", b[j]);
    putchar('\n');
  }
  else {
    b[B++] = a[i];   backtrack(i+1);
    --B;             backtrack(i+1);
  }
}

int main()
{
  bool first_case = true;
  while ( ~scanf("%d",&A) && A!=0 ) {
    for ( int i=0; i<A; ++i ) scanf("%d", &a[i]);

    if ( first_case ) first_case = false;
    else putchar('\n');

    B = 0;
    backtrack(0);
  }
}
