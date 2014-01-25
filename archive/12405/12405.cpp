#include <cstdio>

int main()
{
  int T, N;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    char str[101];
    scanf("%d%s", &N, str);
    
    int count = 0;
    int pos = 0;
    while ( pos < N ) {
      if ( str[pos]=='.' ) {
	++count;
	if      ( pos+2<N && str[pos+2]=='.' ) pos += 3;
	else if ( pos+1<N && str[pos+1]=='.' ) pos += 2;
	else ++pos;
      }
      else
	++pos;
    }
    printf("Case %d: %d\n", t, count);
  }
}
