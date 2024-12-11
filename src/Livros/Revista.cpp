#include "../../include/Livros/Revista.h"

Revista::Revista(string categoria,string titulo, string autor, int ano, bool disponivel,string issn, string Tema):Geral(categoria,titulo,autor,ano,disponivel),issn(issn),Tema(Tema)
{
    //ctor
}

Revista::~Revista()
{
    //dtor
}

void Revista::descricao() const {
    Geral::descricao();
    cout << " | Issn: " << issn
         << " | Tema: " << Tema << endl;
}
string Revista::getCodigo() const {
    return issn;
}

bool Revista::escreverFicheiro(ofstream& file) {
    Geral::escreverFicheiro(file);
    file
    << Tema << " ; "
    << issn << "\n";
    return true;
}