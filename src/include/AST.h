// /**
//  * Header file contains declarations for Abstract Syntax Tree (class AST) and
//  * Abstract Syntax Tree Nodes
//  */
// #pragma once

// #include <vector>

// #include "Lexer.h"

// namespace Node {
// union BinaryExpressionValue {
// 	BinaryExpression expression;
// 	Token value;
// };

// /**
//  * Represents a node in a binary expression tree
//  */
// struct BinaryExpression {
//    public:
// 	BinaryExpressionValue left;
// 	Token operatorToken;
// 	BinaryExpressionValue right;
// };
// }  // namespace Node

// /**
//  * Manages an abstract syntax tree root
//  */
// class AST {
//    public:
// 	/**
// 	 * Create a new abstract syntax tree
// 	 * @param tokens list of tokens to be parsed
// 	 * @throw invalid syntax error
// 	 */
// 	explicit AST(std::vector<Token>& tokens);
// };