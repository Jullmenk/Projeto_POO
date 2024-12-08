#include "../../include/Pessoas/LeitorComum.h"

LeitorComum::LeitorComum(string nome, string NIF, int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, int totalMultaPorPagar, int totalMultaPago,int NumeroDeReservas,string categoria,int livrosMaximos,double descontoMulta):Pessoa(nome,id,3,0.0,NumeroDeEmprestimos, 0, 0, 0,NumeroDeReservas, categoria){} // 3 livros máximos, sem desconto em multas

LeitorComum::~LeitorComum()
{
    //dtor
}

void LeitorComum::descricao() const {
    Pessoa::descricao();
}

int LeitorComum::getPrazoDevolucao(string categoriaLivro) const {
    return 2; 
}

bool LeitorComum::PodeReservar() const{
    if(NumeroDeReservas>=2){
        return false;
    }
    else{
        return true;
    }
}

bool LeitorComum::PodeEmprestar() const{
    if(NumeroDeEmprestimosAtivos >= livrosMaximos){
        return false;
    }
    else{
        return true;
    }
}