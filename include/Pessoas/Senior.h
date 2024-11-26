#ifndef SENIOR_H
#define SENIOR_H

#include <Pessoa.h>


class Senior : public Pessoa
{
    private:

    public:
        Senior(string nome, string id);
        virtual ~Senior();
        
        void descricao() const override;

    protected:
};

#endif // SENIOR_H_H
