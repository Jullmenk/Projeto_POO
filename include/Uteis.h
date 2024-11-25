#ifndef UTEIS_H
#define UTEIS_H
#include "Biblioteca.h"


class Uteis
{
    protected:
    
    public:
        Uteis();
        virtual ~Uteis();

        void CriarLivroUser(Biblioteca& bib);
        void LivroInfo(int opcao,string categoria,Biblioteca& biblioteca);


    private:
};

#endif // UTEIS_H
