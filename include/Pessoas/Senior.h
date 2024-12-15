#ifndef SENIOR_H
#define SENIOR_H

#include "Pessoa.h"


class Senior : public Pessoa
{
    private:
    int    livrosMaximos; // 10
    double descontoMulta; // 0.5

    public:
        Senior(string nome, string NIF, int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, int totalMultaPorPagar, int totalMultaPago,int NumeroDeReservas,string categoria,int livrosMaximos,double descontoMulta);
        virtual ~Senior();
        
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

#endif // SENIOR_H_H
