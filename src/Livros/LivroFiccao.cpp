#include "../../include/Livros/LivroFiccao.h"

LivroFiccao::LivroFiccao(string titulo, string autor, int ano, bool disponivel,string ISBN,string Genero_Literario,int Faixa_Etaria):Geral(titulo,autor,ano, disponivel),Genero_Literario(Genero_Literario),Faixa_Etaria(Faixa_Etaria)
{
    //ctor
}

LivroFiccao::~LivroFiccao()
{
    //dtor 
}

void LivroFiccao::descricao() const
{
    Geral::descricao();
    cout << "ISBN: " << ISBN <<"\n";
    cout << "Genero Literario: " << Genero_Literario <<"\n";
    cout << "Faixa Etaria: " << Faixa_Etaria <<"\n";
}