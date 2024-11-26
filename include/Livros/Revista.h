#ifndef REVISTA_H
#define REVISTA_H

#include "Geral.h"


class Revista : public Geral
{
    private:
    string ISSN; //Identificador único para revistas.
    string Tema; //Moda, tecnologia, esportes, etc.

    public:
        Revista(string titulo, string autor, int ano, bool disponivel,string ISSN, string Tema);
        virtual ~Revista();
        void descricao() const override;
    protected:


};

#endif // REVISTA_H
