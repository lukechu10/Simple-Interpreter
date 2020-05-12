#pragma once
#include <iomanip>
#include <iostream>
#include <string>

class Token {
   public:
	enum class Type : unsigned {
		IntegerLiteral = 0,
		End,
		EndOfFile,
		Character
	};

	Token(Type type, std::string value) noexcept {
		m_type = type;
		m_lexeme = value;
	}

	Type type() const noexcept { return m_type; }
	bool isType(Type t) const noexcept { return m_type == t; }

	std::string lexeme() const noexcept { return m_lexeme; }
	void lexeme(std::string lexeme) noexcept { m_lexeme = std::move(lexeme); }

	friend std::ostream& operator<<(std::ostream& os, const Token::Type& t) {
		switch (t) {
			case Token::Type::IntegerLiteral:
				os << "IntegerLiteral";
				break;
			/*case Token::Type::DoubleLiteral:
				os << "DoubleLiteral";
				break;*/
			case Token::Type::Character:
				os << "Character";
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

	friend std::ostream& operator<<(std::ostream& os, const Token& tok) {
		os << std::left << "Type: " << std::setw(20) << tok.type()
		   << tok.lexeme();
		return os;
	}

   private:
	Type m_type;
	std::string m_lexeme;
};
