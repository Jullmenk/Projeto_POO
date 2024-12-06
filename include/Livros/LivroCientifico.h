#ifndef LIVROCIENTIFICO_H
#define LIVROCIENTIFICO_H

#include "Geral.h"



class LivroCientifico : public Geral
{
    private:
    string area;  //Física, biologia, química, etc.
    string ISBN;
    int edicao; // Número da edição do livro.

    public:
        LivroCientifico(string titulo, string autor, int ano, bool disponivel,string ISBN,const string& area, int edicao);
        virtual ~LivroCientifico();
        void descricao() const override;
        string getCodigo() const override;
};

#endif // LIVROCIENTIFICO_H
