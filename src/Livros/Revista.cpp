#include "../../include/Livros/Revista.h"

Revista::Revista(string titulo, string autor, int ano, bool disponivel,string ISSN, string Tema):Geral(titulo,autor,ano,disponivel),ISSN(ISSN),Tema(Tema)
{
    //ctor
}

Revista::~Revista()
{
    //dtor
}

void Revista::descricao() const {
    Geral::descricao();
    cout << " | ISSN: " << ISSN
         << " | Tema: " << Tema << endl;
}
string Revista::getCodigo() const {
    return ISSN;
}