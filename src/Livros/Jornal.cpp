#include "../../include/Livros/Jornal.h"

Jornal::Jornal(string categoria,string titulo, string autor, int ano, bool disponivel,string issn, string Seccao):Geral(categoria,titulo,autor,ano,disponivel),issn(issn),Seccao(Seccao)
{
    //ctor
}

Jornal::~Jornal()
{
           cout << categoria << " destruído com sucesso.\n";
}

void Jornal::descricao() const {
    Geral::descricao();
    cout << " | ISSN: " << issn
         << " | Secção: " << Seccao << endl;
}

string Jornal::getCodigo() const {
    return issn;
}

bool Jornal::escreverFicheiro(ofstream& file) {
    Geral::escreverFicheiro(file);
    file
    << Seccao << " ; "
    << issn << "\n";
    return true;
}

void Jornal::AlterarInformacaoDoLivro(){
    cout << "\nNos Jornais Só é possivel alterar a Secção";
    cout << "\n Digite a nova secção do Jornal :";
    cin.ignore(); 
    getline(cin, Seccao);
}