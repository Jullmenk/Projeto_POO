#ifndef REVISTA_H
#define REVISTA_H

#include "Geral.h"


class Revista : public Geral
{
    private:
    string issn; //Identificador único para revistas.
    string Tema; //Moda, tecnologia, esportes, etc.

    public:
        Revista(string categoria,string titulo, string autor, int ano, bool disponivel,string issn, string Tema);
        virtual ~Revista();
        void descricao() const override;
        string getCodigo() const override;
        bool escreverFicheiro(ofstream& file) override;
};

#endif // REVISTA_H
