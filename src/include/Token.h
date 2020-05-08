#pragma once
#include <string>

class Token {
   public:
	enum class Type : unsigned {
		IntegerLiteral = 0,
		DoubleLiteral,
		OperatorPlus,
		OperatorMinus,
		OperatorAsterix,
		OperatorSlash,
		End,
		EndOfFile
	};

	Token(Type type, std::string value) noexcept {
		m_type = type;
		m_lexeme = value;
	}

	Type type() const noexcept { return m_type; }
	bool isType(Type t) const noexcept { return m_type == t; }
	bool isLiteral() const noexcept {
		switch (m_type) {
			case Type::IntegerLiteral:
			case Type::DoubleLiteral:
				return true;
			default:
				return false;
		}
	}

	bool isOperator() const noexcept {
		switch (m_type) {
			case Type::OperatorPlus:
			case Type::OperatorMinus:
			case Type::OperatorAsterix:
			case Type::OperatorSlash:
				return true;
			default:
				return false;
		}
	}

	std::string lexeme() const noexcept { return m_lexeme; }
	void lexeme(std::string lexeme) noexcept { m_lexeme = std::move(lexeme); }

   private:
	Type m_type;
	std::string m_lexeme;
};

inline std::ostream& operator<<(std::ostream& os, const Token::Type& t) {
	switch (t) {
		case Token::Type::IntegerLiteral:
			os << "IntegerLiteral";
			break;
		case Token::Type::DoubleLiteral:
			os << "DoubleLiteral";
			break;
		case Token::Type::OperatorPlus:
			os << "OperatorPlus";
			break;
		case Token::Type::OperatorMinus:
			os << "OperatorPlus";
			break;
		case Token::Type::OperatorAsterix:
			os << "OperatorAsterix";
			break;
		case Token::Type::OperatorSlash:
			os << "OperatorSlash";
			break;
		case Token::Type::End:
			os << "End";
			break;
		case Token::Type::EndOfFile:
			os << "EOF";
			break;
		default:
			os << "UnknownToken";
			break;
	}
	return os;
}
