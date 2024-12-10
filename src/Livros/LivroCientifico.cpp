#include "../../include/Livros/LivroCientifico.h"


LivroCientifico::LivroCientifico(string titulo, string autor, int ano, bool disponivel,string ISBN,const string& area,int edicao):Geral(titulo,autor,ano, disponivel),ISBN(ISBN),area(area),edicao(edicao)
{
    //ctor
}

LivroCientifico::~LivroCientifico()
{
    //dtor
}

void LivroCientifico::descricao() const {
    Geral::descricao();
    cout << " | Area: " << area
         << " | Codigo ISBN: " << ISBN
         << " | Edicao: " << edicao << endl;
}

string LivroCientifico::getCodigo() const {
    return ISBN;
}

bool LivroCientifico::escreverFicheiro(ofstream& file) {
    Geral::escreverFicheiro(file);
    file
    << area << " ; "
    << ISBN << " ; "
    << edicao << " \n";
    return true;
}