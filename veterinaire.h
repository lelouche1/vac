#ifndef VETERINAIRE_H_INCLUDED
#define VETERINAIRE_H_INCLUDED

#include <string>
#include <vector>

class Veterinaire
{
public:
   Veterinaire();
   Veterinaire(int, std::string, std::string);
   ~Veterinaire();
   int get_id()const { return m_id;}

private:
   int m_id;
   std::string m_nom, m_prenom;
   std::vector<int> m_tabMatAnduVeto;
};

#endif // VETERINAIRE_H_INCLUDED
