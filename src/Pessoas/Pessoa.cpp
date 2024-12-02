#include "../../include/Pessoas/Pessoa.h"

Pessoa::Pessoa(string nome, string NIF, int livrosMaximos, double descontoMulta, int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, int totalMultaPorPagar, int totalMultaPago,int NumeroDeReservas,string categoria)
    : nome(nome), NIF(NIF), livrosMaximos(livrosMaximos), descontoMulta(descontoMulta), 
    NumeroDeEmprestimosTotal(NumeroDeEmprestimosTotal), NumeroDeEmprestimosAtivos(NumeroDeEmprestimosAtivos),
    totalMultaPorPagar(totalMultaPorPagar), totalMultaPago(totalMultaPago), NumeroDeReservas(NumeroDeReservas),categoria(categoria) {}

Pessoa::~Pessoa() {}

void Pessoa::descricao() const {
    cout << "Nome: " << nome 
         << " | NIF: " << NIF 
         << " | Numero maximo de Livros que Pode requisitar: " << livrosMaximos 
         << " | Desconto Multa: " << descontoMulta;

    if (totalMultaPago == 0) {
        cout << " | Multa a Pagar: " << totalMultaPorPagar;
    } else {
        cout << " | Multa Paga: " << totalMultaPago;
    }

    cout << " | Emprestimos Totais: " << NumeroDeEmprestimosTotal
         << " | Emprestimos Ativos: " << NumeroDeEmprestimosAtivos
         << " | Reservas: " << NumeroDeReservas
         << endl;
}

string Pessoa::getNome() const { return nome; }
string Pessoa::getNIF() const { return NIF; }
int Pessoa::getLivrosMaximos() const { return livrosMaximos; }
double Pessoa::getDescontoMulta() const { return descontoMulta; }

double Pessoa::calcularMultaTotal() const {
    return totalMultaPorPagar * (1 - descontoMulta);
}

// Métodos utilitários
void Pessoa::adicionarMulta(int valor) {
    totalMultaPorPagar += valor;
}

void Pessoa::pagarMulta(int valor) {
    if (valor <= totalMultaPorPagar) {
        totalMultaPorPagar -= valor;
        totalMultaPago += valor;
    } else {
        cout << "Valor de pagamento excede o total de multas pendentes!\n";
    }
}

void Pessoa::incrementarEmprestimosAtivos() {
    if (NumeroDeEmprestimosAtivos < livrosMaximos) {
        NumeroDeEmprestimosAtivos++;
        NumeroDeEmprestimosTotal++;
    } else {
        cout << "Limite de empréstimos ativos atingido.\n";
    }
}

void Pessoa::decrementarEmprestimosAtivos() {
    if (NumeroDeEmprestimosAtivos > 0) {
        NumeroDeEmprestimosAtivos--;
    } else {
        cout << "Nenhum empréstimo ativo para decrementar.\n";
    }
}

void Pessoa::adicionarReserva() {
    NumeroDeReservas++;
}

void Pessoa::removerReserva() {
    if (NumeroDeReservas > 0) {
        NumeroDeReservas--;
    } else {
        cout << "Nenhuma reserva ativa para remover.\n";
    }
}


// Adicionar empréstimo
void Pessoa::adicionarEmprestimo( Emprestimo& emprestimo) {
        Emprestimos.push_back(emprestimo);
        NumeroDeEmprestimosTotal++;
        NumeroDeEmprestimosAtivos++;
}

void Pessoa::adicionarReserva( Emprestimo& emprestimo) {
        Reservas.push_back(emprestimo);
        NumeroDeReservas++;
}

// Remover empréstimo

// Listar empréstimos ativos
void Pessoa::listarEmprestimosAtivos() const {
    if(NumeroDeEmprestimosTotal<=0){
        cout<<"Este Utilizador ainda nao requisitou livros\n";
        return;
    }
    cout << "Emprestimos ativos para o leitor: " << nome << endl;
    for (const auto& emprestimo : Emprestimos) {
        emprestimo.Descricao(); // Assumindo que a classe Emprestimo possui um método `descricao`
    };
}
