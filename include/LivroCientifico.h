#ifndef LIVROCIENTIFICO_H
#define LIVROCIENTIFICO_H

#include "Geral.h" // Como está no mesmo diretório "include"



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

    protected:

    private:
};

#endif // LIVROCIENTIFICO_H
