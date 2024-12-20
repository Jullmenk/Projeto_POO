#ifndef LIVROCIENTIFICO_H
#define LIVROCIENTIFICO_H

#include "Geral.h"



class LivroCientifico : public Geral
{
    private:
    string area;  //Física, biologia, química, etc.
    string isbn;
    string edicao; // Número da edição do livro.

    public:
        LivroCientifico(string categoria,string titulo, string autor, int ano, bool disponivel,string isbn,string area, string edicao);
        virtual ~LivroCientifico();
        void descricao() const override;
        string getCodigo() const override;
        bool escreverFicheiro(ofstream& file) override;
        void AlterarInformacaoDoLivro() override;
};

#endif // LIVROCIENTIFICO_H
