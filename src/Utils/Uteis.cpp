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
    cout << "\tSelecione uma categoria de Livro"<< endl;
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
            cout << "\t Digite o genero: " <<endl;
            cin.ignore(); // Limpa o buffer
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

void Uteis::ListarPorCategoriaLivro(Biblioteca& bib,bool search){
        retorno Retornado = RetornarType_String();
        bib.listarLivrosComPaginacao(search,Retornado.categoria);  
}

void Uteis::ListarPorCategoriaUtilizador(Biblioteca& bib,bool search){
        retorno Retornado = RetornarType_String_User();
        bib.listarLeitores(search,Retornado.categoria);  
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
    cout << "\tSelecione uma categoria de utilizador"<< endl;
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
        case 1: { // Estudante
            Pessoa* estudante = new Estudante(nome,NIF,0,0,0,0,0,categoria,limitesPorCategoria[categoria],descontoPorCategoria[categoria]);
            biblioteca.adicionarLeitor(categoria, estudante);
            break;
        }
        case 2: { // Comum
            Pessoa* leitorComum = new LeitorComum(nome,NIF,0,0,0,0,0,categoria,limitesPorCategoria[categoria],descontoPorCategoria[categoria]);
            biblioteca.adicionarLeitor(categoria, leitorComum);
            break;
        }
        case 3: { // Professor
            Pessoa* professor = new Professor(nome,NIF,0,0,0,0,0,categoria,limitesPorCategoria[categoria],descontoPorCategoria[categoria]);
            biblioteca.adicionarLeitor(categoria, professor);
            break;
        }
        case 4: { // Senior
            Pessoa* senior = new Senior(nome,NIF,0,0,0,0,0,categoria,limitesPorCategoria[categoria],descontoPorCategoria[categoria]);
            biblioteca.adicionarLeitor(categoria, senior);
            break;
        }
        default:
            cout << "Opção inválida.\n";
            return;
    }

    cout << "Utilizador adicionado com sucesso!\n";
}

void Uteis::CriarUser(Biblioteca& bib){
        retorno Retornado = RetornarType_String_User();
        Uteis::UserInfo(Retornado.type,Retornado.categoria,bib);        
}

 void Uteis::EmprestimoFuncaoPrincipal(Biblioteca& bib){
    string id_Pessoa;
    string id_Livro;

    retorno user = RetornarType_String_User();
    if(!bib.listarLeitores(true,user.categoria))return;
    cout << "\t Digite o NIF do utilizador\n";
    cin>> id_Pessoa;
    Pessoa *pessoa = bib.ProcurarUtilizador(id_Pessoa);
    if(!pessoa)return;

    retorno escolha =  RetornarType_String();
    if(!bib.listarLivrosComPaginacao(true,escolha.categoria))return;
    cout << "\t Digite o ISBN/ISSN do Livro que deseja \n";
    cin>> id_Livro;
    Geral* livro = bib.ProcurarLivro(id_Livro);
    if(!livro)return;
    bib.registrarEmprestimo(pessoa,livro);
 }
 
 void Uteis::ConsultarHistoricoUtilizador(Biblioteca& bib){
    string id_Pessoa;
    string id_Livro;

    retorno user = RetornarType_String_User();
    if(!bib.listarLeitores(true,user.categoria))return;
    cout << "\t Digite o NIF do utilizador que procuras\n";
    cin>> id_Pessoa;
    Pessoa *pessoa = bib.ProcurarUtilizador(id_Pessoa);
    if(!pessoa)return;
    pessoa->listarEmprestimos();
    system("pause");
 }

void Uteis::ConsultarHistoricoDeReservas(Biblioteca& bib){
    string id_Pessoa;
    string id_Livro;

    retorno user = RetornarType_String_User();
    if(!bib.listarLeitores(true,user.categoria))return;
    cout << "\t Digite o NIF do utilizador que procuras\n";
    cin>> id_Pessoa;
    Pessoa *pessoa = bib.ProcurarUtilizador(id_Pessoa);
    if(!pessoa)return;
    pessoa->listarReservas();
    system("pause");
 }

 void Uteis::RelatorioTipoDeLivro(Biblioteca& bib){
    retorno escolha = RetornarType_String();
    bib.RelatorioEmprestimosTipoDeLivro(escolha.categoria);
    system("pause");
}


void Uteis::DevolverLivro(Biblioteca& bib){
    string id_Pessoa,id_Livro;
    bool findUser,findLivro;
    Pessoa *pessoa=nullptr;
    Geral *livro=nullptr;
    retorno user = RetornarType_String_User();
    while (!findUser)
    {
        if(!bib.listarLeitores(true,user.categoria))return;
        cout << "\t Digite o NIF do utilizador\n";
        cin>> id_Pessoa;
        pessoa = bib.ProcurarUtilizador(id_Pessoa);
        if(pessoa)findUser=true;
    }

    pessoa->listarEmprestimos();
    if(pessoa->getNumeroDeEmprestimosTotais()<=0)return;
    while (!findLivro)
    {
        cout<< "\tDigite o ISBN/ISSN do Livro Deseja Devolver:";
        cin >> id_Livro;
        livro = bib.ProcurarLivro(id_Livro);
        if(!livro)findLivro=true;

    }    
    
    auto& empresLista = bib.getEmprestimosPorCategoria();
    auto it = empresLista.find(livro->getCategoria());
    if (it == empresLista.end()) {
        cout << "Nenhum livro dessa categoria foi requisitado.\n";
        return;
    }

    // Iteração de trás para frente com iteradores reversos
    for (auto rit = it->second.rbegin(); rit != it->second.rend(); ++rit) {
        auto& emprestimo = *rit;
        if ((emprestimo.getNif() == pessoa->getNIF()) && (emprestimo.getIDLivro() == livro->getCodigo())) {
            livro->setDisponivel();
            pessoa->decrementarEmprestimosAtivos();
            time_t dataAtual = time(nullptr);
            if(emprestimo.getDataDevolucao() < dataAtual){
                pessoa->incrementarMulta();
                cout<<"O prazo de devolução já expirou, foi acrescentado uma multa de"<<5*(1 - pessoa->getDescontoMulta())<<"EUR.\n";
                system("pause");
            }
            cout << "Livro devolvido com sucesso.\n";
            bib.transformarReservaEmEmprestimo(emprestimo.getCategoriaLivro(),emprestimo.getIDLivro());
            system("pause");
            return; 
        }
    }

}

void alterarLimitesLivro(map<string, int>& limites) {
    string categoria;
    int novoLimite;

    cout << "Categorias disponíveis: " << endl;
    for (const auto& par : limites) {
        cout << par.first << " (atual: " << par.second << " livros)" << endl;
    }

    cout << "Digite o nome da categoria que deseja alterar: ";
    cin >> categoria;

    // Verificar se a categoria existe no map
    if (limites.find(categoria) != limites.end()) {
        cout << "Digite o novo limite para a categoria '" << categoria << "': ";
        cin >> novoLimite;

        // Atualizar o limite
        limites[categoria] = novoLimite;
        cout << "O limite da categoria '" << categoria << "' foi atualizado para " << novoLimite << " livros." << endl;
    } else {
        cout << "Categoria '" << categoria << "' não encontrada!" << endl;
    }
}