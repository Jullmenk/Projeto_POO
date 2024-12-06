#ifndef LEITORCOMUM_H
#define LEITORCOMUM_H

#include "Pessoa.h"


class LeitorComum : public Pessoa
{
    private:
    int    livrosMaximos; // Número máximo de livros que pode requisitar
    double descontoMulta; // Desconto em multas (0.0 a 1.0)
    public:
        LeitorComum(string nome, string NIF, int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, int totalMultaPorPagar, int totalMultaPago,int NumeroDeReservas,string categoria,int livrosMaximos,double descontoMulta);
        virtual ~LeitorComum();
        
        void descricao() const override;
        int getPrazoDevolucao(string categoriaLivro) const override;
        bool PodeReservar() const override;
        bool PodeEmprestar() const override;
};

#endif // LEITORCOMUM_H
