#include "veterinaire.h"

using namespace std;

Veterinaire::Veterinaire()
{}
Veterinaire::Veterinaire(int id, string n, string p): m_id(id),m_nom(n),m_prenom(p)
{}
Veterinaire::~Veterinaire()
{}
//---------------------------------------------------
int Veterinaire::chercherMatcVeto(int m)
{

   vector<int>::iterator it;
   for(it = m_tabMatAnduVeto.begin(); it != m_tabMatAnduVeto.end(); it++)
   {
      if((*it)==m)
         return 1;
   }
   return -1;
}
//-------------------------------------------------
void Veterinaire::ajouterMtricule(int m)
{
   m_tabMatAnduVeto.push_back(m);
}
