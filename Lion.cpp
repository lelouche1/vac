#include "Lion.h"


using namespace std;

Lion::Lion()
{}

Lion::Lion(int m, string e, int v):Animal(m,e), m_qtiteViand(v)
{}
Lion::~Lion()
{}
