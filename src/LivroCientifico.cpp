#include "../include/LivroCientifico.h"


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
    // Chama o método descricao da classe base
    Geral::descricao();
    // Adiciona a descrição específica da subclasse
    cout << "Area: " << area << "\n";
    cout << "Codigo ISBN: " << ISBN << "\n";
    cout << "Edicao: " << edicao << "\n";
}