#include "ChanceQueue.h"
#include <algorithm>
#include <random>

#include "visitors/CollectFromOthersVisitor.h"
#include "visitors/CollectVisitor.h"
#include "visitors/ReceivePrisonFreeVisitor.h"
#include "visitors/GoToDestinationVisitor.h"
#include "visitors/CollectVisitor.h"
#include "visitors/GoToPrisonVisitor.h"
#include "visitors/PayVisitor.h"
#include "visitors/MoveVisitor.h"
#include "visitors/TownModernizationVisitor.h"


ChanceQueue::ChanceQueue(QObject *parent) :
    QObject(parent)
{
    // PRISON FREE
    ReceivePrisonFreeVisitor* prisonFree = new ReceivePrisonFreeVisitor;
    visitors.push_back(std::unique_ptr<Visitor>(prisonFree));
    // BACK TO START
    GoToDestinationVisitor* visitor2 = new GoToDestinationVisitor;
    visitor2 ->init(0, false, QString("Going back to start"), false);
    visitors.push_back(std::unique_ptr<Visitor>(visitor2));
    // BEAUTY CONTEST
    CollectVisitor * visitor3 = new CollectVisitor;
    visitor3 -> init(200.0,QString("You took second prize in a beauty contest receive from the bank 200$"));
    visitors.push_back(std::unique_ptr<Visitor>(visitor3));
    // GOING TO PRISON
    GoToPrisonVisitor* visitor4 = new GoToPrisonVisitor;
    visitor4->init(3);
    visitors.push_back(std::unique_ptr<Visitor>(visitor4));
    // MEDICAL TREATMENT
    PayVisitor* visitor5 = new PayVisitor;
    visitor5 ->init(20,QString("You have to pay for medical treatment 20$"));
    visitors.push_back(std::unique_ptr<Visitor>(visitor5));
    // BACK TO VIENNA
    GoToDestinationVisitor* visitor6 = new GoToDestinationVisitor;
    visitor6->init(39, false, QString("You have to go back to Vienna"), false);
    visitors.push_back(std::unique_ptr<Visitor>(visitor6));
    // INHERIT 200
    CollectVisitor* visitor7 = new CollectVisitor;
    visitor7 ->init(200, QString("You inherit 200$"));
    visitors.push_back(std::unique_ptr<Visitor>(visitor7));
    // PENALTY PAYMENT
    PayVisitor* visitor8 = new PayVisitor;
    visitor8->init(20, QString("You pay penalty 20$"));
    visitors.push_back(std::unique_ptr<Visitor>(visitor8));
    // BIRTHDAY
    CollectFromOthersVisitor* visitor9 = new CollectFromOthersVisitor;
    visitor9->init(20,QString("You have birthday. Receive 20$ from every player"),
                   QString("Your friend have birthday today. You must give him 20$"));
    visitors.push_back(std::unique_ptr<Visitor>(visitor9));
    // ANNUAL PENSION
    CollectVisitor* visitor10 = new CollectVisitor;
    visitor10->init(200,QString("You receive annual pension 200$"));
    visitors.push_back(std::unique_ptr<Visitor>(visitor10));
    // INSURANCE PAYMENT
    PayVisitor* visitor11 = new PayVisitor;
    visitor11->init(20, QString("You have to pay for insurance 20$"));
    visitors.push_back(std::unique_ptr<Visitor>(visitor11));
    // GET 50 FRM BANK
    CollectVisitor* visitor12 = new CollectVisitor;
    visitor12->init(50, QString("You collect 50$ from bank"));
    visitors.push_back(std::unique_ptr<Visitor>(visitor12));
    // COLLECT 20 FROM STOREHOUSE
    CollectVisitor* visitor13 = new CollectVisitor;
    visitor13->init(20, QString("You collect 20$ from Storehouse"));
    visitors.push_back(std::unique_ptr<Visitor>(visitor13));
    // TAX REFOUND
    CollectVisitor* visitor14 = new CollectVisitor;
    visitor14->init(120, QString("You collect 120$ as a tax refound"));
    visitors.push_back(std::unique_ptr<Visitor>(visitor14));
    // BANK MADE A MISTAKE
    CollectVisitor* visitor15 = new CollectVisitor;
    visitor15->init(400, QString("Bank made a mistake - you receive 400$"));
    visitors.push_back(std::unique_ptr<Visitor>(visitor15));
    // PAY FOR SHOOL
    PayVisitor* visitor16 = new PayVisitor;
    visitor16->init(300, QString("You have to pay shool fee 300$"));
    visitors.push_back(std::unique_ptr<Visitor>(visitor16));
    // PAY FOR HOSPITAL TREATMENT
    PayVisitor* visitor17 = new PayVisitor;
    visitor17->init(400, QString("You have to pay for hospital 400$"));
    visitors.push_back(std::unique_ptr<Visitor>(visitor17));
    // GO TO NEAPOL
    GoToDestinationVisitor* visitor18 = new GoToDestinationVisitor;
    visitor18 ->init(6, true, QString("Going to NEAPOL if you cross START then collect 400$"), true);
    visitors.push_back(std::unique_ptr<Visitor>(visitor18));
    // GO TO EAST RAILWAY
    GoToDestinationVisitor* visitor19 = new GoToDestinationVisitor;
    visitor19 ->init(35, true, QString("Going to EAST RAILWAY if you cross START then collect 400$"), true);
    visitors.push_back(std::unique_ptr<Visitor>(visitor19));
    // BACK 3 MOVES
    MoveVisitor* visitor20 = new MoveVisitor;
    visitor20 -> init(-3, QString("You have to do three steps backward"));
    visitors.push_back(std::unique_ptr<Visitor>(visitor20));
    // TOWN MODERNIZATION 50, 200
    TownModernizationVisitor* visitor21 = new TownModernizationVisitor;
    visitor21 -> init(50, 200, QString("You are obliged to do town modernization."
                                       "Pay 50$ for every house,"
                                       "and 200 for every hotel"));
    visitors.push_back(std::unique_ptr<Visitor>(visitor21));
    // TOWN MODERNIZATION 80, 280
    TownModernizationVisitor* visitor22 = new TownModernizationVisitor;
    visitor22 -> init(80, 280, QString("You are obliged to do town modernization."
                                       "Pay 80$ for every house,"
                                       "and 280 for every hotel"));
    visitors.push_back(std::unique_ptr<Visitor>(visitor22));
    // BACK TO BRUSSEL
    GoToDestinationVisitor* visitor23 = new GoToDestinationVisitor;
    visitor23->init(23, true, QString("You have to go back to BRUSSEL."
                                      "If you cross START then collect 400$"), false);
    visitors.push_back(std::unique_ptr<Visitor>(visitor23));

    // VISITORS CONSTRUCTION FINISHED
    this->shuffle();
    currentPosition = visitors.begin();
}

void ChanceQueue::shuffle()
{
    /*std::random_device rd;
    std::default_random_engine g(rd());*/
    std::random_shuffle(visitors.begin(), visitors.end());
}

std::unique_ptr<Visitor> ChanceQueue::getVisitor()
{
    std::unique_ptr<Visitor> result = (*currentPosition++)->clone();
    if(currentPosition == visitors.end())
    {
     this->shuffle();
        currentPosition = visitors.begin();
    }
    return result;
}
