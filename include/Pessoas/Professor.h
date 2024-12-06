#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pessoa.h"


class Professor : public Pessoa
{
    private:
    int    livrosMaximos; // Número máximo de livros que pode requisitar
    double descontoMulta; // Desconto em multas (0.0 a 1.0)
    public:
        Professor(string nome, string NIF, int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, int totalMultaPorPagar, int totalMultaPago,int NumeroDeReservas,string categoria,int livrosMaximos,double descontoMulta);
        virtual ~Professor();

        void descricao() const override;
        int getPrazoDevolucao(string categoriaLivro) const override;
        bool PodeReservar() const override;
        bool PodeEmprestar() const override;
};

#endif // PROFESSOR_H
