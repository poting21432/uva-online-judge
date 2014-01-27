#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

const int TIME_LIMIT = 5*60*60;
const int BUF_LENGTH = 1024;

char buf[BUF_LENGTH];
vector<int> buffer;

int N;
vector<int> T;
vector<int> light;
vector<int> counter;
vector<int> green_count;

enum Light {
  GREEN,
  ORANGE,
  RED
};

void solve()
{
  N = T.size();
  light  .resize(N);
  counter.resize(N);
  green_count.resize(N);
  for ( int i=0; i<N; ++i ) {
    light  [i] = GREEN;
    counter[i] = 0;
    green_count[i] = 1;
  }
  for ( int t=1; t<=TIME_LIMIT+1; ++t ) {
    //printf("t=%2d, light = %d %d\n", t, light[0], light[1]);
    bool finished = true;
    for ( int i=0; i<N; ++i )
      if ( light[i]!=GREEN || green_count[i]==1 )
	{ finished=false; break; }

    if ( finished ) {
      //printf("finished time = %d\n", t-1);
      int h=0, m=0, s=0;
      s = t-1;
      if ( s>60 ) {
	m = s/60;
	s = s%60;
	if ( m>60 ) {
	  h = m/60;
	  m = m%60;
	}
      }
      printf("%02d:%02d:%02d\n", h, m, s);
      return;
    }

    for ( int i=0; i<N; ++i ) {
      ++counter[i];
      if ( light[i]==GREEN ) {
	if ( counter[i] == T[i]-5 ) {
	  light  [i] = ORANGE;
	  counter[i] = 0;
	}
      }
      else if ( light[i]==ORANGE ) {
	if ( counter[i] == 5 ) {
	  light  [i] = RED;
	  counter[i] = 0;
	}
      }
      else if ( light[i]==RED ) {
	if ( counter[i] == T[i] ) {
	  light  [i] = GREEN;
	  counter[i] = 0;
	  ++green_count[i];
	}
      }
    }
  }
  puts("Signals fail to synchronise in 5 hours");
}

bool containsThreeZeros(const char *str)
{
  int z1, z2, z3;
  return sscanf(str,"%d%d%d",&z1,&z2,&z3)!=EOF && z1==0 && z2==0 && z3==0;
}

void read()
{
  while ( gets(buf) ) {
    if ( containsThreeZeros(buf) )
      break;
    else {
      char *ptr;
      for ( ptr=strtok(buf," "); ptr; ptr=strtok(NULL," ") ) {
	int x = atoi(ptr);
	buffer.push_back(x);
      }
    }
  }
}

int main()
{
  read();
  for ( int i=0; i<buffer.size(); ++i ) {
    if ( buffer[i]==0 ) {
      solve();
      T.clear();
    }
    else {
      T.push_back( buffer[i] );
    }
  }
}
