#include "../include/Uteis.h"
#include "../include/Geral.h"
#include "../include/Biblioteca.h"
#include "../include/LivroFiccao.h"
#include <iostream>
#include <string>
#include "../include/LivroCientifico.h"
#include "../include/LivroEducativo.h"
#include "../include/Revista.h"
#include "../include/Jornal.h"
#include <cstdlib> // Para exit e system("cls")
using namespace std;


using namespace std;

Uteis::Uteis()
{
    //ctor
}

Uteis::~Uteis()
{
    //dtor
}

void Uteis::LivroInfo(int opcao,string categoria,Biblioteca& biblioteca)
{
    string titulo, autor;
    int ano;
    bool disponivel=true;

    cout << "Digite o titulo: " << endl;
    cin.ignore(); 
    getline(cin, titulo);

    cout << "Digite o autor: " << endl;
    getline(cin, autor); 
    cout << "Digite o ano de publicacao: ";
    cin >> ano;

    // Entrada de dados específicos com base na opção
    switch (opcao) {
        case 1: { // Livro de Ficção
            string genero,isbn;
            int Faixa_Etaria;
            cout << "Digite o genero: " <<endl;
            cin.ignore(); // Limpa o buffer
            getline(cin, genero);
            cout << "Digite o ISBN: "<<endl;
            getline(cin, isbn);
            cout << "Digite a Faixa Etaria: ";
            cin >> Faixa_Etaria;

            Geral* livroFiccao = new LivroFiccao(titulo, autor, ano, disponivel,isbn,genero,Faixa_Etaria);
            biblioteca.adicionarLivro(categoria, livroFiccao);
            break;
        }
        case 2: { // Livro Científico
            string area,isbn;
            int edicao;
            cout << "Digite a area cientifica: "<<endl;
            cin.ignore();
            getline(cin, area);
            cout << "Digite o ISBN: "<<endl;
            getline(cin, isbn);
            cout << "Digite a edicao: ";
            cin >> edicao;

            Geral* livroCientifico = new LivroCientifico(titulo, autor, ano, disponivel, isbn,area,edicao);
            biblioteca.adicionarLivro(categoria, livroCientifico);
            break;
        }
        case 3: { // Livro Educativo
            string materia,isbn;
            int nivelEscolaridade;
            cout << "Digite a materia: "<<endl;
            cin.ignore();
            getline(cin, materia);
            cout << "Digite o ISBN: "<<endl;
            getline(cin, isbn);
            cout << "Digite o nivel de escolaridade (1-Fundamental, 2-Medio, 3-Superior): ";
            cin >> nivelEscolaridade;

            Geral* livroEducativo = new LivroEducativo(titulo, autor, ano, disponivel,isbn, nivelEscolaridade,materia);
            biblioteca.adicionarLivro(categoria, livroEducativo);
            break;
        }
        case 4: { // Revista
            string tema,issn;
            cout << "Digite o tema: "<<endl;
            cin.ignore();
            getline(cin, tema);
            cout << "Digite o ISSN: "<<endl;
            getline(cin, issn);

            Geral* revista = new Revista(titulo, autor, ano, disponivel,issn,tema);
            biblioteca.adicionarLivro(categoria, revista);
            break;
        }
        case 5: { // Jornal
            string seccao,issn;
            cout << "Digite a Seccao de circulação: "<<endl;
            cin.ignore();
            getline(cin, seccao);
            cout << "Digite o ISSN: "<<endl;
            getline(cin, issn);

            Geral* jornal = new Jornal(titulo, autor, ano, disponivel,issn,seccao);
            biblioteca.adicionarLivro(categoria, jornal);
            break;
        }
        default:
            cout << "Opção inválida.\n";
            return;
    }

    cout << "Livro adicionado com sucesso!\n";
}

void Uteis::CriarLivroUser(Biblioteca& bib){
    int type;
    string categoria;
    while (type<0||type>5)
    {
    cout << "\n\t***** Biblioteca *****" << endl;
    cout << "\t1. Livro de Ficcao" << endl;
    cout << "\t2. Livro Cientifico" << endl;
    cout << "\t3. Livro Educativo" << endl;
    cout << "\t4. Revista" << endl;
    cout << "\t5. Jornal" << endl;
    cout << "\t0. Sair" << endl;
    cout << "\n" << endl;    
    cout << "\tQue deseja Adicionar?"<< endl;
    cout << "\n\tEscolha uma opcao: ";
    
    cin>> type;
    }
    cout << "\tLivro Escolhido : ";
    switch (type)
        {
        case 1:
            cout<<"Livro de Ficcao"<<endl;
            categoria = "Ficcao";
            break;
        case 2:
            cout<<"Livro Cientifico"<<endl;
            categoria = "Cientifico";
            break;
        case 3:
            cout<<"Livro Educativo"<<endl;
            categoria = "Educativo";
            break;
        case 4:
            cout<<"Revista"<<endl;
            categoria = "Revista";
            break;
        case 5:
            cout<<"Livro Jornal"<<endl;
            categoria = "Jornal";
            break;
        }
        system("pause");

        Uteis::LivroInfo(type,categoria,bib);        

}
