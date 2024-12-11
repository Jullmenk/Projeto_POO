#include "../../include/Livros/LivroEducativo.h"


LivroEducativo::LivroEducativo(string categoria,string titulo, string autor, int ano, bool disponivel,string isbn,int Nivel_Educacional,string Materia):Geral(categoria,titulo,autor,ano, disponivel),isbn(isbn),Nivel_Educacional(Nivel_Educacional),Materia(Materia)
{
    //ctor
}

LivroEducativo::~LivroEducativo()
{
    //dtor
}

void LivroEducativo::descricao() const {
    Geral::descricao();
    cout << " | ISBN: " << isbn
         << " | Nível Educacional: ";
    switch (Nivel_Educacional) {
        case 1: cout << "Fundamental"; break;
        case 2: cout << "Médio"; break;
        case 3: cout << "Superior"; break;
    }
    cout << " | Matéria: " << Materia << endl;
}

string LivroEducativo::getCodigo() const {
    return isbn;
}

bool LivroEducativo::escreverFicheiro(ofstream& file) {
    Geral::escreverFicheiro(file);
    file
    << Nivel_Educacional << " ; "
    << isbn << " ; "
    << Materia << " \n";
    return true;
}