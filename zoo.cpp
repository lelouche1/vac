#include "zoo.h"


using namespace std;


Zoo::Zoo()
{}
//---------------------------------------------------------------
Zoo::~Zoo()
{
    vector<Animal *>::iterator ita;

    for(ita = m_TAN.begin(); ita != m_TAN.end(); ita++)
    {
        delete (*ita);
    }

}
//--------------------------------------------------------------------
Zoo::Zoo(string a): m_adresse(a)
{}

//-----------------------------------------------
Zoo::Zoo(const Zoo& z)
{
    if((this)!= &z)
    {
        vector<Animal *>::const_iterator ita;

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

        m_TVet=z.m_TVet;
        m_adresse=z.m_adresse;
    }

}
//-----------------------------------------------------------
Zoo& Zoo::operator=(const Zoo& z)
{
    vector<Animal *>::iterator ita;

    for(ita = m_TAN.begin(); ita != m_TAN.end(); ita++)
    {
        delete (*ita);
    }
    m_TAN.clear();


    vector<Animal *>::const_iterator it;
    for(it = z.m_TAN.begin(); it != z.m_TAN.end(); it++)
    {
        Animal *p;
        if(typeid(**it) == typeid(Animal))
        {
            p= new Animal(**it);
        }
        else
        {
            p=new Lion(static_cast<const Lion&>(**it));
        }
        m_TAN.push_back(p);
    }

    m_TVet=z.m_TVet;
    m_adresse=z.m_adresse;

    return (*this);
}
//---------------------------------------------------------
vector<Veterinaire>::iterator Zoo::rechercherv(int n)
{
    vector<Veterinaire>::iterator itv;

    for(itv = m_TVet.begin(); itv != m_TVet.end(); itv++)
    {
        if(itv->get_id() == n)
            return itv;
    }
    return m_TVet.end();
}
//----------------------------------------------------------
std::vector<Animal*>::iterator Zoo::recherchera(int n)
{
    vector<Animal*>::iterator it;

    for(it = m_TAN.begin(); it != m_TAN.end(); it++)
    {
        if((*it)->get_matricul() == n)
            return it;
    }
    return m_TAN.end();
}
//----------------------------------------------------------
void Zoo::ajouter(const Animal& a)
{
    try
    {
        if(recherchera(a.get_matricul()) != m_TAN.end())
        {
            throw string("\n matricule est deja attribue _n");
        }
        else
        {
            Animal *p = new Animal(a);
            m_TAN.push_back(p);
        }
    }
    catch(const string& ch)
    {
        cerr<<ch<<endl;
    }

}
//------------------------------------------------------------
void Zoo::ajouter(const Lion& l)
{

    try
    {
        if(recherchera(l.get_matricul()) != m_TAN.end())
            throw string("\n desole cet identifiant existe deja \n");
        else
        {
            Animal *p= new Lion(l);
            m_TAN.push_back(p);
        }
    }
    catch (const string& ch)
    {
        cerr<<ch<<endl;
    }
}
//-------------------------------------------------
void Zoo::ajouterDate(int ma,string da)
{
    vector<Animal*>::iterator it=recherchera(ma);
    if( it != m_TAN.end())
    {
        (*it)->ajouterDate(da);
    }
}
//------------------------------------------------
void Zoo::affecMatAoVeto(int ma, int id)
{
    vector<Animal*>::iterator ita=recherchera(ma);
    vector<Veterinaire>::iterator itv=rechercherv(id);

    try
    {
        if(ita != m_TAN.end() && itv != m_TVet.end() && itv->chercherMatcVeto(ma) == 1)
        {
            itv->ajouterMtricule(ma);
        }
        else
            throw string("\n erreur d'ajout du matricule condition non respecter \n");
    }
    catch (const string& ch)
    {
        cerr << ch << endl;
    }


}
