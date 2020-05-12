#include <iostream>
#include <vector>

#include "AST.h"
#include "Lexer.h"
#include "Parser.h"
#include "Token.h"

using namespace std;

int main() {
	cout << "Hello World!" << endl;

	Lexer lexer(cin);

	vector<Token> tokens;

#pragma region Handle repl input
	Token nextToken(Token::Type::EndOfFile, "");

	do {
		nextToken = lexer.getNextToken();
		cout << nextToken << endl;

		tokens.push_back(nextToken);

	} while (!nextToken.isType(Token::Type::End) &&
			 !nextToken.isType(Token::Type::EndOfFile));
#pragma endregion
	Parser parser(tokens);
	parser.parse();

	system("pause");
	return 0;
}