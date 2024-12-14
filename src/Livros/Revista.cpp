#include "../../include/Livros/Revista.h"

Revista::Revista(string categoria,string titulo, string autor, int ano, bool disponivel,string issn, string Tema):Geral(categoria,titulo,autor,ano,disponivel),issn(issn),Tema(Tema)
{
    //ctor
}

Revista::~Revista()
{
           cout << categoria << " destruído com sucesso.\n";
}

void Revista::descricao() const {
    Geral::descricao();
    cout << " | ISSN: " << issn
         << " | Tema: " << Tema << endl;
}
string Revista::getCodigo() const {
    return issn;
}

bool Revista::escreverFicheiro(ofstream& file) {
    Geral::escreverFicheiro(file);
    file
    << Tema << " ; "
    << issn << "\n";
    return true;
}

void Revista::AlterarInformacaoDoLivro(){
    cout << "\nNas Revistas Só é possivel alterar o Tema";
    cout << "\n Digite o novo Tema do Jornal : ";
    cin.ignore(); 
    getline(cin, Tema);
}