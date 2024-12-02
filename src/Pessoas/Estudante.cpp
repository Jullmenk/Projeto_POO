#include "../../include/Pessoas/Estudante.h"

Estudante::Estudante(string nome, string id, int NumeroDeEmprestimos,int NumeroDeReservas,string categoria)
    : Pessoa(nome, id, 5, 0.2, NumeroDeEmprestimos, 0, 0, 0,NumeroDeReservas,categoria) {} // 5 livros máximos, 20% de desconto

Estudante::~Estudante() {}

void Estudante::descricao() const {
    Pessoa::descricao();
}

int Estudante::getPrazoDevolucao(string categoriaLivro) const {
    if (categoriaLivro == "Educativo") {
        return 30; // 30 dias para livros educativos
    }
    return 15; // Prazo padrão para outros tipos de livros
}

int Estudante::getNumerodeReservas(string categoriaLivro) const {
    if (categoriaLivro == "Educativo") {
        return 5; 
    }
    return 2;
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