#include <cstdio>
#include <set>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

void error()
{
  while(1);
}

void getABO(const char *blood, char *ABO)
{
  if      ( !strcmp(blood, "A" ) ) strcpy(ABO, "AO");
  else if ( !strcmp(blood, "B" ) ) strcpy(ABO, "BO");
  else if ( !strcmp(blood, "O" ) ) strcpy(ABO, "OO");
  else if ( !strcmp(blood, "AB") ) strcpy(ABO, "AB");
  else error();
}

void getBlood(const char father, const char mother, char *blood)
{
  if      ( father=='A' && mother=='A' ) strcpy(blood, "A");
  else if ( father=='A' && mother=='O' ) strcpy(blood, "A");
  else if ( father=='O' && mother=='A' ) strcpy(blood, "A");
  else if ( father=='A' && mother=='B' ) strcpy(blood, "AB");
  else if ( father=='B' && mother=='A' ) strcpy(blood, "AB");
  else if ( father=='B' && mother=='B' ) strcpy(blood, "B");
  else if ( father=='B' && mother=='O' ) strcpy(blood, "B");
  else if ( father=='O' && mother=='B' ) strcpy(blood, "B");
  else if ( father=='O' && mother=='O' ) strcpy(blood, "O");
  else error();
}

void findChild(const char *father, const char *mother)
{
  //printf("findChild(%s,%s):", father, mother);
  int  father_len = strlen(father);
  int  mother_len = strlen(mother);
  char father_blood[4]; strcpy(father_blood, father); father_blood[father_len-1] = '\0';
  char mother_blood[4]; strcpy(mother_blood, mother); mother_blood[mother_len-1] = '\0';
  char father_ABO[4];
  char mother_ABO[4];
  getABO(father_blood, father_ABO); //printf("[father_blood = %s, father_ABO = %s]", father_blood, father_ABO);
  getABO(mother_blood, mother_ABO); //printf("[mother_blood = %s, mother_ABO = %s]", mother_blood, mother_ABO);
  bool father_rh = father[father_len-1]=='+';
  bool mother_rh = mother[mother_len-1]=='+';
  set<string> bloods;
  for ( int i=0; i<2; ++i ) { // father
    for ( int j=0; j<2; ++j ) { // mother
      char child_blood[4];
      getBlood(father_ABO[i], mother_ABO[j], child_blood);
      if ( father_rh==false && mother_rh==false )
	bloods.insert( string(child_blood) + "-" );
      else {
	bloods.insert( string(child_blood) + "+" );
	bloods.insert( string(child_blood) + "-" );
      }
    }
  }
  if ( bloods.empty() ) printf("IMPOSSIBLE");
  else if ( bloods.size()==1 ) {
    printf("%s", bloods.begin()->c_str());
  }
  else {
    set<string>::iterator it = bloods.begin();
    printf("{%s", it->c_str());
    while ( ++it != bloods.end() )
      printf(", %s", it->c_str());
    putchar('}');
  }
}

int getBloodIndex(const char *blood)
{
  if ( !strcmp(blood, "A") ) return 1;
  else if ( !strcmp(blood, "B") ) return 2;
  else if ( !strcmp(blood, "AB") ) return 3;
  else if ( !strcmp(blood, "O") ) return 4;
  else return 0;
}

