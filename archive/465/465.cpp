#include <iostream>
#include <climits>
#include <sstream>
#include <string>

using namespace std;

typedef long long INT;

INT makeINT(string str)
{
  INT n = 0ll;
  int len = str.length();
  for ( int i=0; i<len; ++i )
    n = n*10ll + str[i];  
  return n;
}

bool literalOverflow(string str)
{
  if ( str.length() > 18 )
    return true;
  else {
    return makeINT(str) > INT_MAX;
  }
}

bool addOverflow(INT A, INT B)
{
  return A+B > (INT)INT_MAX;
}

bool mulOverflow(INT A, INT B)
{
  return A*B/B!=A || B*A/A!=B;
}

int main()
{
  string line, a, op, b;
  while ( getline(cin, line) ) {
    stringstream ss(line);
    ss >> a >> op >> b;
    cout << line << endl;
    if ( literalOverflow(a) )
      cout << "first number too big" << endl;
    if ( literalOverflow(b) )
      cout << "second number too big" << endl;

    INT A = makeINT(a);
    INT B = makeINT(b);
    if ( op=="+" && addOverflow(A,B) )
      cout << "result too big" << endl;
    if ( op=="*" && mulOverflow(A,B) )
      cout << "result too big" << endl;
  }
}
