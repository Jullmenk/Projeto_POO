#ifndef LIVROEDUCATIVO_H
#define LIVROEDUCATIVO_H

#include "Geral.h"


class LivroEducativo : public Geral
{
    private:
    string isbn;
    int Nivel_Educacional; // 1 - Fundamental , 2 - Medio, 3 - Superior 
    string Materia; // Matemática, história, física, etc..

    public:
        LivroEducativo(string categoria,string titulo, string autor, int ano, bool disponivel,string isbn,int Nivel_Educacional,string Materia);
        virtual ~LivroEducativo();
        void descricao() const override;
        string getCodigo() const override;
        bool escreverFicheiro(ofstream& file) override;

};

#endif // LIVROEDUCATIVO_H
