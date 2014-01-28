#include <cstdio>

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    int N, I;
    double p;
    scanf("%d %lf %d", &N, &p, &I);
    if ( p==0.0 ) {
      puts("0.0000");
      continue;
    }

    double a = p;
    for ( int i=0; i<I-1; ++i ) a *= 1-p;

    double r = 1.0;
    for ( int i=0; i<N; ++i ) r *= 1-p;

    double ans = a/(1-r);
    //printf("a=%.4f, r=%.4f\n", a, r);
    printf("%.4f\n", ans);
  }
}
