#include "../../include/Pessoas/Senior.h"

Senior::Senior(string nome, string id, int NumeroDeEmprestimos,int NumeroDeReservas,string categoria):Pessoa(nome, id, 4, 0.3,NumeroDeEmprestimos, 0, 0, 0,NumeroDeReservas,categoria) {} // 4 livros máximos, 30% de desconto em multas

Senior::~Senior()
{

}

void Senior::descricao() const {
    Pessoa::descricao();
}

int Senior::getPrazoDevolucao(string categoriaLivro) const {
    if (categoriaLivro == "Educativo") {
        return 30; 
    }
    return 15; 
}

int Senior::getNumerodeReservas(string categoriaLivro) const {
    if (categoriaLivro == "Educativo") {
        return 15; 
    }
    return 10;
}


bool Senior::PodeReservar() const{
    if(NumeroDeReservas>=10){
        return false;
    }
    else{
        return true;
    }
}

bool Senior::PodeEmprestar() const{
    if(NumeroDeEmprestimosAtivos >= livrosMaximos){
        return false;
    }
    else{
        return true;
    }
}