#include <cstdio>
#include <cstring>

int  drawn = 1;
int  path[9] = {1};
bool vst[6][6];
bool con[6][6] = {
  0,0,0,0,0,0,
  0,0,1,1,0,1,
  0,1,0,1,0,1,
  0,1,1,0,1,1,
  0,0,0,1,0,1,
  0,1,1,1,1,0
};

void search(int u)
{
  if ( drawn==9 ) {
    for ( int i=0; i<drawn; ++i ) printf("%d", path[i]);
    putchar('\n');
  }
  else {
    for ( int v=1; v<=5; ++v ) {
      if ( con[u][v] && !vst[u][v] ) {
	vst[u][v] = vst[v][u] = true;
	path[drawn++] = v;
	search(v);
	--drawn;
	vst[u][v] = vst[v][u] = false;
      }
    }
  }
}

int main()
{
  memset(vst, 0, sizeof(vst));
  search(1);
}
