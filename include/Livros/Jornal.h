#ifndef JORNAL_H
#define JORNAL_H

#include "Geral.h"


class Jornal : public Geral
{
    private:
    string ISSN; // Identificar unico para Jornal
    string Seccao; //Política, esportes, economia, cultura, etc.
    
    public:
        Jornal(string titulo, string autor, int ano, bool disponivel,string ISSN, string Seccao);
        virtual ~Jornal();
        void descricao() const override;
        string getCodigo() const override;
    protected:
 

};

#endif // Jornal_H
