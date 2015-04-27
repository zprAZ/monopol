#ifndef MONOPOLY_TOKEN_HPP
#define MONOPOLY_TOKEN_HPP

#include "pawn.hpp"
#include "player.hpp"

namespace monopoly
{

class player_visitor; // forward declaration
class pawn_visitor; // forward declaration

class token : public pawn
{
	int current_position_m;
	static int max_position_m;
	color color_m;
	std::shared_ptr<player> player_m;
public:
	token(const monopoly::token::color& inp_color, const int& max_pos, std::shared_ptr<player> inp);  
	enum class color : int {red = 1, green = 2, blue = 3, yellow = 4};
	virtual void go(const int& inp);
	virtual void get_last_movement();
	virtual void accept(const player_visitor& visitor);
	virtual void accept(const pawn_visitor& visitor);
};


} // namespace monopoly

#endif // MONOPOLY_TOKEN_HPP
