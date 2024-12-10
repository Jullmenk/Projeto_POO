#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include "Pessoa.h"


class Estudante : public Pessoa
{
private:
    int livrosMaximos; // 5
    double descontoMulta; // 0.2

public:
    Estudante(string nome, string NIF, int NumeroDeEmprestimosTotal, int NumeroDeEmprestimosAtivos, int totalMultaPorPagar, int totalMultaPago,int NumeroDeReservas,string categoria,int livrosMaximos,double descontoMulta);
    virtual ~Estudante();

    void descricao() const override;
    int getPrazoDevolucao(string categoriaLivro) const override;
    bool PodeReservar() const override;
    bool PodeEmprestar() const override;
    int getLivrosMaximos() override;
    double getDescontoMulta() override;
    double calcularMultaTotal() override;
    void incrementarEmprestimosAtivos() override;
    void addEmprestimo(Emprestimo& emprestimo) override;
};  
#endif // ESTUDANTE_H
