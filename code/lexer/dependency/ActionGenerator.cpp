#include "ActionGenerator.hpp"
#include "protocols/Action.hpp"
#include "protocols/EntryType.hpp"

#include "libraries/Mealy.hpp"

#include <cstddef>

namespace tul
{
  namespace lexer
  {
    namespace dependency
    {
      protocols::Action ActionGenerator::computeAction(protocols::EntryType type)
      {
        return machine.transist(type, 5);
      }

      ActionGenerator::ActionGenerator()
      {
        /*
          n = no action
          p = push current OTHER_SYMBOL on to the current token
          tx = transfer something of type x
          tg = transfer a GROUPING_SYMBOL token
          tr = transfer a string token
          ts = transfer a OTHER_SYMBOL token
          ta = transfer an alnumu token
          txp = transfer x and then push
          ptx = push and then transfer
        */
        machine.setTransitionTable(table);
      }

      using namespace protocols;

      constexpr const tul::library::Mealy<std::size_t, protocols::Action, protocols::EntryType>::Compound ActionGenerator::table[]
        =
          { /*    ALPHA_DIGIT_OR_UNDERSCORE  GROUPING_SYMBOL QUOTE_SYMBOL OTHER_SYMBOL      WHITESPACE  */
            /*0*/ {1, Action::P},    {0, Action::PTG},   {2, Action::N},  {4, Action::P},   {0, Action::N},
            /*1*/ {1, Action::P},    {0, Action::TAPTG}, {2, Action::TA}, {4, Action::TAP}, {0, Action::TA},
            /*2*/ {2, Action::P},    {2, Action::P},     {3, Action::N},  {2, Action::P},   {2, Action::P},
            /*3*/ {1, Action::TRP},  {0, Action::TRPTG}, {2, Action::P},  {4, Action::TRP}, {0, Action::TR},
            /*4*/ {1, Action::TSP},  {0, Action::TSPTG}, {2, Action::TS}, {4, Action::P},   {0, Action::TS}
          };
    }
  }
}
