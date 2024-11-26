#include "../../include/Livros/LivroCientifico.h"


LivroCientifico::LivroCientifico(string titulo, string autor, int ano, bool disponivel,string ISBN,const string& area,int edicao):Geral(titulo,autor,ano, disponivel),ISBN(ISBN),area(area),edicao(edicao)
{
    //ctor
}

LivroCientifico::~LivroCientifico()
{
    //dtor
}

void LivroCientifico::descricao() const
{
    Geral::descricao();
    cout << "Area: " << area << "\n";
    cout << "Codigo ISBN: " << ISBN << "\n";
    cout << "Edicao: " << edicao << "\n";
}