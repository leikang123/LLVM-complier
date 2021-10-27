#include <string>
#include <iostream>
using namespace std;
/*词法分析器。又是扫描器，将输入分解为标记。返回的是一些标记代码和元数据（数值）。*/
// 如果是未知字符，词法分析器返回标记 [0-255]，否则返回一个
// 其中的已知事物。
enum Token {
  tok_eof = -1,

  // 输入def返回-2
  tok_def = -2,
  // 输入extern 返回 -3
  tok_extern = -3,

  // primary
  tok_identifier = -4,
  // 输入数字返回 -5
  tok_number = -5
};
 // 填写如果tok_identifier
static std::string IdentifierStr; 
// 如果tok_number
static double NumVal;             
// gettok - 从标准输入返回下一个令牌。
static int gettok() {
  // 静态变量lastchar赋值为空白
  static int LastChar = ' ';

  // 当isspace包含变量LastChar时，跳过空白
  while (isspace(LastChar))
    LastChar = getchar();

  if (isalpha(LastChar)) { // identifier: [a-zA-Z][a-zA-Z0-9]*
    IdentifierStr = LastChar;
    while (isalnum((LastChar = getchar())))
      IdentifierStr += LastChar;

    if (IdentifierStr == "def")
      return tok_def;
    if (IdentifierStr == "extern")
      return tok_extern;
    return tok_identifier;
  }

  if (isdigit(LastChar) || LastChar == '.') { // Number: [0-9.]+
    std::string NumStr;
    do {
      NumStr += LastChar;
      LastChar = getchar();
    } while (isdigit(LastChar) || LastChar == '.');

    NumVal = strtod(NumStr.c_str(), nullptr);
    return tok_number;
  }

  if (LastChar == '#') {
    // Comment until end of line.
    do
      LastChar = getchar();
    while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

    if (LastChar != EOF)
      return gettok();
  }

  // Check for end of file.  Don't eat the EOF.
  if (LastChar == EOF)
    return tok_eof;

  // Otherwise, just return the character as its ascii value.
  int ThisChar = LastChar;
  LastChar = getchar();
  return ThisChar;
}
/*int main(){/
    while (true){
        int tok =gettok();
        cout << "get token" << tok << endl;
    }
}
*/
class ExprAST{
  public :
  virtual ~ExprAST(){}
};
class NumberExprAST : public ExprAST{
     double Val;
     public :
     NumberExprAST(double Val):Val(Val){}

};