#ifndef LIVROFICCAO_H
#define LIVROFICCAO_H

#include "Geral.h"


class LivroFiccao : public Geral
{
    private:
    string ISBN;
    string Genero_Literario; // Ficção científica, fantasia, romance, mistério
    int Faixa_Etaria; // Idade Permitida para a leitura

    public:
        LivroFiccao(string titulo, string autor, int ano, bool disponivel,string ISBN,string Genero_Literario, int Faixa_Etaria);
        virtual ~LivroFiccao();
        void descricao() const override;

    protected:

    private:
};

#endif // LIVROFICCAO_H
