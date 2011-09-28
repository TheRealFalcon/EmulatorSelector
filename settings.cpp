#include <QtXmlPatterns/QXmlQuery>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include "settings.h"

void getEmulators()
{
    QXmlQuery query;
    query.setQuery("doc('./settings.xml')/*");

    QStringList blah;
    query.evaluateTo(&blah);

    qDebug() << blah;
}
