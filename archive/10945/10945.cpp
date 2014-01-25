#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

bool check(string &line)
{
  int n = line.length();
  string str = "";
  for ( int i=0; i<n; ++i )
    if ( isalpha(line[i]) )
      str += tolower(line[i]);

  n = str.length();
  for ( int i=0; i<n/2; ++i )
    if ( str[i] != str[n-1-i] )
      return false;

  return true;
}

int main()
{
  string buf;
  while ( getline(cin, buf) ) {
    if ( buf=="DONE" )
      break;
    else {
      puts(check(buf)?"You won't be eaten!":"Uh oh..");
    }
  }
}
