#include "../../include/Pessoas/Estudante.h"

Estudante::Estudante(string nome, string id, int NumeroDeEmprestimos,int NumeroDeReservas,string categoria)
    : Pessoa(nome, id, 5, 0.2, NumeroDeEmprestimos, 0, 0, 0,NumeroDeReservas,categoria) {} // 5 livros máximos, 20% de desconto

Estudante::~Estudante() {}

void Estudante::descricao() const {
    Pessoa::descricao();
}

int Estudante::getPrazoDevolucao(string categoriaLivro) const {
    if (categoriaLivro == "Educativo") {
        return 4; // 4 dias para livros educativos
    }
    return 2; // Prazo padrão para outros tipos de livros
}


bool Estudante::PodeReservar() const{
    if(NumeroDeReservas>=2){
        return false;
    }
    else{
        return true;
    }
}

bool Estudante::PodeEmprestar() const{
    if(NumeroDeEmprestimosAtivos >= livrosMaximos){
        return false;
    }
    else{
        return true;
    }
}