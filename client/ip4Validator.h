#ifndef IP4VALIDATOR_H
#define IP4VALIDATOR_H

#include <QValidator>
#include <QStringList>

class IP4Validator : public QValidator
{
public:
    IP4Validator(QObject* parent = 0);
    void fixup(const QString& input) const{};
    QValidator::State validate(QString &input, int &position) const;

};

#endif // IP4VALIDATOR_H
