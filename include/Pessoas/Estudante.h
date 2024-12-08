#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include "Pessoa.h"


class Estudante : public Pessoa
{
private:
    int livrosMaximos; // Número máximo de livros que pode requisitar
    double descontoMulta; // Desconto em multas (0.0 a 1.0)

public:
    Estudante(string nome, string NIF, int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, int totalMultaPorPagar, int totalMultaPago,int NumeroDeReservas,string categoria,int livrosMaximos,double descontoMulta);
    virtual ~Estudante();

    void descricao() const override;
    int getPrazoDevolucao(string categoriaLivro) const override;
    bool PodeReservar() const override;
    bool PodeEmprestar() const override;};

#endif // ESTUDANTE_H
