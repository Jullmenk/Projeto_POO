#include "../../include/Pessoas/LeitorComum.h"

LeitorComum::LeitorComum(string nome, string NIF, int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, int totalMultaPorPagar, int totalMultaPago,int NumeroDeReservas,string categoria,int livrosMaximos,double descontoMulta)
    : Pessoa(nome, NIF, NumeroDeEmprestimosTotal, NumeroDeEmprestimosAtivos, totalMultaPorPagar, totalMultaPago, NumeroDeReservas,categoria),livrosMaximos(livrosMaximos),descontoMulta(descontoMulta) {} // 5 livros máximos, 20% de desconto

LeitorComum::~LeitorComum()
{
       cout << categoria << " destruído com sucesso.\n";
}

void LeitorComum::descricao() const {
    Pessoa::descricao();
    cout << " | Maximo de Livros que Pode requisitar: " << livrosMaximos 
    << " | Desconto Multa: " << descontoMulta<< "\n";
}

int LeitorComum::getPrazoDevolucao(string categoriaLivro) const {
    return 1; 
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
int LeitorComum::getLivrosMaximos() { return livrosMaximos; }
double LeitorComum::getDescontoMulta() { return descontoMulta; }
double LeitorComum::calcularMultaTotal() {
    return totalMultaPorPagar * (1 - descontoMulta);
}
void LeitorComum::incrementarEmprestimosAtivos()  {
    if (NumeroDeEmprestimosAtivos < livrosMaximos) {
        NumeroDeEmprestimosAtivos++;
        NumeroDeEmprestimosTotal++;
    } else {
        cout << "Limite de empréstimos ativos atingido.\n";
    }
}

void LeitorComum::addEmprestimo( Emprestimo& emprestimo)  {
        EmprestimosUser.push_back(emprestimo);
        incrementarEmprestimosAtivos();
}

bool LeitorComum::escreverFicheiro(ofstream& file) {
    Pessoa::escreverFicheiro(file);
    file
    << livrosMaximos << " ; "
    << descontoMulta << "\n";
    return true;
}

void LeitorComum::alterarLivrosMaximos(int max) {
    livrosMaximos = max;
};

void LeitorComum::alterarDescontos(int desc) {
    descontoMulta = desc;
};

void LeitorComum::EnviarNotificacoesdeAtraso(){
    if(categoria == "Professor"){
        cout<<"O prazo de devolução já expirou, Gostaria de Prorrogar o Empréstimo?\n";
    }else{
    cout << "O prazo de devolução já expirou, foi acrescentado uma multa de"<<5*(1 - LeitorComum::getDescontoMulta())<<"EUR.\n";
    }
}