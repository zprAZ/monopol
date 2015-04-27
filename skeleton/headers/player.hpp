#ifndef MONOPOLY_PLAYER_HPP
#define MONOPOLY_PLAYER_HPP

namespace monopoly
{

class player_visitor;

class player
{
protected:
	long money;
public:
	player(const double& inp_money):money(inp_money){}; 
	virtual ~player();
	virtual bool transaction(const double& inp){
		if(money >= std::abs(inp)){ 
		money += inp;
		return true;
		} else 
		return false;		
	}
	virtual void accept(const player_visitor& visitor) = 0;		
};

} // namespace monopoly

#endif // MONOPOLY_PLAYER_HPP
