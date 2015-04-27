#ifndef MONOPOLY_CHANCE_HPP
#define MONOPOLY_CHANCE_HPP

namespace monopoly
{

class chance
{
	queue queue_m;
	std::string text_m;
	int id_m;
	virtual std::unique_ptr<visitor> create_visitor() = 0;
	virtual void init(std::istream& inp) = 0;
public:
	enum class queue:int{ JUST_CHANCE = 0, COMMUNITY_CHEST = 1}
	enum class type:int{PAY = 0, GO = 1, COLLECT = 2, REPAIR = 3, PAY_TO_OTHERS = 4, COLLECT_FROM_OTHERS = 5}
	chance(const queue& inp_type,const std::string& text, const int& id):text_m(text), id_m(id),type_m(inp_type){}
	chance(){};
	void load(std::istream& inp);
	std::shared_ptr<visitor> get_visitor() const;
	int get_id()const {return id_m;}
	queue get_queue()const {return type_m;}
	virtual ~chance();
};

} // namespace monopoly
#endif // MONOPOLY_CHANCE_HPP
