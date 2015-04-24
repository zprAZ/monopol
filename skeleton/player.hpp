#ifndef PLAYER_HPP
#define PLAYER_HPP

namespace monopoly
{


class player
{
protected:
	double money;
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
};

}

#endif
