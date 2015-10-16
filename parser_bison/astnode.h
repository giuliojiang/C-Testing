
#include <vector>
#include <iostream>

class ASTnode {
public:
  virtual ~ASTnode() {}
  virtual void check() {}
  virtual void walk() {}
};

class Expression : public ASTnode { };
typedef std::vector<Expression*> ExpressionList;

class Statement : public ASTnode { };
typedef std::vector<Statement*> StatementList;


class StatSeq : public Statement {
public:
  StatementList statements;

  StatSeq () {} 
  
  void walk()
  {
      for (int i = 0; i < statements.size(); i++)
      {
          statements[i]->walk();
          std::cout << " ; ";
      }
  }
};

class Identifier : public Expression {
public:
  std::string id;
	
  Identifier(std::string& id) : id(id) {}
  
  void walk()
  {
      std::cout << " identifier[" << id << "] ";
  }
};

class Assignment : public Statement {
public:
  Identifier& var;
  Expression& expr;

  Assignment(Identifier& var, Expression& expr) 
    : var(var), expr(expr) {}
    
  void walk()
  {
      std::cout << " assignment{";
      var.walk();
      std::cout << "}={";
      expr.walk();
      std::cout << "} ";
  }
};

class IfStatement : public Statement {
public:
  Expression&   expr;
  StatSeq& thenS;
  StatSeq* elseS; 

  IfStatement(Expression& expr, StatSeq& thenS) 
    : expr(expr), thenS(thenS) {}

  IfStatement(Expression& expr, StatSeq& thenS, StatSeq* elseS)
    : expr(expr), thenS(thenS), elseS(elseS) {}
    
  void walk()
  {
      std::cout << " ifstmt{";
      expr.walk();
      std::cout << "}{";
      thenS.walk();
      std::cout << "}{";
      elseS->walk();
      std::cout << "} ";
  }
};

class WhileStatement : public Statement {
public:
  Expression& expr;
  StatSeq& doS;

  WhileStatement(Expression& expr, StatSeq& doS) 
    : expr(expr), doS(doS) {}
    
  void walk()
  {
      std::cout << " whilestmt{";
      expr.walk();
      std::cout << "}{";
      doS.walk();
      std::cout << "} ";
  }
};

class RepeatStatement : public Statement {
public:
  StatSeq& block;
  Expression& expr;

  RepeatStatement(StatSeq& block, Expression& expr) 
    : block(block), expr(expr) {}
    
  void walk()
  {
      std::cout << " repeatstmt{";
      block.walk();
      std::cout << "}{";
      expr.walk();
      std::cout << "} ";
  }
};

class ReadStatement : public Statement {
public:
  Identifier& id;
  
  ReadStatement(Identifier& id) : id(id) {}
  
  void walk()
  {
    std::cout << " readstmt{";
    id.walk();
    std::cout << "} ";
  }
};

class WriteStatement : public Statement {
public:
  Expression& expr;

  WriteStatement(Expression& expr) : expr(expr) {}
  
  void walk()
  {
    std::cout << " writestmt{";
    expr.walk();
    std::cout << "} ";
  }
};

class Number : public Expression {
public:
  int value;
  
  Number(int value) : value(value) {}
  
  void walk()
  {
      std::cout << " number(" << value << ") ";
  }
};

class Operator : public Expression {
public:
  int op;
  Expression& left;
  Expression& right;
	
  Operator(Expression& left, int op, Expression& right) 
    : left(left), right(right), op(op) {}
    
  void walk()
  {
      std::cout << " operator(" << op << ") ";
  }
};

class VariableDeclaration : public Statement { 
public:
  Identifier& type;
  Identifier& id;
  Expression* expr;

  VariableDeclaration(Identifier& type, Identifier& id) 
    : type(type), id(id) {}
  VariableDeclaration(Identifier& type, Identifier& id, Expression *expr) 
    : type(type), id(id), expr(expr) {}
    
  void walk()
  {
      std::cout << " vardecl{";
      type.walk();
      std::cout << "}{";
      id.walk();
      std::cout << "}{";
      expr->walk();
      std::cout << "} ";
  }
};
typedef std::vector<VariableDeclaration*> VariableList;

class FunctionDeclaration : public Statement {
public:
  Identifier& type;
  Identifier& id;
  VariableList parameters;
  StatSeq& block;
  
  FunctionDeclaration(Identifier& type, Identifier& id, 
      VariableList& parameters, StatSeq& block) 
    : type(type), id(id), parameters(parameters), block(block) {}
  
  void walk()
  {
      std::cout << " funcdecl{";
      type.walk();
      std::cout << "}{";
      id.walk();
      std::cout << "}{";
      for (int i = 0; i < parameters.size(); i++)
      {
          parameters[i]->walk();
          std::cout << " ; ";
      }
      std::cout << "}{";
      block.walk();
      std::cout << "} ";
  }
};

class FunctionCall : public Expression {
public:
  Identifier& id;
  ExpressionList parameters;
  
  FunctionCall(Identifier& id, ExpressionList& parameters) 
    : id(id), parameters(parameters) {}
  FunctionCall(Identifier& id) 
    : id(id) {}
    
  void walk()
  {
      std::cout << " funccall{";
      id.walk();
      std::cout << "}{";
      for (int i = 0; i < parameters.size(); i++)
      {
          parameters[i]->walk();
          std::cout << " ; ";
      }
      std::cout << "} ";
  }
};
