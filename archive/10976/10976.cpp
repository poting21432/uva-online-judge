#include <cstdio>
#include <vector>

using namespace std;

struct Ans
{
  int x, y;
  Ans(int _x, int _y):x(_x),y(_y){}
};

int main()
{
  int k, x, y;
  vector<Ans> ans;
  while ( ~scanf("%d", &k) ) {
    if ( k==1 ) {
      puts("1");
      puts("1/1 = 1/2 + 1/2");
      continue;
    }

    ans.clear();
    for ( x=k+1; ; ++x ) {
      if ( (x*k) % (x-k) == 0 ) {
	y = (x*k) / (x-k);
	if ( y<x ) break;
	//printf("(x=%d, y=%d)\n", x, y);
	ans.push_back( Ans(x, y) );
      }
    }
    printf("%zd\n", ans.size());
    for ( int i=0; i<ans.size(); ++i )
      printf("1/%d = 1/%d + 1/%d\n", k, ans[i].y, ans[i].x);
  }
}
