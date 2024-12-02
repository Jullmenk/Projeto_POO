#include "../../include/Pessoas/Professor.h"

Professor::Professor(string nome,string id,int NumerodeEmprestimos,int NumeroDeReservas,string categoria):Pessoa(nome, id, 10, 0.5,NumerodeEmprestimos, 0, 0, 0,NumeroDeReservas,categoria) {} // 10 livros máximos, 50% de desconto em multas{}

Professor::~Professor()
{
    //dtor
}

void Professor::descricao() const{
    Pessoa::descricao();
}

int Professor::getPrazoDevolucao(string categoriaLivro) const {
    if (categoriaLivro == "Educativo") {
        return 360; 
    }
    return 15; 
}

int Professor::getNumerodeReservas(string categoriaLivro) const {
    if (categoriaLivro == "Educativo") {
        return 10; 
    }
    return 5;
}


bool Professor::PodeReservar() const{
    if(NumeroDeReservas>=5){
        return false;
    }
    else{
        return true;
    }
}

bool Professor::PodeEmprestar() const{
    if(NumeroDeEmprestimosAtivos >= livrosMaximos){
        return false;
    }
    else{
        return true;
    }
}