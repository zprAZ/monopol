#ifndef MONOPOLY_PLAYER_VISITOR_HPP
#define MONOPOLY_PLAYER_VISITOR_HPP

namespace monopoly
{

class player_visitor: public visitor
{
public:
	virtual void visit(player& inp);
	virtual void visit(pawn& inp);
};



}

#endif
