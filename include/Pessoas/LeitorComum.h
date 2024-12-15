#ifndef LEITORCOMUM_H
#define LEITORCOMUM_H

#include "Pessoa.h"


class LeitorComum : public Pessoa
{
    private:
    int    livrosMaximos; // 3
    double descontoMulta; // 0
    public:
        LeitorComum(string nome, string NIF, int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, int totalMultaPorPagar, int totalMultaPago,int NumeroDeReservas,string categoria,int livrosMaximos,double descontoMulta);
        virtual ~LeitorComum();
        
        void descricao() const override;
        int getPrazoDevolucao(string categoriaLivro) const override;
        bool PodeReservar() const override;
        bool PodeEmprestar() const override;
        int getLivrosMaximos() override;
        void alterarLivrosMaximos(int max) override;
        void alterarDescontos(int desc) override;
        double getDescontoMulta() override;
        double calcularMultaTotal() override;
        void incrementarEmprestimosAtivos() override;
        void addEmprestimo (Emprestimo &emprestimo) override;
        bool escreverFicheiro(ofstream& file) override;
        void EnviarNotificacoesdeAtraso() override;

};

#endif // LEITORCOMUM_H
