#include "../../include/Livros/Jornal.h"

Jornal::Jornal(string titulo, string autor, int ano, bool disponivel,string ISSN, string Seccao):Geral(titulo,autor,ano,disponivel),ISSN(ISSN),Seccao(Seccao)
{
    //ctor
}

Jornal::~Jornal()
{
    //dtor
}

void Jornal::descricao() const {
    Geral::descricao();
    cout << " | ISSN: " << ISSN
         << " | Seccao: " << Seccao << endl;
}

string Jornal::getCodigo() const {
    return ISSN;
}