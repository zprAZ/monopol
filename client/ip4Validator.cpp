#include "ip4Validator.h"


IP4Validator::IP4Validator(QObject *parent):QValidator(parent)
{
}

QValidator::State IP4Validator::validate(QString &input, int &position) const
{
    if(input.isEmpty()) return QValidator::Invalid;
    QStringList slist = input.split(".");
    if(slist.size() > 4) return Invalid;
    bool emptyGroup = false;
    for(QStringList::const_iterator iter = slist.begin(); iter != slist.end() ; ++iter){
        bool ok;
        if(iter ->isEmpty() ){
        emptyGroup = true;
        continue;
        }
        int val = iter ->toInt(&ok);
        if(!ok || val< 0 || val>255) return Invalid;
    }
    if(slist.size()<4 || emptyGroup) return Intermediate;
    return Acceptable;
}
