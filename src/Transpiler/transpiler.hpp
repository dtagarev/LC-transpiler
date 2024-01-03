#ifndef TRANSPILER_FILE
#define TRANSPILER_FILE

#include "../Generator/generator.hpp"
#include "../Lexer/lexer.hpp"
#include "../Parser/parser.hpp"
#include "../Transformer/transformer.hpp"

class Transpiler {
  Lexer lx;
  Parser ps;
  Transformer tr;
  Generator gn;

  void printTokens(std::vector<Token> tokens);
  void printAst(std::vector<Structure *>);
  void printTransformation();

public:
  void transpile(const char *filename);
};

#endif
