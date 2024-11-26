#ifndef UTEIS_H
#define UTEIS_H
#include "../Biblioteca.h"


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

struct retorno {
    int type;
    string categoria;
};

// Função para retornar o tipo e a categoria
retorno RetornarType_String();

#endif // UTEIS_H
