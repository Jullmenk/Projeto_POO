#include "../../include/Pessoas/LeitorComum.h"

LeitorComum::LeitorComum(string nome, string id):Pessoa(nome,id,3,0.0){} // 3 livros máximos, sem desconto em multas

LeitorComum::~LeitorComum()
{
    //dtor
}

void LeitorComum::descricao() const {
    cout << "Leitor Comum: ";
    Pessoa::descricao();
}
