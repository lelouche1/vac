#include "Animal.h"

using namespace std;

Animal::Animal()
{}
Animal::Animal(int mat, string esp):m_matricule(mat), m_espece(esp)
{}
Animal::~Animal()
{}
//-------------------------------------------------------
vector<string>::iterator Animal::verifDate(string d)
{
   vector<string>::iterator it;

   for(it = m_tabDate.begin(); it != m_tabDate.end(); it++)
   {
      if((*it)==d)
         return it;
   }
   return m_tabDate.end();
}
//--------------------------------------------------------
void Animal::ajouterDate(string da)
{
   try
   {
         if(verifDate(da) != m_tabDate.end())
      throw string("\n cette date existe deja \n");
      else
      {
         m_tabDate.push_back(da);
      }
   }
   catch (const string& ch)
   {
      cerr << ch << endl;
   }


}
