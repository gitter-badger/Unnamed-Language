#pragma once

namespace tul
{
	namespace protocols
	{
		enum class CrossTerminal
		{
			ENTER,
			EXIT,
			NONE,
			FIELD_DECLARATION_LIST,
			DECLARATION,
			ACCESS_SPECIFIER,
			OPTIONAL_EQUALS,
			COMMA_SEPARATED_LIST,
			OPTIONAL_CALL,
			METHOD_DECLARATION_LIST,
			COMMA_SEPARATED_TYPE_AND_NAME_LIST,
			STATEMENT_LIST,
			COMMA_SEPARATED_LIST_ITEM,
			STATEMENT,
			TYPE,
			EPSILONATE,
			GROUPER_LEFT_BRACE,
			GROUPER_RIGHT_BRACE,
			GROUPER_LEFT_BRACKET,
			GROUPER_RIGHT_BRACKET,
			GROUPER_LEFT_PARENTHESIS,
			GROUPER_RIGHT_PARENTHESIS,
			IDENTIFIER_CLASS,
			IDENTIFIER_ENUMERATION,
			IDENTIFIER_PACKAGE,
			IDENTIFIER_SUBROUTINE,
			IDENTIFIER_VARIABLE,
			INTEGER_LITERAL,
			KEYWORD_ASSEMBLY,
			KEYWORD_DO,
			KEYWORD_FOR,
			KEYWORD_GOTO,
			KEYWORD_IF,
			KEYWORD_LABEL,
			KEYWORD_PRIVATE,
			KEYWORD_PUBLIC,
			KEYWORD_RESTRICTED,
			KEYWORD_WHILE,
			PRIMITIVE_SIGNED,
			PRIMITIVE_UNSIGNED,
			STRING,
			SYMBOL_PLUS,
			SYMBOL_PLUS__PLUS,
			SYMBOL_MINUS,
			SYMBOL_MINUS__MINUS,
			SYMBOL_STAR,
			SYMBOL_STAR__STAR,
			SYMBOL_FORWARD_SLASH,
			SYMBOL_BACKWARD_SLASH,
			SYMBOL_AMPERSAND__AMPERSAND,
			SYMBOL_BAR__BAR,
			SYMBOL_AMPERSAND,
			SYMBOL_BAR,
			SYMBOL_CARET,
			SYMBOL_EXCLAMATION_MARK,
			SYMBOL_DOT__DOT,
			SYMBOL_DOT,
			SYMBOL_COMMA,
			SYMBOL_COLON__COLON,
			SYMBOL_COLON,
			SYMBOL_SEMICOLON,
			SYMBOL_LESS_THAN__LESS_THAN,
			SYMBOL_LESS_THAN,
			SYMBOL_GREATER_THAN__GREATER_THAN,
			SYMBOL_GREATER_THAN,
			UNIDENTIFIED,
			ENUM_END
		};
	}
}