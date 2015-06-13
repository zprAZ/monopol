#include "TaxPlace.h"
#include "visitors/PayVisitor.h"


TaxPlace::TaxPlace(const int& id, const QString& name):BoardPlace(id, name)
{
}
std::unique_ptr<Visitor> TaxPlace::createVisitor(int playerId)
{
    PayVisitor* visitor = new PayVisitor;
    visitor ->init(this->taxValue, this->message);
    return std::unique_ptr<Visitor>(visitor);
}
int TaxPlace::implementGetNumberOfBuildHouses() const
{
    return 0;
}
int TaxPlace::implementGetNumberOfBuildHotels() const
{
    return 0;
}
void TaxPlace::implementBuildHouse()
{
    // do nothing
}

void TaxPlace::implementBuildHotel()
{
    // do nothing
}

void TaxPlace::implementSetOwnership(std::shared_ptr<Player> inp)
{
    // do nothing
}

void TaxPlace::init(const double& tax, const QString& message)
{
    this->taxValue = tax;
    this->message = message;
}

