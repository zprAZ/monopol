#include "VisitorFactory.h"

VisitorFactory::VisitorFactory()
{

}

VisitorFactory& VisitorFactory::getInstance()
{
    static VisitorFactory instance;
    return instance;
}

std::unique_ptr<Visitor> VisitorFactory::createVisitor(const Visitor::VisitorType& id)
{
    auto iter = this->creators.find(id);
    if(iter != this->creators.end())
    {
        return iter->second();
    }
    else
    {
        return std::unique_ptr<Visitor>(nullptr);
    }
}

void VisitorFactory::registerVisitor(const Visitor::VisitorType& type, CreateVisitor fun)
{
    creators.insert(std::pair<Visitor::VisitorType,CreateVisitor>(type,fun));
}
