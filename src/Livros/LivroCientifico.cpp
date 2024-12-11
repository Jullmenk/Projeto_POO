#include "../../include/Livros/LivroCientifico.h"


LivroCientifico::LivroCientifico(string categoria,string titulo, string autor, int ano, bool disponivel,string isbn,const string& area,string edicao):Geral(categoria,titulo,autor,ano, disponivel),isbn(isbn),area(area),edicao(edicao)
{
    //ctor
}

LivroCientifico::~LivroCientifico()
{
    //dtor
}

void LivroCientifico::descricao() const {
    Geral::descricao();
    cout << " | Área: " << area
         << " | ISBN: " << isbn
         << " | Edição: " << edicao << endl;
}

string LivroCientifico::getCodigo() const {
    return isbn;
}

bool LivroCientifico::escreverFicheiro(ofstream& file) {
    Geral::escreverFicheiro(file);
    file
    << area << " ; "
    << isbn << " ; "
    << edicao << " \n";
    return true;
}