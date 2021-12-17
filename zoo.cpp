#include "zoo.h"


using namespace std;


Zoo::Zoo()
{}
Zoo::~Zoo()
{}
Zoo::Zoo(string a): m_adresse(a)
{
}
//-----------------------------------------------
Zoo::Zoo(const Zoo& z)
{
    if((this)!= &z)
    {
        vector<Animal *>::const_iterator ita;
        vector<Veterinaire>::const_iterator itv;

        for(ita = z.m_TAN.begin(); ita != z.m_TAN.end(); ita++)
        {
            if(typeid(**ita)==typeid(Animal))
            {
                Animal *p=new Animal(**ita);
                m_TAN.push_back(p);
            }
            else
            {
                Animal *p= new Lion(static_cast<const Lion&>(**ita));
                m_TAN.push_back(p);
            }
        }
//--------------------------------------------------------------------
        for(itv = z.m_TVet.begin(); itv != z.m_TVet.end(); itv++)
        {
            this->m_TVet.push_back(*itv);

        }
        m_adresse=z.m_adresse;
    }

}
