#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
  char buf[32];
  int guess;
  while ( true ) {
    vector<int>  guesses;
    vector<bool> compares;
    while ( true ) {
      gets(buf);
      sscanf(buf, "%d", &guess);
      if ( guess==0 ) {
	return 0;
      }
      else {
	gets(buf);
	if ( !strcmp(buf, "too low") ) {
	  guesses .push_back(guess);
	  compares.push_back(true);
	}
	else if ( !strcmp(buf, "too high") ) {
	  guesses .push_back(guess);
	  compares.push_back(false);	  
	}
	else if ( !strcmp(buf, "right on") ) {
	  bool cheat = false;
	  for ( int i=0; i<guesses.size(); ++i ) {
	    if ( compares[i]==true  && guess<=guesses[i] ) { cheat=true; break; }
	    if ( compares[i]==false && guess>=guesses[i] ) { cheat=true; break; }
	  }
	  puts(cheat?"Stan is dishonest":"Stan may be honest");
	  break;
	}
      }
    }
  }
}
