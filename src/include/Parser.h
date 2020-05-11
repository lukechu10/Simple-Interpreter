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
	std::unique_ptr<AST::Expression> parseExpression();

	std::vector<Token> m_tokens;
};