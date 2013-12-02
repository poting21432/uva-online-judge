// g++ uva-link.cpp -o uva-link && ./uva-link < ../.basic-problem-list.md > ../basic-problem-list.md

#include <cstdio>
#include <cctype>
#include <cstring>

char buf[1024];

int main()
{
  while ( gets(buf) ) {
    if ( strlen(buf)>3 && isdigit(buf[0]) && isdigit(buf[1]) ) {
      char problem_id[16];
      sscanf(buf, "%s", problem_id);
      char problem_dir[16];
      strcpy(problem_dir, problem_id);
      problem_dir[strlen(problem_id)-2] = '\0';
      //printf("%s / %s\n", problem_dir, problem_id);
      printf("[．%s](http://uva.onlinejudge.org/external/%s/%s.html) ", buf, problem_dir, problem_id);
    }
    else {
      puts(buf);
    }
  }
}
