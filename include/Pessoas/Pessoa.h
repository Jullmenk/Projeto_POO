#ifndef PESSOA_H
#define PESSOA_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;
#include "../Utils/Emprestimos.h"


class Pessoa
{
    protected:
    string nome;
    string NIF;
    int livrosMaximos; // Número máximo de livros que pode requisitar
    double descontoMulta; // Desconto em multas (0.0 a 1.0)
    int totalMultaPorPagar;
    int totalMultaPago;
    int NumeroDeEmprestimosTotal;
    int NumeroDeEmprestimosAtivos;
    int NumeroDeReservas;
    string categoria;

    vector<Emprestimo> Emprestimos;
    vector<Emprestimo> Reservas;

    private:
    
    public:
        // Construtor e destruidor
        Pessoa(string nome, string NIF, int livrosMaximos, double descontoMulta, int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, int totalMultaPorPagar, int totalMultaPago,int NumeroDeReservas,string categoria);
        virtual ~Pessoa();

        // Método virtual para descrição
        virtual void descricao() const;

        // Métodos de acesso (getters)
        string getNome() const;
        string getNIF() const;
        string getCategoria() const;
        int getLivrosMaximos() const;
        double getDescontoMulta() const;

        // Métodos utilitários
        double calcularMultaTotal() const;
        void adicionarMulta(int valor);
        void pagarMulta(int valor);
        void incrementarEmprestimosAtivos();
        void decrementarEmprestimosAtivos();
        void adicionarReserva();
        void removerReserva();
        void adicionarEmprestimo(Emprestimo& emprestimo);
        void adicionarReserva(Emprestimo& emprestimo);
        void listarEmprestimos() const;
        void listarReservas() const;
        int getNumeroDeEmprestimosTotais();
        
        

        // Método puramente virtual
        virtual int getPrazoDevolucao(string categoriaLivro) const = 0;
        virtual int getNumerodeReservas(string categoriaLivro) const = 0;
        virtual bool PodeReservar() const = 0;
        virtual bool PodeEmprestar() const = 0;
    };

#endif // PESSOA_H
