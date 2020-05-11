#include <iostream>

#include "AST.h"
#include "Lexer.h"
#include "Token.h"

using namespace std;

int main() {
	cout << "Hello World!" << endl;

	Lexer lexer(cin);

#pragma region Handle repl input
	Token nextToken(Token::Type::EndOfFile, "");
	do {
		nextToken = lexer.next();
		cout << nextToken << endl;

	} while (!nextToken.isType(Token::Type::End) &&
			 !nextToken.isType(Token::Type::EndOfFile));
#pragma endregion

	system("pause");
	return 0;
}