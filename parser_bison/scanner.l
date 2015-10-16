
/* Flex specification for DoC221 language 
------------------------------------------------------------------------------- 
http://flex.sourceforge.net/manual/index.html

Definitions section. 
-------------------------------------------------------------------------------
http://flex.sourceforge.net/manual/Definitions-Section.html#Definitions-Section
   
- Defines names (shortcuts) for regular expressions (called patterns in Flex and
  Bison. Names are referred to using {name}
- Use #include for needed libraries. 
  Embed within %{  %}
-------------------------------------------------------------------------------
*/

%{
  #include <string>
  #include "astnode.h"
  #include "parser.hpp"
%}

/* bison compatibility directive */
%option noyywrap 

digit         [0-9]
number        {digit}+
letter        [a-zA-Z]
identifier    {letter}+
whitespace    [ \t\n]+
comment       //[^\n]*\n

%% 

  /*  Must INDENT Comments in this section!!
  Rules section.
  ---------------------------------------------------------------------------
  http://flex.sourceforge.net/manual/Rules-Section.html#Rules-Section
   
  - Rules are of the form 
       pattern C-statement. 
    We'll return an uppercase identifier (e.g. WHILE) which will be defined 
    as a unique integer token value by Bison.
  - yytext refers to string of token.
  - we can set yylval for a longint representation of a token.

  */

begin         return BEGINN;
end           return END; 
if            return IF; 
then          return THEN; 
else          return ELSE; 
while         return WHILE; 
do            return DO; 
repeat        return REPEAT; 
until         return UNTIL; 
read          return READ; 
write         return WRITE; 
":="          return BECOMES; 
"="           return EQUALS; 
"<"           return LESSTHAN; 
"+"           return PLUS; 
"-"           return MINUS; 
"*"           return STAR; 
"/"           return SLASH; 
"("           return LPAREN; 
")"           return RPAREN; 
";"           return SEMICOLON; 
";"           return COMMA; 

{number}      yylval.string = new std::string(yytext,yyleng); return INTEGER;; 
{identifier}  yylval.string = new std::string(yytext,yyleng); return IDENTIFIER; 
{whitespace}  { }
  /* {comment}     { }  */
.             return ERROR; 

%%  

/* Optional User Code section
--------------------------------------------------------------------------------
*/

