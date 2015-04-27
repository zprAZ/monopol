#ifndef MONOPOLY_CITY_HPP
#define MONOPOLY_CITY_HPP

namespace monopoly
{

class city: public board_place
{
	std::string name;
	int number_of_houses;
	bool hotel;
public:
	std::string get_name()const {return name;} 
	
};


}



#endif
