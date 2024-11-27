#ifndef LEITORCOMUM_H
#define LEITORCOMUM_H

#include <Pessoa.h>


class LeitorComum : public Pessoa
{
    private:

    public:
        LeitorComum(string nome, string id,int NumerodeEmprestimos);
        virtual ~LeitorComum();
        
        void descricao() const override;

    protected:
};

#endif // LEITORCOMUM_H
