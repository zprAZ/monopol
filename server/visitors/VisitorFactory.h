#ifndef VISITORFACTORY_H
#define VISITORFACTORY_H

#include <memory>
#include <map>

#include "Visitor.h"

class VisitorFactory
{
public:
    typedef std::unique_ptr<Visitor> (*CreateVisitor)();
    VisitorFactory(const VisitorFactory& inp) = delete;
    VisitorFactory& operator=(const VisitorFactory&) = delete;
    static VisitorFactory& getInstance();
    std::unique_ptr<Visitor> createVisitor(const Visitor::VisitorType& id);
    void registerVisitor(const Visitor::VisitorType& type, CreateVisitor fun);
private:
    std::map<Visitor::VisitorType, CreateVisitor> creators;
    VisitorFactory();
};

#endif // VISITORFACTORY_H
