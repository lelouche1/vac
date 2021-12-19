#ifndef ZOO_H_INCLUDED
#define ZOO_H_INCLUDED

#include "Animal.h"
#include "veterinaire.h"
#include <typeinfo>
#include "Lion.h"
#include <iostream>


class Zoo
{
public:
   Zoo();
   Zoo(std::string);
   ~Zoo();
   Zoo(const Zoo&);
   std::vector<Veterinaire>::iterator rechercherv(int);
   std::vector<Animal*>::iterator recherchera(int);
   void ajouter(const Animal&);
   void ajouter(const Lion&);
   Zoo& operator=(const Zoo&);
   void ajouterDate(int,std::string);
   void affecMatAoVeto(int, int);

private:
   std::string m_adresse;
   std::vector<Veterinaire> m_TVet;
   std::vector<Animal *> m_TAN;
};

#endif // ZOO_H_INCLUDED
