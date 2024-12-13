#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pessoa.h"


class Professor : public Pessoa
{
    private:
    int    livrosMaximos; // 10
    double descontoMulta; //0.5
    public:
        Professor(string nome, string NIF, int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, int totalMultaPorPagar, int totalMultaPago,int NumeroDeReservas,string categoria,int livrosMaximos,double descontoMulta);
        virtual ~Professor();

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
};

#endif // PROFESSOR_H
