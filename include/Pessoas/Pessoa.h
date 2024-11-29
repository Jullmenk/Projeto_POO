#ifndef PESSOA_H
#define PESSOA_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;


struct LivroEmprestado {
    string idLivro;
    string titulo;
    string categoria;
    time_t dataEmprestimo;
    bool recebido;
    bool devolvido;

    LivroEmprestado(std::string titulo = "", std::string dataEmprestimo = "", bool devolvido = false)
        : titulo(titulo), dataEmprestimo(dataEmprestimo), devolvido(devolvido) {}
};

class Pessoa
{
    protected:
    string nome;
    string id;
    int livrosMaximos; // Número máximo de livros que pode requisitar
    double descontoMulta; // Desconto em multas (0.0 a 1.0)
    int totalMultaPorPagar;
    int totalMultaPago;
    int NumeroDeEmprestimosTotal;
    int NumeroDeEmprestimosAtivos;

    struct LivroEmprestado {
    string idLivro;
    string titulo;
    string categoria;
    time_t dataEmprestimo;
    bool recebido;
    };

    private:
    vector<LivroEmprestado> livrosEmprestados;

    public:
        Pessoa(string nome, string id, int livrosMaximos, double descontoMulta,int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, struct LivroEmprestado );
        virtual ~Pessoa();
        virtual void descricao() const ;
 
        string getNome() const;
        string getId() const;
        int getLivrosMaximos() const;
        double getDescontoMulta() const;
        void adicionarEmprestimo(string idLivro, string titulo,string categoria, time_t dataEmprestimo);
        void listarEmprestimos() const;
        double calcularMultaTotal() const;



};

#endif // PESSOA_H
