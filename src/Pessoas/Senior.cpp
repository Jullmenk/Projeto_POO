#include "../../include/Pessoas/Senior.h"

Senior::Senior(string nome, string NIF, int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, int totalMultaPorPagar, int totalMultaPago,int NumeroDeReservas,string categoria,int livrosMaximos,double descontoMulta)
    : Pessoa(nome, NIF, NumeroDeEmprestimosTotal, NumeroDeEmprestimosAtivos, totalMultaPorPagar, totalMultaPago, NumeroDeReservas,categoria),livrosMaximos(livrosMaximos),descontoMulta(descontoMulta) {} // 5 livros máximos, 20% de desconto

Senior::~Senior()
{

}

void Senior::descricao() const {
    Pessoa::descricao();
    cout << " | Maximo de Livros que Pode requisitar: " << livrosMaximos 
    << " | Desconto Multa: " << descontoMulta;
}

int Senior::getPrazoDevolucao(string categoriaLivro) const {
    if (categoriaLivro == "Educativo") {
        return 14; 
    }
    return 7; 
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

int Senior::getLivrosMaximos() { return livrosMaximos; }
double Senior::getDescontoMulta() { return descontoMulta; }
double Senior::calcularMultaTotal() {
    return totalMultaPorPagar * (1 - descontoMulta);
}
void Senior::incrementarEmprestimosAtivos()  {
    if (NumeroDeEmprestimosAtivos < livrosMaximos) {
        NumeroDeEmprestimosAtivos++;
        NumeroDeEmprestimosTotal++;
    } else {
        cout << "Limite de empréstimos ativos atingido.\n";
    }
}

void Senior::addEmprestimo( Emprestimo& emprestimo)  {
        EmprestimosUser.push_back(emprestimo);
        incrementarEmprestimosAtivos();
}