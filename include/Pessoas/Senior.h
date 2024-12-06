#ifndef SENIOR_H
#define SENIOR_H

#include "Pessoa.h"


class Senior : public Pessoa
{
    private:
    int    livrosMaximosSenior; // Número máximo de livros que pode requisitar
    double descontoMultaSenior; // Desconto em multas (0.0 a 1.0)

    public:
        Senior(string nome, string NIF, int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, int totalMultaPorPagar, int totalMultaPago,int NumeroDeReservas,string categoria,int livrosMaximos,double descontoMulta);
        virtual ~Senior();
        
        void descricao() const override;
        int getPrazoDevolucao(string categoriaLivro) const override;
        bool PodeReservar() const override;
        bool PodeEmprestar() const override;
};

#endif // SENIOR_H_H
