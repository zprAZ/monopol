#ifndef MONOPOLY_PAY_CHANCE
#define MONOPOLY_PAY_CHANCE

#include"chance.hpp"

namespace monopoly
{

class pay_chance:public chance
{
	long payment;
	virtual std::unique_ptr<visitor> get_visitor() const;
	virtual void init(std::istream& inp);
public:
	pay_chance(
};

} // namespace monopoly


#endif // MONOPOLY_PAY_CHANCE
