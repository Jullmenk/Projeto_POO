#include "../include/Revista.h"

Revista::Revista(string titulo, string autor, int ano, bool disponivel,string ISSN, string Tema):Geral(titulo,autor,ano,disponivel),ISSN(ISSN),Tema(Tema)
{
    //ctor
}

Revista::~Revista()
{
    //dtor
}

void Revista::descricao() const
{
    // Chama o método descricao da classe base
    Geral::descricao();
    // Adiciona a descrição específica da subclasse
    cout << "ISSN: " << ISSN << "\n";
    cout << "Tema: " << Tema << "\n";
}