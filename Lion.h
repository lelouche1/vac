#ifndef LION_H_INCLUDED
#define LION_H_INCLUDED

#include "Animal.h"

class Lion: public Animal
{
public:
   Lion();
   Lion(int,std::string,int);
   ~Lion();

private:
   int m_qtiteViand;
};

#endif // LION_H_INCLUDED
