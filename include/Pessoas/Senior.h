#ifndef SENIOR_H
#define SENIOR_H

#include "Pessoa.h"


class Senior : public Pessoa
{
    private:

    public:
        Senior(string nome, string id,int NumerodeEmprestimos,int NumeroDeReservas,string categoria);
        virtual ~Senior();
        
        void descricao() const override;
        int getPrazoDevolucao(string categoriaLivro) const override;
        bool PodeReservar() const override;
        bool PodeEmprestar() const override;
    protected:
};

#endif // SENIOR_H_H
