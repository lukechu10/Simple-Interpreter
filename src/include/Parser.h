/**
 * Code for parsing tokens and generating an abstract syntax tree (AST)
 */
#pragma once

#include <vector>

#include "AST.h"

class Parser {
   public:
	Parser(std::vector<Token> tokens) : m_tokens(tokens) {}

   private:
	std::vector<Token> m_tokens;
};