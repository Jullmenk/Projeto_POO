#include "../../include/Pessoas/Pessoa.h"

Pessoa::Pessoa(string nome, string id, int livrosMaximos, double descontoMulta,int NumeroDeEmprestimosAtivos,int NumeroDeEmprestimosTotal,struct LivroEmprestado)
        :nome(nome), id(id), livrosMaximos(livrosMaximos), descontoMulta(descontoMulta),NumeroDeEmprestimosAtivos(NumeroDeEmprestimosAtivos),NumeroDeEmprestimosTotal(NumeroDeEmprestimosTotal),struct LivroEmprestado(LivroEmprestado){}

Pessoa::~Pessoa(){}

void Pessoa::descricao() const 
{
    cout << "Nome: " << nome << " | ID: " << id << " | Max. Livros: " << livrosMaximos
    << " | Desconto Multa: " << descontoMulta * 100 << "%" << " | Total de Emprestimos :"<< NumeroDeEmprestimosTotal << "NumeroDeEmprestimosAtivos : " << NumeroDeEmprestimosAtivos <<endl;
}

string Pessoa::getNome() const { return nome; }
string Pessoa::getId() const { return id; }
int Pessoa::getLivrosMaximos() const { return livrosMaximos; }
double Pessoa::getDescontoMulta() const { return descontoMulta; }

void Pessoa::adicionarEmprestimo(string idLivro,string titulo, string categoria, time_t dataEmprestimo) {
    if (livrosEmprestados.size() >= livrosMaximos) {
        cout << "Limite de livros emprestados atingido!" << endl;
        return;
    }
    livrosEmprestados.push_back({idLivro, titulo, categoria, dataEmprestimo});
    NumeroDeEmprestimosAtivos++;
    cout << "Livro adicionado com sucesso." << endl;
}

void Pessoa::listarEmprestimos() const {
    cout << "Livros emprestados por " << nome << ":\n";
    for (const auto& livro : livrosEmprestados) {
        cout << "ID: " << livro.idLivro
             << " | Titulo: " << livro.titulo
             << " | Categoria: " << livro.categoria
            //  << " | Data do emprestimo: " << ctime(&livro.dataEmprestimo)
            ;
    }
}

double Pessoa::calcularMultaTotal() const {
    double total = 0.0;
    // Aqui você implementa a lógica de cálculo da multa
    total *= (1.0 - descontoMulta); // Aplica desconto
    return total;
}
