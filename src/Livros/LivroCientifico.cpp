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
    if (!file.is_open()) {
        return false;
    }

    file << "Livro Científico\n";
    file << "Título: " << titulo << "\n";
    file << "Autor: " << autor << "\n";
    file << "Área: " << area << "\n";
    file << "ISBN: " << ISBN << "\n";
    file << "Edição: " << edicao << "\n";
    file << "---\n"; // Separador entre livros
    return true;
}