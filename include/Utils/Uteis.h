#ifndef UTEIS_H
#define UTEIS_H
#include "../Biblioteca.h"
#include <map>

class Uteis
{    
    private:
    map<string, int> limitesPorCategoria={
        {"Estudante", 5},
        {"Professor", 10},
        {"Senior", 10},
        {"LeitorComum",3}
    };

    map<string, int> descontoPorCategoria={
        {"Estudante", .2},
        {"Professor", .5},
        {"Senior", .5},
        {"LeitorComum",.0}
    };

    public:
        Uteis();
        virtual ~Uteis();
        void CriarLivroUser(Biblioteca& bib);
        void LivroInfo(int opcao,string categoria,Biblioteca& biblioteca);
        void CriarUser(Biblioteca& bib);
        void UserInfo(int opcao,string categoria,Biblioteca& biblioteca);
        void EmprestimoFuncaoPrincipal(Biblioteca& bib);
        void ListarPorCategoriaLivro(Biblioteca& bib,bool search);
        void ListarPorCategoriaUtilizador(Biblioteca& bib,bool search);
        void ConsultarHistoricoUtilizador(Biblioteca& bib);
        void RelatorioTipoDeLivro(Biblioteca& bib);
        void ConsultarHistoricoDeReservas(Biblioteca& bib);
        void DevolverLivro(Biblioteca& bib);
};

struct retorno {
    int type;
    string categoria;
};


// Função para retornar o tipo e a categoria
retorno RetornarType_String();
retorno RetornarType_String_User();

#endif // UTEIS_H
