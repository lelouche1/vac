#ifndef ZOO_H_INCLUDED
#define ZOO_H_INCLUDED

#include "Animal.h"
#include "veterinaire.h"
#include <typeinfo>
#include "Lion.h"



class Zoo
{
public:
   Zoo();
   Zoo(std::string);
   ~Zoo();
   Zoo(const Zoo&);

private:
   std::string m_adresse;
   std::vector<Veterinaire> m_TVet;
   std::vector<Animal *> m_TAN;
};

#endif // ZOO_H_INCLUDED
