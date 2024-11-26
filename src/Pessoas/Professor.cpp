#include "../../include/Pessoas/Professor.h"

Professor::Professor(string nome,string id):Pessoa(nome, id, 10, 0.5) {} // 10 livros máximos, 50% de desconto em multas{}

Professor::~Professor()
{
    //dtor
}

void Pessoa::descricao() const{
    cout << "Professor: ";
    Pessoa::descricao();
}