#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

const int TIME_LIMIT = 5*60*60;
const int BUF_LENGTH = 1024;

char buf[BUF_LENGTH];
char tmp[BUF_LENGTH];
vector<int> buffer;

int N;
vector<int> T;

struct Light
{
  int  tick;
  char color; // 'G'->'Y'->'R'
  int  cycle;
};

void printAnswer(int t)
{
  if ( t > 5*60*60 ) {
    puts("Signals fail to synchronise in 5 hours");
    return;
  }

  //printf("[t=%d] ", t);
  int h=0, m=0, s=t;
  if ( s>60 ) {
    m = s / 60;
    s = s % 60;
    if ( m > 60 ) {
      h = m / 60;
      m = m % 60;
    }
  }
  printf("%02d:%02d:%02d\n", h, m, s);
}

void solve()
{
  N = T.size();
}

bool containsThreeZeros(char *str)
{
  strcpy(tmp, str);
  int zero_count = 0;
  for ( char *ptr=strtok(tmp," "); ptr; ptr=strtok(NULL," ") )
    if ( atoi(ptr)==0 )
      ++zero_count;
  return zero_count==3;
}

void read()
{
  while ( gets(buf) ) {
    if ( containsThreeZeros(buf) ) {
      break;
    }
    else {
      strcpy(tmp, buf);
      char *ptr;
      for ( ptr=strtok(tmp," "); ptr; ptr=strtok(NULL," ") ) {
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
