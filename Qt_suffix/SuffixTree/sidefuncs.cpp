#include <sidefuncs.h>

QString s2q(const string &s)
{
    return QString(QString::fromLocal8Bit(s.c_str()));
}
string q2s(const QString &s)
{
    return string((const char *)s.toLocal8Bit());
}
