#include "../../include/Pessoas/Pessoa.h"

Pessoa::Pessoa(string nome, string id, int livrosMaximos, double descontoMulta):nome(nome), id(id), livrosMaximos(livrosMaximos), descontoMulta(descontoMulta){}

Pessoa::~Pessoa()
{
    //dtor
}

void Pessoa::descricao() const 
{
        cout << "Nome: " << nome << " | ID: " << id << " | Máx. Livros: " << livrosMaximos
             << " | Desconto Multa: " << descontoMulta * 100 << "%" << endl;
}

string Pessoa::getNome() const { return nome; }
string Pessoa::getId() const { return id; }
int Pessoa::getLivrosMaximos() const { return livrosMaximos; }
double Pessoa::getDescontoMulta() const { return descontoMulta; }