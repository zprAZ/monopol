#ifndef MONOPOLY_BOARD_HPP
#define MONOPOLY_BOARD_HPP

#include "player.hpp"

namespace monopoly
{

class board
{
	std::vector<std::shared_ptr<player> > players_m;
	std::vector<std::shared_ptr<board_place> > places_m;
	std::vector<std::shared_ptr<pawn> > pawns_m;


};



} // namespace monopoly



#endif // MONOPOLY_BOARD_HPP
