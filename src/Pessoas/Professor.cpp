#include "../../include/Pessoas/Professor.h"

Professor::Professor(string nome,string id,int NumerodeEmprestimos):Pessoa(nome, id, 10, 0.5,NumerodeEmprestimos) {} // 10 livros máximos, 50% de desconto em multas{}

Professor::~Professor()
{
    //dtor
}

void Professor::descricao() const{
    cout << "Professor: ";
    Pessoa::descricao();
}