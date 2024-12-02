#ifndef LEITORCOMUM_H
#define LEITORCOMUM_H

#include "Pessoa.h"


class LeitorComum : public Pessoa
{
    private:

    public:
        LeitorComum(string nome, string id,int NumerodeEmprestimos,int NumeroDeReservas,string categoria);
        virtual ~LeitorComum();
        
        void descricao() const override;
        int getPrazoDevolucao(string categoriaLivro) const override;
        int getNumerodeReservas(string categoriaLivro) const override;
        bool PodeReservar() const override;
        bool PodeEmprestar() const override;
    protected:
};

#endif // LEITORCOMUM_H
