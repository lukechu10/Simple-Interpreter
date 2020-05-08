#pragma once
#include <istream>

#include "Token.h"

class Lexer {
   public:
	/**
	 * Create a new Lexer object
	 * @param stream stream for Lexer to read from
	 */
	explicit Lexer(std::istream& stream);

    Token next();

   private:
	/**
	 * @returns true if c is a whitespace character, false otherwise
	 */
	bool isSpace(char c) const noexcept;
	/**
	 * @returns true if c is a number, false otherwise
	 */
	bool isDigit(char c) const noexcept;

    /**
     * @returns true if c is an operator character, false otherwise
     */
    bool isOperator(char c) const noexcept;

    /**
     * Reads next token as an integer token
     */
    Token integerToken();

    /**
     * Reads next token as an operator token
     */
    Token operatorToken();

	std::istream* m_stream;
};