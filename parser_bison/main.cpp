
#include <iostream>
#include "astnode.h"

using namespace std;

extern int yyparse();

extern StatSeq* ast;

int main(int argc, char **argv) {
  yyparse();
  std::cout << "parsing complete" << std::endl;
  ast->walk();
  std::cout << std::endl;
  return 0;
}

