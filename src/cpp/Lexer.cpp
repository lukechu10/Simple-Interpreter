#include "Lexer.h"

#include <exception>

using namespace std;

Lexer::Lexer(istream& stream) { m_stream = &stream; }

Token Lexer::next() {
	// get all whitespace characters and throw away
	while (isSpace(m_stream->peek())) {
		m_stream->get();
	}

	if (m_stream->peek() == EOF) {
		return Token(Token::Type::EndOfFile, "");
	} else if (isDigit(m_stream->peek())) {
		return integerToken();
	} else {
		return operatorToken();
	}
}

bool Lexer::isSpace(char c) const noexcept {
	switch (c) {
		case ' ':
		case '\n':
		case '\r':
		case '\t':
			return true;
		default:
			return false;
	}
}

bool Lexer::isDigit(char c) const noexcept {
	// check if char c is between char '0' and '9' according to ascii value
	return '0' <= c && c <= '9';
}

bool Lexer::isOperator(char c) const noexcept {
	switch (c) {
		case '+':
		case '-':
		case '*':
		case '/':
			return true;
		default:
			return false;
	}
}

Token Lexer::integerToken() {
	string lexemeBuffer;

	while (m_stream->good() && isDigit(m_stream->peek())) {
		lexemeBuffer += m_stream->get();  // add next character to lexemeBuffer
										  // as long as there is no whitespace
	}

	return Token(Token::Type::IntegerLiteral, lexemeBuffer);
}

Token Lexer::operatorToken() {
	char tokenChar = m_stream->get();  // eat character
	return Token(Token::Type::Character, string(1, tokenChar));
}