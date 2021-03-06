#ifndef BOARD_PLACE_HPP
#define BOARD_PLACE_HPP

namespace monopoly
{
	
class board_place
{
protected
	const int id_m;
public:
	enum class type: int {CORNER_PLACE = 0, RAILWAYS_PLACE = 1, COUNTER_PLACE = 2, CHANCE_PLACE = 3, }
	board_place(int id_inp):id_m(id_inp){};
	int get_id() const {return id_m;}
	virtual ~board_place() {};
};



} // namespace monopoly


#endif // BOARD_PLACE_HPP
