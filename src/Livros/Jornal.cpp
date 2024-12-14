#include "../../include/Livros/Jornal.h"

Jornal::Jornal(string categoria,string titulo, string autor, int ano, bool disponivel,string issn, string Seccao):Geral(categoria,titulo,autor,ano,disponivel),issn(issn),Seccao(Seccao)
{
    //ctor
}

Jornal::~Jornal()
{
    //dtor
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

void AlterarInformacaoDoLivro(){
    int type;
    cout << "\nNos Jornais So é possivel alterar a Secção";
    // cout << "O que deseja alterar ?";
    // cout << "\t1. Seccao" << endl;
    // cin>> type;

    cout << "\n Digite a nova secção do Jornal";
    cin.ignore(); 
    getline(cin, seccao);

}