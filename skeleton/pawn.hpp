#ifndef MONOPOLY_PAWN_HPP
#define MONOPOLY_PAWN_HPP

namespace monopoly
{

class pawn
{
	protected:
	int last_movement;
	public:
	virtual ~pawn(){};
	virtual void go(const int& inp) = 0;
	virtual int get_last_movement() = 0;
};

} // end monopoly


#endif
