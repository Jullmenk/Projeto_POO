#include <iostream>
#include <cstdlib> // Para exit e system("cls")
#include <iostream>
#include <string>
using namespace std;
#include "../../include/Utils/menu.h"
#include "../../include/Biblioteca.h"
#include "../../include/Utils/Uteis.h"
#include "../../include/Livros/LivroFiccao.h"
#include "../../include/Livros/LivroCientifico.h"
#include "../../include/Livros/LivroEducativo.h"
#include "../../include/Pessoas/Estudante.h"


void MENU_PRINCIPAL(Biblioteca &biblioteca,Uteis uteis) {

    int num;
    do {
        system("cls");

        cout << "\n\t***** Biblioteca *****" << endl;
        cout << "\t1. Livros" << endl;
        cout << "\t2. Utilizador" << endl;
        cout << "\t3. Senior" << endl;
        cout << "\t0. Sair" << endl;
        cout << "\n\tEscolha uma opcao: ";

        cin >> num;

        system("cls");

        switch (num) {
            case 1:
                MENU_LIVROS(biblioteca,uteis);
                system("pause");
                break;

            case 2:
                MENU_UTILIZADOR(biblioteca,uteis);
                break;
            case 3: MENU_SENIOR(biblioteca,uteis);
                break;
            case 0:
                cout << "Saindo do programa..." << endl;
                exit(0);
                break;

            default:
                cout << "\n\tOpcao invalida!" << endl;
                break;
        }
    } while (num != 0);
}



void MENU_LIVROS(Biblioteca &biblioteca,Uteis uteis) {
    int num;
    do {
        system("cls");

        cout << "\n\t***** Biblioteca - LIVROS *****" << endl;
        cout << "\t1. Ver Livros" << endl;
        cout << "\t2. Adicionar Livros" << endl;
        cout << "\t3. Emprestar Livro" << endl;
        cout << "\t4. Remover Livro" << endl;
        cout << "\t6. Relatorio de Emprestimos por Tipo de Livro" << endl;
        cout << "\t7. Relatorio Multas Pendentes" << endl;
        cout << "\t8. Voltar" << endl;
        cout << "\n\tEscolha uma opcao: ";

        cin >> num;

        system("cls");

        switch (num) {
            case 1:{
                uteis.ListarPorCategoriaLivro(biblioteca,false);
                system("pause");
                break;
            }
            case 2:{
                 uteis.CriarLivroUser(biblioteca);
                break;}
            case 3:
                uteis.EmprestimoFuncaoPrincipal(biblioteca);
                break;
            case 6:
                uteis.RelatorioTipoDeLivro(biblioteca);
                break;
            case 7:
                biblioteca.RelatorioMultasPendentes();
                break;
            case 8:
                MENU_PRINCIPAL(biblioteca,uteis);
                break;
            case 0:
                cout << "Saindo do programa..." << endl;
                exit(0);
                break;

            default:
                cout << "\n\tOpcao invalida!" << endl;
                break;
        }
    } while (num != 0);
}




void MENU_UTILIZADOR(Biblioteca &biblioteca,Uteis uteis) {
    int num;
    do {
        system("cls");

        cout << "\n\t***** Biblioteca - Utilizador *****" << endl;
        cout << "\t1. Ver Utilizadores" << endl;
        cout << "\t2. Adicionar Utilizador" << endl;
        cout << "\t3. Ver Historico de Emprestimo do Utilizador" << endl;
        cout << "\t4. Ver Historico de Reservas do Utilizador" << endl;
        cout << "\t5. Devolver Livro" << endl;
        cout << "\t6. Relatorios de Livros por Categoria" << endl;
        cout << "\t7. Voltar" << endl;
        cout << "\n\tEscolha uma opcao: ";

        cin >> num;

        system("cls");

        switch (num) {
            case 1:{
                uteis.ListarPorCategoriaUtilizador(biblioteca,false);
                system("pause");
                break;
            }
            case 2:{
                uteis.CriarUser(biblioteca);
                system("pause");
                break;}

            case 3: uteis.ConsultarHistoricoUtilizador(biblioteca);break;
            case 4: uteis.ConsultarHistoricoDeReservas(biblioteca);break;
            case 5: uteis.DevolverLivro(biblioteca);break;
            case 7:MENU_PRINCIPAL(biblioteca,uteis);break;
            case 0:cout << "Saindo do programa..." << endl;exit(0);break;
            default:cout << "\n\tOpcao invalida!" << endl;break;
        }
    } while (num != 0);
}

void MENU_SENIOR(Biblioteca &biblioteca,Uteis uteis) {
    int num;
    do {
        system("cls");

        cout << "\n\t***** Biblioteca - Senior *****" << endl;
        cout << "\t1. Editar Livros máximos dos Leitores" << endl;
        cout << "\t2. Editar Descontos de multa dos Leitores" << endl;
        cout << "\t3. Editar Informacoes de Livro" << endl;
        cout << "\t4. Salvar Alteracoes" << endl;
        cout << "\t5. Voltar" << endl;
        cout << "\n\tEscolha uma opcao: ";

        cin >> num;

        system("cls");

        switch (num) {
            case 1:
                uteis.MudarLimiteLivros(biblioteca);
                break;
            case 2:{
                uteis.MudarDesconto(biblioteca);
                break;}
            case 4:
                { 
                bool emp = biblioteca.GravarEmprestimosPorCategoria();
                bool res = biblioteca.GravarReservasPorCategoria();
                bool conf = biblioteca.GravarLivrosPorCategoria();
                bool user = biblioteca.GravarPessoasPorCategoria();
                bool liv = uteis.gravarLimitesPorCategoria();
                bool disc = uteis.gravarDesconto();
                if(conf && user && liv && disc && emp && res){
                     cout<< "Livros, Utilizadores, Limites e Descontos de Livros Gravados com sucesso";
                     system("pause");
                 }}
                break;
            case 5:MENU_PRINCIPAL(biblioteca,uteis);break;
            case 0:cout << "Saindo do programa..." << endl;exit(0);break;
            default:cout << "\n\tOpcao invalida!" << endl;break;
        }
    } while (num != 0);
}
