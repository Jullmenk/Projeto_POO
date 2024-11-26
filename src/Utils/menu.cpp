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

void MENU_PRINCIPAL(Biblioteca &biblioteca) {

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
                MENU_LIVROS(biblioteca);
                system("pause");
                break;

            case 2:
                cout << "Menu do Utilizador (em desenvolvimento)" << endl;
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



void MENU_LIVROS(Biblioteca &biblioteca) {
    int num;
    do {
        system("cls");

        cout << "\n\t***** Biblioteca - LIVROS *****" << endl;
        cout << "\t1. Ver Livros" << endl;
        cout << "\t2. Adicionar Livros" << endl;
        cout << "\t3. Emprestar Livro" << endl;
        cout << "\t4. Remover Livro" << endl;
        cout << "\t5. Devolver Livro" << endl;
        cout << "\t6. Relatorios de Livros por Categoria" << endl;
        cout << "\n\tEscolha uma opcao: ";

        cin >> num;

        system("cls");

        switch (num) {
            case 1:{
                biblioteca.listarLivrosComPaginacao();
                system("pause");
                break;
            }
            case 2:{
                //Funcao para teste, adiciono Livros aleatórios
                Uteis uteis;
                cout << "\n\t***** Adicionar Livros *****" << endl;
                    for (int i = 1; i <= 10; ++i) {
                        Geral* livroEducativo = new LivroEducativo("Educativo Livro " + to_string(i), "Julino Mendonca", 2002+i, true,"213123"+to_string(i), 18,"Fisica");
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
                // uteis.CriarLivroUser(biblioteca);
                // cout << "" << endl;
                break;}

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
