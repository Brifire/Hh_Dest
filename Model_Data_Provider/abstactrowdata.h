#ifndef ABSTACTROWDATA_H
#define ABSTACTROWDATA_H

#include <qcontainerfwd.h>

class AbstractRowData
{
public:
    virtual ~AbstractRowData()=default;
    virtual void calc()=0;
    virtual QStringList to_string_list() const=0;
};

#endif // ABSTACTROWDATA_H
