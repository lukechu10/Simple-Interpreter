// /**
//  * Header file contains declarations for Abstract Syntax Tree (class AST) and
//  * Abstract Syntax Tree Nodes
//  */
#pragma once

#include <vector>

#include "Lexer.h"

namespace AST {
/**
 * Base class for all expression nodes
 */
class Expression {
   public:
	virtual ~Expression() noexcept {}
};

/**
 * Expression class for integer literals (e.g. "3")
 */
class IntegerExpression : public Expression {
   public:
	/**
	 * Create a new IntegerExpression node with value val
	 */
	IntegerExpression(long long int val) noexcept : m_val(val) {}

   private:
	long long int m_val;
};

/**
 * Expression class for a binary operator (e.g. "3 + 2")
 */
class BinaryExpression : public Expression {
   public:
	/**
	 * Create a new BinaryExpression with operator op and expressions leftExpr
	 * and rightExpr
	 * @param op operator char (opcode)
	 * @param leftExpr left expression
	 * @param rightExpr right expression
	 */
	BinaryExpression(char op, std::unique_ptr<Expression> leftExpr,
					 std::unique_ptr<Expression> rightExpr)
		: m_operator(op),
		  m_leftExpr(std::move(leftExpr)),
		  m_rightExpr(std::move(rightExpr)) {}

   private:
	char m_operator;
	std::unique_ptr<Expression> m_leftExpr;
	std::unique_ptr<Expression> m_rightExpr;
};
}  // namespace AST
