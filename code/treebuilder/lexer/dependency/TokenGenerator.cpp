// Copyright © 2015 Kevin Robert Stravers
/*
This file is part of Unnamed-Language Compiler Reference Implementation (ULCRI).

ULCRI is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ULCRI is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ULCRI.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "TokenGenerator.hpp"
#include "protocols/Action.hpp"
#include "protocols/Token.hpp"
#include "protocols/EntryType.hpp"

#include <cstddef>
#include <limits>

namespace tul
{
  namespace treebuilder
  {
    namespace lexer
    {
      namespace dependency
      {

        std::size_t TokenGenerator::consumeCharacter(char character_, protocols::Action action_)
        {
          using namespace protocols;
          switch (action_)
          {
            case Action::N:
              // Do nothing
              return 0;
            break;
            case Action::P:
              current_working_lexeme.push_back(character_);
              return 0;
            break;
            case Action::E:
              return std::numeric_limits<std::size_t>::max();
            break;
            case Action::PTG:
              current_working_lexeme.push_back(character_);
              token_stack.emplace_back(Token {0, 0, EntryType::GROUPING_SYMBOL, TokenType::UNIDENTIFIED, std::move(current_working_lexeme)} );
              return 1;
            break;
            case Action::TAPTG:
              token_stack.emplace_back(Token {0, 0, EntryType::ALPHA_DIGIT_OR_UNDERSCORE, TokenType::UNIDENTIFIED, std::move(current_working_lexeme)} );
              current_working_lexeme.push_back(character_);
              token_stack.emplace_back(Token {0, 0, EntryType::GROUPING_SYMBOL, TokenType::UNIDENTIFIED, std::move(current_working_lexeme)} );
              return 2;
            break;
            case Action::TA:
              token_stack.emplace_back(Token {0, 0, EntryType::ALPHA_DIGIT_OR_UNDERSCORE, TokenType::UNIDENTIFIED, std::move(current_working_lexeme)} );
              return 1;
            break;
            case Action::TAP:
              token_stack.emplace_back(Token {0, 0, EntryType::ALPHA_DIGIT_OR_UNDERSCORE, TokenType::UNIDENTIFIED, std::move(current_working_lexeme)} );
              current_working_lexeme.push_back(character_);
              return 1;
            break;
            case Action::TRP:
              token_stack.emplace_back(Token {0, 0, EntryType::QUOTE_SYMBOL, TokenType::UNIDENTIFIED, std::move(current_working_lexeme)} );
              current_working_lexeme.push_back(character_);
              return 1;
            break;
            case Action::TRPTG:
              token_stack.emplace_back(Token {0, 0, EntryType::QUOTE_SYMBOL, TokenType::UNIDENTIFIED, std::move(current_working_lexeme)} );
              current_working_lexeme.push_back(character_);
              token_stack.emplace_back(Token {0, 0, EntryType::GROUPING_SYMBOL, TokenType::UNIDENTIFIED, std::move(current_working_lexeme)} );
              return 2;
            break;
            case Action::TSP:
              token_stack.emplace_back(Token {0, 0, EntryType::OTHER_SYMBOL, TokenType::UNIDENTIFIED, std::move(current_working_lexeme)} );
              current_working_lexeme.push_back(character_);
              return 1;
            break;
            case Action::TSPTG:
              token_stack.emplace_back(Token {0, 0, EntryType::OTHER_SYMBOL, TokenType::UNIDENTIFIED, std::move(current_working_lexeme)} );
              current_working_lexeme.push_back(character_);
              token_stack.emplace_back(Token {0, 0, EntryType::GROUPING_SYMBOL, TokenType::UNIDENTIFIED, std::move(current_working_lexeme)} );
              return 2;
            break;
            case Action::TS:
              token_stack.emplace_back(Token {0, 0, EntryType::OTHER_SYMBOL, TokenType::UNIDENTIFIED, std::move(current_working_lexeme)} );
              return 1;
            break;
            case Action::TR:
              token_stack.emplace_back(Token {0, 0, EntryType::QUOTE_SYMBOL, TokenType::UNIDENTIFIED, std::move(current_working_lexeme)} );
              return 1;
            break;
            default:
            break;
          }
          return 0;
        }

        std::vector<protocols::Token> &TokenGenerator::getTokenStack()
        {
          return token_stack;
        }
      } // namespace dependency
    } // namespace lexer
  } // namespace treebuilder
} // namespace tul
