#include <cstdio>
#include <cstring>
#include <set>

char buf[16];
bool node[26];
int  parent[26];

void Init()
{
  for ( int i=0; i<26; ++i )
    parent[i] = i;
}

int Find(int x)
{
  while ( x != parent[x] )
    x = parent[x];
  return x;
}

void Union(int i, int j)
{
  int x = Find(i);
  int y = Find(j);
  if ( x!=y )
    parent[x] = y;
}

int main()
{
  int T;
  gets(buf);
  sscanf(buf, "%d", &T);
  gets(buf); // blank line
  for ( int t=1; t<=T; ++t ) {
    if ( t>1 ) putchar('\n');
    Init();
    memset(node, 0, sizeof(node));
    gets(buf); // largest node
    int w = buf[0]-'A';
    node[w] = true;
    for ( int i=0; i<w; ++i ) node[i] = true;
    while ( gets(buf) ) {
      //printf("buf = %s\n", buf);
      if ( buf[0]=='\0' ) break;
      else {
	int u = buf[0]-'A';
	int v = buf[1]-'A';
	node[u] = true;
	node[v] = true;
	//printf("%d %d\n", u, v);
	Union(u,v);
      }
    }
    std::set<int> groups;
    for ( int i=0; i<26; ++i )
      if ( node[i] )
	groups.insert( Find(i) );
    
    printf("%zd\n", groups.size());
  }
}
