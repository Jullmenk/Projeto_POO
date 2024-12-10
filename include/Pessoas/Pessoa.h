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
    int totalMultaPorPagar;
    int totalMultaPago;
    int NumeroDeEmprestimosTotal;
    int NumeroDeEmprestimosAtivos;
    int NumeroDeReservas;
    string categoria;

    vector<Emprestimo> EmprestimosUser;
    vector<Emprestimo> Reservas;
    
    public:
        // Construtor e destruidor
        Pessoa(string nome, string NIF, int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, int totalMultaPorPagar, int totalMultaPago,int NumeroDeReservas,string categoria);
        virtual ~Pessoa();

        // Método virtual para descrição
        virtual void descricao() const;

        // Métodos de acesso (getters)
        string getNome() const;
        string getNIF() const;
        string getCategoria() const;
        int getNumeroDeEmprestimosTotais();


        // Métodos utilitários
        void decrementarEmprestimosAtivos();
        void adicionarReserva();
        void removerReserva();
        void adicionarEmprestimo(Emprestimo& emprestimo);
        void adicionarReserva(Emprestimo& emprestimo);
        void listarEmprestimos() const;
        void listarReservas() const;
        void incrementarMulta();

        //Notificacoes
        void EnviarNotificacoesdeAtraso();
        void EnviarNotificacoesdeExlusaoDeReserva(string livro);
        void EnviarNotificacoesdeAquisicaoDaReserva(string livro);
        
        

        // Método puramente virtual
        virtual int getPrazoDevolucao(string categoriaLivro) const = 0;
        virtual bool PodeReservar() const = 0;
        virtual bool PodeEmprestar() const = 0;
        virtual int getLivrosMaximos() const ;
        virtual double getDescontoMulta() const ;
        virtual double calcularMultaTotal()const;
        virtual void incrementarEmprestimosAtivos() const ;
        virtual void adicionarEmprestimo (Emprestimo &emprestimo)const ;
    };

#endif // PESSOA_H
