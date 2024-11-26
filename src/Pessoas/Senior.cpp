#include "../../include/Pessoas/Senior.h"

Senior::Senior(string nome,string id):Pessoa(nome, id, 4, 0.3) {} // 4 livros máximos, 30% de desconto em multas

Senior::~Senior()
{

}

void Senior::descricao() const {
    cout << "Leitor Comum: ";
    Pessoa::descricao();
}
