#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include "Pessoa.h"


class Estudante : public Pessoa
{
public:
    Estudante(string nome, string id, int NumeroDeEmprestimos,int NumeroDeReservas,string categoria);
    virtual ~Estudante();

    void descricao() const override;
    int getPrazoDevolucao(string categoriaLivro) const override;
    int getNumerodeReservas(string categoriaLivro) const override;
    bool PodeReservar() const override;
    bool PodeEmprestar() const override;};

#endif // ESTUDANTE_H
