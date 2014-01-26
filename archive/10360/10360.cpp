#include <cstdio>
#include <cstring>

const int SIZE = 1025; // 1..SIZE

int d; // radius
int n; // number of rat populations
int w[SIZE+1][SIZE+1];
int s[SIZE+1][SIZE+1];

void read()
{
  scanf("%d", &d);
  scanf("%d", &n);
  memset(w, 0, sizeof(w));
  for ( int i=0; i<n; ++i ) {
    int x, y, size;
    scanf("%d %d %d", &x, &y, &size);
    w[x][y] = size;
  }
}

void prepare()
{
  s[0][0] = w[0][0];
  for ( int x=1; x<=SIZE; ++x ) s[x][0] = s[x-1][0] + w[x][0];
  for ( int y=1; y<=SIZE; ++y ) s[0][y] = s[0][y-1] + w[0][y];
  for ( int x=1; x<=SIZE; ++x )
    for ( int y=1; y<=SIZE; ++y )
      s[x][y] = s[x-1][y] + s[x][y-1] - s[x-1][y-1] + w[x][y];
}

int sum(int x1, int y1, int x2, int y2)
{
  if ( x1==0 && y1==0 ) return s[x2][y2];
  else if ( x1==0 )     return s[x2][y2] - s[x2][y1-1];
  else if ( y1==0 )     return s[x2][y2] - s[x1-1][y2];
  else                  return s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1];
}

void solve()
{
  int max_killed = 0;
  int max_x;
  int max_y;
  for ( int x=0; x<=SIZE; ++x ) {
    for ( int y=0; y<=SIZE; ++y ) {
      int x1 = x-d; if (x1<1) x1=1;
      int y1 = y-d; if (y1<1) y1=1;
      int x2 = x+d; if (x2>SIZE) x2=SIZE;
      int y2 = y+d; if (y2>SIZE) y2=SIZE;
/*
      if ( x>=950 && y>=950 )
	printf("(x,y)=(%d,%d) (x1,y1)=(%d,%d) (x2,y2)=(%d,%d)\n", x, y, x1, y1, x2, y2);
*/
      int killed = sum(x1, y1, x2, y2);
      if ( killed > max_killed ) {
	max_killed = killed;
	max_x = x;
	max_y = y;
      }
    }
  }
  printf("%d %d %d\n", max_x, max_y, max_killed);
}

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    read();
    prepare();
    solve();
  }
}
