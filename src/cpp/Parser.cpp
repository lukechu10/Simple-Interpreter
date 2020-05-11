#include "Parser.h"

#include <cassert>
#include <string>
#include <memory>

using namespace std;
using namespace AST;

void Parser::parse() {}

const Token& Parser::getNextToken() {
	assert(m_nextTokenIndex + 1 < m_tokens.size());
	return m_tokens[m_nextTokenIndex++];
}
const Token& Parser::peekNextToken() { return m_tokens[m_nextTokenIndex]; }

unique_ptr<Expression> Parser::parseIntegerExpression() {
	// get next token and eat it
	const Token& nextToken = getNextToken();
	// make sure token type is an integer
	assert(nextToken.isType(Token::Type::IntegerLiteral));

	// convert string to long long int
	long long int num = stoll(nextToken.lexeme());
	// create a new IntegerExpression node in AST
	unique_ptr<Expression> result = make_unique<IntegerExpression>(num);

	return move(result);
}

unique_ptr<Expression> Parser::parseParenExpression() {
	const Token& openParen = getNextToken();  // eat open parenthesis
	if (openParen.lexeme() != "(") {
		throw runtime_error(
			"Expected open paranthesis '(' before parenthesis expression");
	}

	auto expression = parseExpression();
	if (expression == nullptr) {
		return nullptr;
	}
	const Token& closeParen = getNextToken();  // eat close parenthesis
	if (closeParen.lexeme() != ")") {
		throw runtime_error(
			"Expected close parenthesis ')' after parenthesis expression");
	}

	return expression;
}

unique_ptr<Expression> Parser::parsePrimaryExpression() {
	const Token& tok = peekNextToken();	 // do not eat token
	switch (tok.type()) {
		case Token::Type::IntegerLiteral:
			return parseIntegerExpression();
		case Token::Type::Character:
			return parseParenExpression();
		default:
			throw runtime_error("Unknown token when expecting an expression");
	}
}

unique_ptr<Expression> Parser::parseExpression() {
	return unique_ptr<Expression>();
}
