#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

int main()
{
  int size;
  ull pos;
  while ( ~scanf("%d %llu", &size, &pos) && !(size==0 && pos==0) ) {
    int count[4] = {0,0,0,0}; // U L D R
    int aug  [4] = {1,1,2,2}; // U L D R
    ull current = 1;
    int dir = 0;
    while ( current != pos ) {
      int move = min((ull)aug[dir], pos-current);
      //printf("current=%llu, aug[dir=%d] = %d, move = %d\n", current, dir, aug[dir], move);
      current    += move;
      count[dir] += move;
      aug[dir] += 2;
      dir = (dir+1)%4;
    }
    //printf("current = %llu [U%d L%d D%d R%d]\n", current, count[0], count[1], count[2], count[3]);
    int di[4] = {+1, 0,-1, 0}; // U L D R
    int dj[4] = { 0,-1, 0,+1}; // U L D R
    int i = (size+1)/2;
    int j = (size+1)/2;
    //printf("(i=%d, j=%d)\n", i, j);
    for ( int k=0; k<4; ++k ) {
      i += di[k] * count[k];
      j += dj[k] * count[k];
      //printf("(i=%d, j=%d)\n", i, j);
    }
    printf("Line = %d, column = %d.\n", i, j);
  }
}
