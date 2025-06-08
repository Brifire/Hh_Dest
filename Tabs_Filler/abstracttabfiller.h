#ifndef ABSTRACTTABFILLER_H
#define ABSTRACTTABFILLER_H

#include <QWidget>

class AbstractTabFiller
{

public:

virtual ~AbstractTabFiller() = default;
virtual void fill_tab(QWidget* tab)=0;

private:

protected:

};

#endif // ABSTRACTTABFILLER_H
