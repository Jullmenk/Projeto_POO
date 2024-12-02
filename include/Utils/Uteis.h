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
        void CriarUser(Biblioteca& bib);
        void UserInfo(int opcao,string categoria,Biblioteca& biblioteca);
        void EmprestimoFuncaoPrincipal(Biblioteca& bib);
        void ConsultarHistorico(Biblioteca& bib);
        Geral* ProcurarLivro(string id,Biblioteca& bib);
        Pessoa* ProcurarUtilizador(string id,Biblioteca& bib);

    private:
};

struct retorno {
    int type;
    string categoria;
};

// Função para retornar o tipo e a categoria
retorno RetornarType_String();
retorno RetornarType_String_User();

#endif // UTEIS_H
