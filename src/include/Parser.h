/**
 * Code for parsing tokens and generating an abstract syntax tree (AST)
 */
#pragma once

#include <vector>

#include "AST.h"

class Parser {
   public:
	Parser(std::vector<Token> tokens) : m_tokens(tokens) {}

	/**
	 * Parses the tokens in vector<Token> tokens
	 */
	void parse();

   private:
	size_t m_nextTokenIndex = 0;
	/**
	 * @return next token in m_tokens and eats it (increments m_nextTokenIndex)
	 */
	const Token& getNextToken();
	const Token& peekNextToken();

	// numberexpr ::= number
	std::unique_ptr<AST::Expression> parseIntegerExpression();
	// parenexpr ::= '(' expression ')'
	std::unique_ptr<AST::Expression> parseParenExpression();
	// primary
	//	::= numberexpr
	//	::= parenexpr
	std::unique_ptr<AST::Expression> parsePrimaryExpression();
	// binoprhs
	//	::= ('+' primary)*
	std::unique_ptr<AST::Expression> parseBinOpRHS(int exprPrecedence, std::unique_ptr<AST::Expression> LHS);
	std::unique_ptr<AST::Expression> parseExpression();

	/**
	 * @return the operator precedence of char op
	 */
	static int getOpPrecedence(char op);

	std::vector<Token> m_tokens;
};