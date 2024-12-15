#include "../../include/Pessoas/Professor.h"

Professor::Professor(string nome, string NIF, int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, int totalMultaPorPagar, int totalMultaPago,int NumeroDeReservas,string categoria,int livrosMaximos,double descontoMulta)
    : Pessoa(nome, NIF, NumeroDeEmprestimosTotal, NumeroDeEmprestimosAtivos, totalMultaPorPagar, totalMultaPago, NumeroDeReservas,categoria),livrosMaximos(livrosMaximos),descontoMulta(descontoMulta) {} // 5 livros máximos, 20% de desconto

Professor::~Professor()
{
       cout << categoria << " destruído com sucesso.\n";
}

void Professor::descricao() const{
    Pessoa::descricao();
    cout << " | Maximo de Livros que Pode requisitar: " << livrosMaximos 
    << " | Desconto Multa: " << descontoMulta<< "\n";
}

int Professor::getPrazoDevolucao(string categoriaLivro) const {
    if (categoriaLivro == "Cientifico") {
        return 7; 
    }
    return 1; 
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

bool Professor::escreverFicheiro(ofstream& file) {
    Pessoa::escreverFicheiro(file);
    file
    << livrosMaximos << " ; "
    << descontoMulta << "\n";
    return true;
}

void Professor::alterarLivrosMaximos(int max) {
    livrosMaximos = max;
};

void Professor::alterarDescontos(int desc) {
    descontoMulta = desc;
};

void Professor::EnviarNotificacoesdeAtraso(){
    if(categoria == "Professor"){
        cout<<"O prazo de devolução já expirou, Gostaria de Prorrogar o Empréstimo?\n";
    }else{
    cout << "O prazo de devolução já expirou, foi acrescentado uma multa de"<<5*(1 - Professor::getDescontoMulta())<<"EUR.\n";
    }
}