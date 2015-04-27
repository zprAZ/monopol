#ifndef MONOPOLY_VISITOR_HPP
#define MONOPOLY_VISITOR_HPP

namespace monopoly
{

class player; // forward declaration
class pawn;

class visitor
{
public:
	virtual void visit(player& inp) = 0;
	virtual void visit(pawn& inp) = 0;
};



} // namespace monopoly

#endif // MONOPOLY_VISITOR_HPP
