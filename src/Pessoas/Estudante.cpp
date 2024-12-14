#include "../../include/Pessoas/Estudante.h"

Estudante::Estudante(string nome, string NIF, int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, int totalMultaPorPagar, int totalMultaPago,int NumeroDeReservas,string categoria,int livrosMaximos,double descontoMulta)
    : Pessoa(nome, NIF, NumeroDeEmprestimosTotal, NumeroDeEmprestimosAtivos, totalMultaPorPagar, totalMultaPago, NumeroDeReservas,categoria),livrosMaximos(livrosMaximos),descontoMulta(descontoMulta) {} // 5 livros máximos, 20% de desconto

Estudante::~Estudante() {
       cout << categoria << " destruído com sucesso.\n";
}

void Estudante::descricao() const {
    Pessoa::descricao();
    cout << " | Maximo de Livros que Pode requisitar: " << livrosMaximos 
    << " | Desconto Multa: " << descontoMulta << "\n";
}

int Estudante::getPrazoDevolucao(string categoriaLivro) const {
    if (categoriaLivro == "Educativo") {
        return 2; // 4 dias para livros educativos
    }
    return 1; // Prazo padrão para outros tipos de livros
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



int Estudante::getLivrosMaximos() { return livrosMaximos; }
double Estudante::getDescontoMulta() { return descontoMulta; }
double Estudante::calcularMultaTotal() {
    return totalMultaPorPagar * (1 - descontoMulta);
}
void Estudante::incrementarEmprestimosAtivos()  {
    if (NumeroDeEmprestimosAtivos < livrosMaximos) {
        NumeroDeEmprestimosAtivos++;
        NumeroDeEmprestimosTotal++;
    } else {
        cout << "Limite de empréstimos ativos atingido.\n";
    }
}

void Estudante::addEmprestimo(Emprestimo& emprestimo){
        EmprestimosUser.push_back(emprestimo);
        incrementarEmprestimosAtivos();
}

bool Estudante::escreverFicheiro(ofstream& file) {
    Pessoa::escreverFicheiro(file);
    file
    << livrosMaximos << " ; "
    << descontoMulta << "\n";
    return true;
}

void Estudante::alterarLivrosMaximos(int max) {
    livrosMaximos = max;
};

void Estudante::alterarDescontos(int desc) {
    descontoMulta = desc;
};
