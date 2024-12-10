#include "../../include/Pessoas/Professor.h"

Professor::Professor(string nome, string NIF, int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, int totalMultaPorPagar, int totalMultaPago,int NumeroDeReservas,string categoria,int livrosMaximos,double descontoMulta)
    : Pessoa(nome, NIF, NumeroDeEmprestimosTotal, NumeroDeEmprestimosAtivos, totalMultaPorPagar, totalMultaPago, NumeroDeReservas,categoria),livrosMaximos(livrosMaximos),descontoMulta(descontoMulta) {} // 5 livros máximos, 20% de desconto

Professor::~Professor()
{
    //dtor
}

void Professor::descricao() const{
    Pessoa::descricao();
    cout << " | Maximo de Livros que Pode requisitar: " << livrosMaximos 
    << " | Desconto Multa: " << descontoMulta;
}

int Professor::getPrazoDevolucao(string categoriaLivro) const {
    if (categoriaLivro == "Cientifico") {
        return 7; 
    }
    return 2; 
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

int Professor::getLivrosMaximos() { return livrosMaximos; }
double Professor::getDescontoMulta() { return descontoMulta; }
double Professor::calcularMultaTotal() {
    return totalMultaPorPagar * (1 - descontoMulta);
}
void Professor::incrementarEmprestimosAtivos()  {
    if (NumeroDeEmprestimosAtivos < livrosMaximos) {
        NumeroDeEmprestimosAtivos++;
        NumeroDeEmprestimosTotal++;
    } else {
        cout << "Limite de empréstimos ativos atingido.\n";
    }
}

void Professor::addEmprestimo( Emprestimo& emprestimo)  {
        EmprestimosUser.push_back(emprestimo);
        incrementarEmprestimosAtivos();
}