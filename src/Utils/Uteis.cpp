#include <iostream>
#include <string>
#include <cstdlib> // Para exit e system("cls")
using namespace std;
#include "../../include/Utils/Uteis.h"
#include "../../include/Livros/Geral.h"
#include "../../include/Biblioteca.h"
#include "../../include/Livros/LivroFiccao.h"
#include "../../include/Livros/LivroCientifico.h"
#include "../../include/Livros/LivroEducativo.h"
#include "../../include/Livros/Revista.h"
#include "../../include/Livros/Jornal.h"
#include "../../include/Pessoas/Estudante.h"
#include "../../include/Pessoas/LeitorComum.h"
#include "../../include/Pessoas/Professor.h"
#include "../../include/Pessoas/Senior.h"


using namespace std;

Uteis::Uteis()
{
    //ctor
}

Uteis::~Uteis()
{
    //dtor
}

retorno RetornarType_String(){
    int type=-1;
    string categoria;
    while (type<0||type>5)
    {
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
        cout << "\n";
        return {type,categoria};
}

void Uteis::LivroInfo(int opcao,string categoria,Biblioteca& biblioteca)
{
    string titulo, autor;
    int ano;
    bool disponivel=true;

    cout << "\t Digite o titulo: " << endl;
    cin.ignore(); 
    getline(cin, titulo);

    cout << "\t Digite o autor: " << endl;
    getline(cin, autor); 
    cout << "\t Digite o ano de publicacao: ";
    cin >> ano;

    switch (opcao) {
        case 1: { // Livro de Ficção
            string genero,isbn;
            int Faixa_Etaria;
            // cout << "\t Digite o genero: " <<endl;
            // cin.ignore(); // Limpa o buffer
            getline(cin, genero);
            cout << "\t Digite o ISBN: "<<endl;
            cin.ignore(); 
            getline(cin, isbn);
            cout<<isbn <<"\n";
            cout << "\t Digite a Faixa Etaria: ";
            cin >> Faixa_Etaria;

            Geral* livroFiccao = new LivroFiccao(titulo, autor, ano, disponivel,isbn,genero,Faixa_Etaria);
            biblioteca.adicionarLivro(categoria, livroFiccao);
            break;
        }
        case 2: { // Livro Científico
            string area,isbn;
            int edicao;
            cout << "\t Digite a area cientifica: "<<endl;
            cin.ignore();
            getline(cin, area);
            cout << "\t Digite o ISBN: "<<endl;
            getline(cin, isbn);
            cout << "\t Digite a edicao: ";
            cin >> edicao;

            Geral* livroCientifico = new LivroCientifico(titulo, autor, ano, disponivel, isbn,area,edicao);
            biblioteca.adicionarLivro(categoria, livroCientifico);
            break;
        }
        case 3: { // Livro Educativo
            string materia,isbn;
            int nivelEscolaridade;
            cout << "\t Digite a materia: "<<endl;
            cin.ignore();
            getline(cin, materia);
            cout << "\t Digite o ISBN: "<<endl;
            getline(cin, isbn);
            cout << "\t Digite o nivel de escolaridade (1-Fundamental, 2-Medio, 3-Superior): ";
            cin >> nivelEscolaridade;

            Geral* livroEducativo = new LivroEducativo(titulo, autor, ano, disponivel,isbn, nivelEscolaridade,materia);
            biblioteca.adicionarLivro(categoria, livroEducativo);
            break;
        }
        case 4: { // Revista
            string tema,issn;
            cout << "\t Digite o tema: "<<endl;
            cin.ignore();
            getline(cin, tema);
            cout << "\t Digite o ISSN: "<<endl;
            getline(cin, issn);

            Geral* revista = new Revista(titulo, autor, ano, disponivel,issn,tema);
            biblioteca.adicionarLivro(categoria, revista);
            break;
        }
        case 5: { // Jornal
            string seccao,issn;
            cout << "\t Digite a Seccao de circulação: "<<endl;
            cin.ignore();
            getline(cin, seccao);
            cout << "\t Digite o ISSN: "<<endl;
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
        retorno Retornado = RetornarType_String();
        Uteis::LivroInfo(Retornado.type,Retornado.categoria,bib);        
}


retorno RetornarType_String_User(){
    int type=-1;
    string categoria;
    while (type<0||type>5)
    {
    cout << "\t1. Estudante" << endl;
    cout << "\t2. Professor" << endl;
    cout << "\t3. Senior" << endl;
    cout << "\t4. Leitor Comum" << endl;
    cout << "\t0. Sair" << endl;
    cout << "\n" << endl;    
    cout << "\tQual Utilizador deseja criar?"<< endl;
    cout << "\n\tEscolha uma opcao: ";
    
    cin>> type;
    }
    cout << "\tUtilizador Escolhido : ";
    switch (type)
        {
        case 1:
            cout<<"Estudante"<<endl;
            categoria = "Estudante";
            break;
        case 2:
            cout<<"Professor"<<endl;
            categoria = "Professor";
            break;
        case 3:
            cout<<"Senior"<<endl;
            categoria = "Senior";
            break;
        case 4:
            cout<<"Leitor Comum"<<endl;
            categoria = "Comum";
            break;
        }
        cout << "\n";
        return {type,categoria};
}



void Uteis::UserInfo(int opcao,string categoria,Biblioteca& biblioteca)
{
    string nome;
    string NIF;

    cout << "\tDigite o Nome do Utilizador: " << endl;
    cin.ignore(); 
    getline(cin, nome);

    cout << "\tDigite o NIF: " << endl;
    getline(cin, NIF); 

    switch (opcao) {
        case 1: { // Livro de Ficção
            Pessoa* estudante = new Estudante(nome,NIF,0,0,categoria);
            biblioteca.adicionarLeitor(categoria, estudante);
            break;
        }
        case 2: { // Livro Científico
            Pessoa* leitorComum = new LeitorComum(nome,NIF,0,0,categoria);
            biblioteca.adicionarLeitor(categoria, leitorComum);
            break;
        }
        case 3: { // Livro Educativo
            Pessoa* professor = new Professor(nome,NIF,0,0,categoria);
            biblioteca.adicionarLeitor(categoria, professor);
            break;
        }
        case 4: { // Revista
            Pessoa* senior = new Senior(nome,NIF,0,0,categoria);
            biblioteca.adicionarLeitor(categoria, senior);
            break;
        }
        default:
            cout << "Opção inválida.\n";
            return;
    }

    cout << "Livro adicionado com sucesso!\n";
}


void Uteis::CriarUser(Biblioteca& bib){
        retorno Retornado = RetornarType_String_User();
        Uteis::UserInfo(Retornado.type,Retornado.categoria,bib);        
}

Geral* Uteis::ProcurarLivro(string id, Biblioteca& bib){

 auto& livros = bib.getLivrosPorCategoria();
    for (auto& categoria : livros) {
        for ( auto& livro : categoria.second) {
            if (livro->getCodigo() == id) {
                cout << "Livro encontrado\n";
                return livro;
            }
        }
    }
    cout<<"Lamentamos, mas esse livro ainda nao existe nessa biblioteca";
    return nullptr;
}

Pessoa* Uteis::ProcurarUtilizador(string id, Biblioteca& bib){
int opc;
 auto& pessoa = bib.getleitores();
    for (auto& categoria : pessoa) {
        for ( auto& pessoafound : categoria.second) {
            if (pessoafound->getNIF() == id) {
                return pessoafound;
            }
        }
    }
    cout<<"Lamentamos, mas esse utilizador ainda nao foi registado nessa biblioteca\n";
    system("pause");
    return nullptr;
}


 void Uteis::EmprestimoFuncaoPrincipal(Biblioteca& bib){
    string id_Pessoa;
    string id_Livro;

    bib.listarLeitores(true);
    cout << "\t Digite o NIF do utilizador\n";
    cin>> id_Pessoa;
    Pessoa *pessoa = ProcurarUtilizador(id_Pessoa,bib);
    if(!pessoa)return;
    
    bib.listarLivrosComPaginacao(true);
    cout << "\t Digite o ISBN/ISSN do Livro que deseja \n";
    cin>> id_Livro;
    Geral* livro = ProcurarLivro(id_Livro,bib);
    if(!livro)return;
    time_t atual = time(nullptr);
    bib.registrarEmprestimo(pessoa,livro,atual);
 }

 
 void Uteis::ConsultarHistorico(Biblioteca& bib){
    string id_Pessoa;
    string id_Livro;

    bib.listarLeitores(true);
    cout << "\t Digite o NIF do utilizador que deseja requisitar um livro\n";
    cin>> id_Pessoa;
    Pessoa *pessoa = ProcurarUtilizador(id_Pessoa,bib);
    if(!pessoa)return;
    pessoa->listarEmprestimosAtivos();
    system("pause");
 }