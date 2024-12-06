#ifndef LIVROEDUCATIVO_H
#define LIVROEDUCATIVO_H

#include "Geral.h"


class LivroEducativo : public Geral
{
    private:
    string ISBN;
    int Nivel_Educacional; // 1 - Fundamental , 2 - Medio, 3 - Superior 
    string Materia; // Matemática, história, física, etc..

    public:
        LivroEducativo(string titulo, string autor, int ano, bool disponivel,string ISBN,int Nivel_Educacional,string Materia);
        virtual ~LivroEducativo();
        void descricao() const override;
        string getCodigo() const override;
};

#endif // LIVROEDUCATIVO_H