void findParent(const char *child, const char *parent)
{
  //printf("findParent(%s,%s)", child, parent);
  int child_len  = strlen(child);
  int parent_len = strlen(parent);
  char child_blood [4]; strcpy(child_blood,  child);  child_blood [child_len -1] = '\0';
  char parent_blood[4]; strcpy(parent_blood, parent); parent_blood[parent_len-1] = '\0';
  int cb = getBloodIndex(child_blood);  // 1 for child_blood =A, 2 for B, 3 for AB, 4 for O
  int pb = getBloodIndex(parent_blood); // 1 for parent_blood=A, 2 for B, 3 for AB, 4 for O
  vector<string> bloods;
  if      ( cb==1 && pb==1 ) { bloods.push_back("A"); bloods.push_back("B"); bloods.push_back("AB"); bloods.push_back("O"); }
  else if ( cb==1 && pb==2 ) { bloods.push_back("A"); bloods.push_back("AB"); }
  else if ( cb==1 && pb==3 ) { bloods.push_back("A"); bloods.push_back("B"); bloods.push_back("AB"); bloods.push_back("O"); }
  else if ( cb==1 && pb==4 ) { bloods.push_back("A"); bloods.push_back("AB"); }

  else if ( cb==2 && pb==1 ) { bloods.push_back("B"); bloods.push_back("AB"); }
  else if ( cb==2 && pb==2 ) { bloods.push_back("A"); bloods.push_back("B"); bloods.push_back("AB"); bloods.push_back("O"); }
  else if ( cb==2 && pb==3 ) { bloods.push_back("A"); bloods.push_back("B"); bloods.push_back("AB"); bloods.push_back("O"); }
  else if ( cb==2 && pb==4 ) { bloods.push_back("B"); bloods.push_back("AB"); }

  else if ( cb==3 && pb==1 ) { bloods.push_back("B"); bloods.push_back("AB"); }
  else if ( cb==3 && pb==2 ) { bloods.push_back("A"); bloods.push_back("AB"); }
  else if ( cb==3 && pb==3 ) { bloods.push_back("A"); bloods.push_back("B"); bloods.push_back("AB"); }
  else if ( cb==3 && pb==4 ) { printf("IMPOSSIBLE"); return; }

  else if ( cb==4 && pb==1 ) { bloods.push_back("A"); bloods.push_back("B"); bloods.push_back("O"); }
  else if ( cb==4 && pb==2 ) { bloods.push_back("A"); bloods.push_back("B"); bloods.push_back("O"); }
  else if ( cb==4 && pb==3 ) { printf("IMPOSSIBLE"); return; }
  else if ( cb==4 && pb==4 ) { bloods.push_back("A"); bloods.push_back("B"); bloods.push_back("O"); }

  bool child_rh  = child [child_len -1]=='+';
  bool parent_rh = parent[parent_len-1]=='+';
  vector<string> rhs;
  if ( child_rh==false && parent_rh==false ) {
    rhs.push_back("+");
    rhs.push_back("-");
  }
  else if ( child_rh==false && parent_rh==true ) {
    rhs.push_back("+");      
    rhs.push_back("-");      
  }
  else if ( child_rh==true && parent_rh==false ) {
    rhs.push_back("+");            
  }
  else if ( child_rh==true && parent_rh==true ) {
    rhs.push_back("+");
    rhs.push_back("-");            
  }

  set<string> options;
  for ( int i=0; i<bloods.size(); ++i ) {
    for ( int j=0; j<rhs.size(); ++j ) {
      options.insert( bloods[i] + rhs[j] );
    }
  }

  if ( options.empty() ) printf("IMPOSSIBLE");
  else if ( options.size()==1 ) {
    printf("%s", options.begin()->c_str());
  }
  else {
    set<string>::iterator it = options.begin();
    printf("{%s", it->c_str());
    while ( ++it != options.end() )
      printf(", %s", it->c_str());
    putchar('}');
  }
}

int main()
{
  char buf[3][8];
  int case_count = 0;
  while ( ~scanf("%s %s %s", buf[0], buf[1], buf[2]) ) {
    if ( buf[0][0]=='E' && buf[1][0]=='N' && buf[2][0]=='D' ) break;
    else {
      for ( int i=0; i<3; ++i ) {
	char rh = buf[i][strlen(buf[i])-1];
	if ( rh!='?' && rh!='+' && rh!='-' ) {
	  error();
	}
      }

      printf("Case %d:", ++case_count);
      for ( int i=0; i<3; ++i ) {
	putchar(' ');
	if ( buf[i][0]=='?' ) {
	  if ( i==2 ) findChild (buf[0], buf[1]);
	  else        findParent(buf[2], buf[0][0]=='?'?buf[1]:buf[0]);
	}
	else {
	  printf("%s", buf[i]);
	}
      }
      putchar('\n');
    }
  }
}
