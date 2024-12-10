#ifndef SENIOR_H
#define SENIOR_H

#include "Pessoa.h"


class Senior : public Pessoa
{
    private:
    int    livrosMaximos; // Número máximo de livros que pode requisitar
    double descontoMulta; // Desconto em multas (0.0 a 1.0)

    public:
        Senior(string nome, string NIF, int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, int totalMultaPorPagar, int totalMultaPago,int NumeroDeReservas,string categoria,int livrosMaximos,double descontoMulta);
        virtual ~Senior();
        
        void descricao() const override;
        int getPrazoDevolucao(string categoriaLivro) const override;
        bool PodeReservar() const override;
        bool PodeEmprestar() const override;
        int getLivrosMaximos() const override;
        double getDescontoMulta() const override;
        double calcularMultaTotal()const override;
        void incrementarEmprestimosAtivos() const override;
        void adicionarEmprestimo (Emprestimo &emprestimo)const override;
};

#endif // SENIOR_H_H
