#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pessoa.h"


class Professor : public Pessoa
{
    protected:

    public:
        Professor(string nome, string id,int NumerodeEmprestimos,int NumeroDeReservas,string categoria);
        virtual ~Professor();

        void descricao() const override;
        int getPrazoDevolucao(string categoriaLivro) const override;
        bool PodeReservar() const override;
        bool PodeEmprestar() const override;
    private:
};

#endif // PROFESSOR_H
