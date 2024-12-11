#ifndef LIVROCIENTIFICO_H
#define LIVROCIENTIFICO_H

#include "Geral.h"



class LivroCientifico : public Geral
{
    private:
    string area;  //Física, biologia, química, etc.
    string isbn;
    int edicao; // Número da edição do livro.

    public:
        LivroCientifico(string categoria,string titulo, string autor, int ano, bool disponivel,string isbn,const string& area, int edicao);
        virtual ~LivroCientifico();
        void descricao() const override;
        string getCodigo() const override;
        bool escreverFicheiro(ofstream& file) override;
};

#endif // LIVROCIENTIFICO_H
