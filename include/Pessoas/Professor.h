#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <Pessoa.h>


class Professor : public Pessoa
{
    protected:

    public:
        Professor(string nome, string id,int NumerodeEmprestimos);
        virtual ~Professor();

        void descricao() const override;

    private:
};

#endif // PROFESSOR_H
