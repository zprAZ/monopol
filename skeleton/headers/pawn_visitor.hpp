#ifndef MONOPOLY_PAWN_VISITOR
#define MONOPOLY_PAWN_VISITOR

namespace monopoly
{

class pawn_visitor: public visitor
{
public:
	virtual void visit(pawn& inp);
	virtual void visit(player& inp);
};


} // namespace monopoly

#endif // MONOPOLY_PAWN_VISITOR
