#include "../../include/Pessoas/Pessoa.h"

Pessoa::Pessoa(string nome, string NIF, int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, int totalMultaPorPagar, int totalMultaPago,int NumeroDeReservas,string categoria)
    : nome(nome), NIF(NIF),NumeroDeEmprestimosTotal(NumeroDeEmprestimosTotal), NumeroDeEmprestimosAtivos(NumeroDeEmprestimosAtivos),
    totalMultaPorPagar(totalMultaPorPagar), totalMultaPago(totalMultaPago), NumeroDeReservas(NumeroDeReservas),categoria(categoria) {}

Pessoa::~Pessoa() {}

void Pessoa::descricao() const {
    cout << "Nome: " << nome 
         << " | NIF: " << NIF;
        cout << " | Multa a Pagar: " << totalMultaPorPagar;
        cout << " | Multa Paga: " << totalMultaPago;
    cout << " | Emprestimos Totais: " << NumeroDeEmprestimosTotal
         << " | Emprestimos Ativos: " << NumeroDeEmprestimosAtivos
         << " | Reservas: " << NumeroDeReservas
         << endl;
}

string Pessoa::getNome() const { return nome; }

string Pessoa::getNIF() const { return NIF; }

string Pessoa::getCategoria() const { return categoria; }

void Pessoa::incrementarMulta(){
    totalMultaPorPagar+=5;
}

void Pessoa::decrementarEmprestimosAtivos() {
    if (NumeroDeEmprestimosAtivos > 0) {
        NumeroDeEmprestimosAtivos--;
    } else {
        cout << "Nenhum empréstimo ativo para decrementar.\n";
    }
}

// Adicionar empréstimo

void Pessoa::adicionarReserva( Emprestimo& emprestimo) {
        Reservas.push_back(emprestimo);
        NumeroDeReservas++;
}

void Pessoa::adicionarReservaPelaLeitura(Emprestimo& emprestimo){
            Reservas.push_back(emprestimo);
}

void Pessoa::adicionarEmprestimoPelaLeitura(Emprestimo& emprestimo){
            EmprestimosUser.push_back(emprestimo);
}

void Pessoa::removerReserva( Emprestimo& emprestimo) {
    for (auto it = Reservas.begin(); it != Reservas.end(); ++it) {
        if (it->getIDLivroEmprestimo() == emprestimo.getIDLivroEmprestimo()) {
            Reservas.erase(it);
            NumeroDeReservas--;
            return;
        }
    }
}




int Pessoa::getNumeroDeEmprestimosTotais(){
    return NumeroDeEmprestimosTotal;
}

// Listar empréstimos ativos
void Pessoa::listarEmprestimos() const {
    system("cls");
    if(NumeroDeEmprestimosTotal<=0){
        cout<<"Este Utilizador ainda nao tem livros emprestados\n";
        return;
    }
    cout << "Emprestimos do leitor: " << nome << "\n\n"<<endl;
    for (const auto& emprestimo : EmprestimosUser) {
        emprestimo.Descricao(); // Assumindo que a classe Emprestimo possui um método `descricao`
    };
}

void Pessoa::listarReservas() const {
    system("cls");
    if(NumeroDeReservas<=0){
        cout<<"Este Utilizador nao tem livros reservados\n";
        return;
    }
    cout << "Reservas do leitor: " << nome << endl;
    for (const auto& reservas : Reservas) {
        reservas.Descricao(); // Assumindo que a classe Emprestimo possui um método `descricao`
    };
}

void Pessoa::EnviarNotificacoesdeAtraso(){
    cout << "";
}

void Pessoa::EnviarNotificacoesdeExlusaoDeReserva(string livro){
    cout 
    <<"Ola,"<<nome
    <<"O Livro " <<livro<<" que havia reservado nesse momento se encontra disponivel,"
    <<"mas verificamos que nesse momento atingiu o limite de livros que pode ter ao mesmo tempo"
    <<"Sendo Assim, estamos a entrar em contato para avisa-lo que a sua reserva sera anulada e o livro sera entregue ao outro leitor"
    <<"Atenciosamente, Biblioteca ESTGV.";
}

void Pessoa::EnviarNotificacoesdeAquisicaoDaReserva(string livro){
    cout 
    <<"Ola,"<<nome
    <<"O Livro " <<livro<<" que havia reservado foi enviado para si.";
}

bool Pessoa::escreverFicheiro(ofstream& file){
    if (!file.is_open()) {
        return false;
    }
    file<< categoria << " ; "
    << nome << " ; "
    << NIF << " ; "
    << totalMultaPorPagar << " ; "
    << totalMultaPago << " ; "
    << NumeroDeEmprestimosTotal <<" ; "
    << NumeroDeEmprestimosAtivos <<" ; "
    << NumeroDeReservas <<" ; ";
} 