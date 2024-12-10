#include "../../include/Livros/LivroFiccao.h"

LivroFiccao::LivroFiccao(string titulo, string autor, int ano, bool disponivel,string ISBN,string Genero_Literario,int Faixa_Etaria):Geral(titulo,autor,ano, disponivel),Genero_Literario(Genero_Literario),Faixa_Etaria(Faixa_Etaria)
{
    //ctor
}

LivroFiccao::~LivroFiccao()
{
    //dtor 
}

void LivroFiccao::descricao() const {
    Geral::descricao();
    cout << " | ISBN: " << ISBN
         << " | Genero Literario: " << Genero_Literario
         << " | Faixa Etaria: " << Faixa_Etaria << endl;
}

string LivroFiccao::getCodigo() const {
    return ISBN;
}

bool LivroFiccao::escreverFicheiro(ofstream& file) {
    Geral::escreverFicheiro(file);
    file
    << Faixa_Etaria << " ; "
    << ISBN << " ; "
    << Genero_Literario << " \n";
    return true;
}