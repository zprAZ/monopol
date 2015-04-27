#ifndef MONOPOLY_CHANCE_HPP
#define MONOPOLY_CHANCE_HPP

namespace monopoly
{

class chance
{
	std::string text_m;
	virtual std::shared_ptr<visitor> create_visitor();
public:
	chance(const std::string& text):text_m(text){};
	std::shared_ptr<visitor> get_visitor();
	virtual ~chance();
}

} // namespace monopoly
#endif // MONOPOLY_CHANCE_HPP
