#ifndef PESSOA_H
#define PESSOA_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;
#include "../Utils/Emprestimos.h"
#include <fstream>



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
        virtual bool escreverFicheiro(ofstream& file); 


        // Métodos de acesso (getters)
        string getNome() const;
        string getNIF() const;
        string getCategoria() const;
        int getNumeroDeEmprestimosTotais();

        // Métodos utilitários
        void decrementarEmprestimosAtivos();
        void removerReserva(Emprestimo& emprestimo);
        void adicionarReserva(Emprestimo& emprestimo);

        void adicionarReservaPelaLeitura(Emprestimo& emprestimo);
        void adicionarEmprestimoPelaLeitura(Emprestimo& emprestimo);

        void listarEmprestimos() const;
        void listarReservas() const;
        void incrementarMulta();
        void AlterarEmprestimo( Emprestimo& emprestimo, time_t dias);
        //Notificacoes
        void EnviarNotificacoesdeAtraso();
        void EnviarNotificacoesdeExlusaoDeReserva(string livro);
        void EnviarNotificacoesdeAquisicaoDaReserva(string livro);

        // Método puramente virtual = 0 , só é acedida pelsa subclasses
        virtual int getPrazoDevolucao(string categoriaLivro) const = 0;
        virtual bool PodeReservar() const = 0;
        virtual bool PodeEmprestar() const = 0;
        virtual int getLivrosMaximos() = 0;
        virtual void alterarLivrosMaximos(int max) = 0;
        virtual void alterarDescontos(int desc) = 0;
        virtual double getDescontoMulta() = 0;
        virtual double calcularMultaTotal() = 0;
        virtual void incrementarEmprestimosAtivos() = 0;
        virtual void addEmprestimo(Emprestimo& emprestimo) = 0;
    
    };

#endif // PESSOA_H
