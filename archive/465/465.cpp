#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const string int32_min = "-2147483648";
const string int32_max =  "2147483647";

bool greaterThan(const string &a, const string &b);
bool lowerThan  (const string &a, const string &b);

bool lowerThan(const string &a, const string &b)
{
  if ( a[0]=='-' && b[0]=='-' )
    return greaterThan(a.substr(1), b.substr(1));
  else if ( a[0]=='-' ) // a<0  b>=0
    return true;
  else if ( b[0]=='-' ) // a>=0 b<0
    return false;
  else {
    int a_len = a.length();
    int b_len = b.length();
    if ( a_len != b_len )
      return a_len < b_len;
    else {
      for ( int i=0; i<a_len; ++i )
	if ( a[i] != b[i] )
	  return a[i] < b[i];
      return false;
    }
  }
}

bool greaterThan(const string &a, const string &b)
{
  if ( a[0]=='-' && b[0]=='-' )
    return lowerThan(a.substr(1), b.substr(1));
  else if ( a[0]=='-' ) // a<0  b>=0
    return false;
  else if ( b[0]=='-' ) // a>=0 b<0
    return true;
  else {
    int a_len = a.length();
    int b_len = b.length();
    if ( a_len != b_len )
      return a_len > b_len;
    else {
      for ( int i=0; i<a_len; ++i )
	if ( a[i] != b[i] )
	  return a[i] > b[i];
      return false;
    }
  }
}

string add(const string &a, const string &b)
{
  int   a_len = a.length();
  int   b_len = b.length();
  int   c_len = max(a_len, b_len) + 1;
  char *a_buf = new char[c_len];
  char *b_buf = new char[c_len];
  char *c_buf = new char[c_len];
  memset(a_buf, 0, c_len);
  memset(b_buf, 0, c_len);
  memset(c_buf, 0, c_len);
  for ( int i=0; i<a_len; ++i ) a_buf[i] = a[a_len-1-i] - '0';
  for ( int i=0; i<b_len; ++i ) b_buf[i] = b[b_len-1-i] - '0';
  for ( int i=0; i<c_len; ++i ) {
    c_buf[i] += a_buf[i] + b_buf[i];
    if ( c_buf[i] >= 10 ) {
      c_buf[i+1] += c_buf[i] / 10;
      c_buf[i] %= 10;
    }
  }

  string c;
  int end = c_len-1;
  while ( end>=0 ) {
    if ( c_buf[end] != 0 )
      break;
    --end;
  }
  if ( end==-1 )
    c = "0";
  else {
    do {
      c += c_buf[end] + '0';
    } while ( --end >= 0 );
  }
  delete [] a_buf;
  delete [] b_buf;
  delete [] c_buf;

  return c;
}

string sub(const string &a, const string &b)
{
  return "0";
}

string mul(const string &a, const string &b)
{
  return "0";
}

void test()
{
  puts( add("123", "456").c_str() );
}

bool literalOverflow(const string &str)
{
  return lowerThan(str, int32_min) || greaterThan(str, int32_max);
}

bool addOverflow(const string &a, const string &b)
{
  return literalOverflow(a) || literalOverflow(b) || literalOverflow(add(a,b));
}

bool mulOverflow(const string &a, const string &b)
{
  return literalOverflow(a) || literalOverflow(b) || literalOverflow(mul(a,b));
}

int main()
{
  test();

  string line, a, op, b;
  while ( getline(cin, line) ) {
    stringstream ss(line);
    ss >> a >> op >> b;
    if ( a[0]=='+' ) a = a.substr(1);
    if ( b[0]=='+' ) b = b.substr(1);

    cout << line << endl;
    if ( literalOverflow(a) ) cout << "first number too big" << endl;
    if ( literalOverflow(b) ) cout << "second number too big" << endl;

    if ( op=="+" && addOverflow(a,b) ) cout << "result too big" << endl;
    if ( op=="*" && mulOverflow(a,b) ) cout << "result too big" << endl;
  }
}
