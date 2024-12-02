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
                //Funcao para teste, adiciono Livros aleatórios
                cout << "\n\t***** Adicionar Livros *****" << endl;
                 for (int i = 1; i <= 10; ++i) {
                     Geral* livroEducativo = new LivroEducativo("Educativo Livro " + to_string(i), "Julino Mendonca", 2002+i, false,"213123"+to_string(i), 18,"Fisica");
                     biblioteca.adicionarLivro("Educativo", livroEducativo);
                 }
                 for (int i = 1; i <= 10; ++i) {
                     Geral* livroCientifico = new LivroCientifico("Cientifico Livro " + to_string(i), "Jose Arrais", 1002+i, true,"3123"+to_string(i),"Matematica", 18);
                     biblioteca.adicionarLivro("Cientifico", livroCientifico);                    }
                 for (int i = 1; i <= 10; ++i) {
                     Geral* livroFiccao = new LivroFiccao("Ficcao Livro " + to_string(i), "Rodrigo Caxinde ", 4002+i, true,"73913"+to_string(i),"Romance",18);
                     biblioteca.adicionarLivro("Ficcao", livroFiccao);
                 }
                 cout<<"Livros Adicionados com sucesso\n";
                 system("pause");
                 //uteis.CriarLivroUser(biblioteca);
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
                //Funcao para teste, adiciono Livros aleatórios
                cout << "\n\t***** Criar Utilizador *****" << endl;
                     for (int i = 1; i <= 10; ++i) {
                         Pessoa* estudante = new Estudante("Julino" + to_string(i),"2182"+ to_string(i),0,0,"Estudante");
                         biblioteca.adicionarLeitor("Estudante", estudante);
                     }
                     cout<<"Utilizadores Adicionados com sucesso\n";
                     system("pause");

                    //uteis.CriarUser(biblioteca);
                break;}

            case 3: uteis.ConsultarHistorico(biblioteca);break;
            case 4: uteis.ConsultarHistoricoDeReservas(biblioteca);break;
            case 7:MENU_PRINCIPAL(biblioteca,uteis);break;
            case 0:cout << "Saindo do programa..." << endl;exit(0);break;
            default:cout << "\n\tOpcao invalida!" << endl;break;
        }
    } while (num != 0);
}
