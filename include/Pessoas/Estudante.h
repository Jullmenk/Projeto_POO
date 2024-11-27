#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include <Pessoa.h>


class Estudante : public Pessoa
{
    private:

    public:
        Estudante(string nome, string id,int NumerodeEmprestimos);
        virtual ~Estudante();
        
        void descricao() const override;

    protected:
};

#endif // ESTUDANTE_H
