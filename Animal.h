#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>

class Animal
{
public:
   Animal();
   Animal(int,std::string);
   virtual ~Animal();
   int get_matricul()const { return m_matricule; }
   void ajouterDate(std::string);
   std::vector<std::string>::iterator verifDate(std::string);
   //virtual void afficher();

protected:
   int m_matricule;
   std::string m_espece;
   std::vector<std::string> m_tabDate;
};


#endif // ANIMAL_H_INCLUDED
