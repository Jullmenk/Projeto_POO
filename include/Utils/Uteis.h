#ifndef UTEIS_H
#define UTEIS_H
#include "../Biblioteca.h"
#include <map>
#include <limits>
#include <sstream>

class Uteis
{    
    private:
    map<string, int> limitesPorCategoria;
    map<string, double> descontoPorCategoria;

    public:
        Uteis();
        virtual ~Uteis();
        void CriarLivroUser(Biblioteca& bib);
        void LivroInfo(int opcao,string categoria,Biblioteca& biblioteca);
        bool LerLivrosPorCategoria(Biblioteca& bib);
        bool LerPessoasPorCategoria(Biblioteca& bib);
        bool LerEmprestimos(Biblioteca& biblioteca);
        void MudarLimiteLivros(Biblioteca& bib);
        void addLimiteLivros(string categoria, int limite);
        bool LerLimitesPorCategoria();
        bool gravarLimitesPorCategoria();
        
        void MudarDesconto(Biblioteca& bib);
        void addDesconto(string categoria, double desconto);
        bool LerDesconto();
        bool gravarDesconto();

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
