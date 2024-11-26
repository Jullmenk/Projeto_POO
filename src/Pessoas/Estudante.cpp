#include "../../include/Pessoas/Estudante.h"

Estudante::Estudante(string nome, string id):Pessoa(nome,id,5,0.2){} // 5 livros máximos, 20% de desconto em multas

Estudante::~Estudante()
{
    //dtor
}

void Estudante::descricao() const {
    cout << "Leitor Comum: ";
    Pessoa::descricao();
}
