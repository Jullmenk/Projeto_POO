#include "../../include/Livros/LivroFiccao.h"

LivroFiccao::LivroFiccao(string categoria,string titulo, string autor, int ano, bool disponivel,string isbn,string Genero_Literario,int Faixa_Etaria):Geral(categoria,titulo,autor,ano, disponivel),Genero_Literario(Genero_Literario),Faixa_Etaria(Faixa_Etaria),isbn(isbn)
{
    //ctor
}

LivroFiccao::~LivroFiccao()
{
    //dtor 
}

void LivroFiccao::descricao() const {
    Geral::descricao();
    cout 
         << " | Género Literário: " << Genero_Literario
         << " | Faixa Etaria: " << Faixa_Etaria 
         << " | ISBN: " << isbn << endl;
}

string LivroFiccao::getCodigo() const {
    return isbn;
}

bool LivroFiccao::escreverFicheiro(ofstream& file) {
    Geral::escreverFicheiro(file);
    file
    << Faixa_Etaria << " ; "
    << isbn << " ; "
    << Genero_Literario << " \n";
    return true;
} 