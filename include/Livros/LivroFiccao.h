#ifndef LIVROFICCAO_H
#define LIVROFICCAO_H

#include "Geral.h"


class LivroFiccao : public Geral
{
    private:
    string isbn;
    string Genero_Literario; // Ficção científica, fantasia, romance, mistério
    int Faixa_Etaria; // Idade Permitida para a leitura

    public:
        LivroFiccao(string categoria,string titulo, string autor, int ano, bool disponivel,string isbn,string Genero_Literario, int Faixa_Etaria);
        virtual ~LivroFiccao();
        void descricao() const override;
        string getCodigo() const override;
        bool escreverFicheiro(ofstream& file) override;

};

#endif // LIVROFICCAO_H
