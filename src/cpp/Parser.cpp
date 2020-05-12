#include "Parser.h"

#include <cassert>
#include <memory>
#include <string>

using namespace std;
using namespace AST;

void Parser::parse() { parseExpression(); }

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

unique_ptr<Expression> Parser::parseBinOpRHS(int exprPrecedence,
											 std::unique_ptr<Expression> LHS) {
	while (true) {
		// if binop, get precedence
		assert(peekNextToken().lexeme().size() > 0);
		int tokPrecedence = getOpPrecedence(peekNextToken().lexeme()[0]);

		// if this binop has higher precedence than the previous one, consume it
		if (tokPrecedence < exprPrecedence) return LHS;

		char binOperator = getNextToken().lexeme()[0];

		// parse primary expression after operator
		auto RHS = parsePrimaryExpression();
		if (!RHS) return nullptr;

		assert(peekNextToken().lexeme().size() > 0);
		int nextPrecedence = getOpPrecedence(peekNextToken().lexeme()[0]);
	
		if (tokPrecedence < nextPrecedence) {
			RHS = parseBinOpRHS(tokPrecedence + 1, move(RHS));
			if (!RHS) return nullptr;
		}

		// merge RHS and LHS
		LHS = make_unique<BinaryExpression>(binOperator, move(LHS), move(RHS));
	}
}

unique_ptr<Expression> Parser::parseExpression() {
	auto LHS = parsePrimaryExpression();
	if (LHS == nullptr) return nullptr;
	return parseBinOpRHS(0, move(LHS));
}

int Parser::getOpPrecedence(char op) {
	switch (op) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	}
}