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
    cout << "\n\tEscolha uma opção: ";
    
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

    cout << "\t Digite o titulo: " ;;
    cin.ignore(); 
    getline(cin, titulo);

    cout << "\t Digite o autor: " ;;
    getline(cin, autor); 

    cout << "\t Digite o ano de publicacao: ";
    cin >> ano;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Geral* livro= nullptr;

    switch (opcao) {
        case 1: { // Livro de Ficção
            string genero,isbn;
            int Faixa_Etaria;
            
            cout << "\t Digite o genero: " ;
            getline(cin, genero);

            cout << "\t Digite o ISBN: ";
            getline(cin, isbn);

            cout << "\t Digite a Faixa Etaria: ";
            cin >> Faixa_Etaria;
            
            livro = new LivroFiccao(categoria,titulo, autor, ano, disponivel,isbn,genero,Faixa_Etaria);
            biblioteca.adicionarLivro(categoria, livro);
            break;
        }
        case 2: { // Livro Científico
            string area,isbn,edicao;

            cout << "\t Digite a area cientifica: ";
            getline(cin, area);
            
            cout << "\t Digite o ISBN: ";
            getline(cin, isbn);

            cout << "\t Digite a edicao: ";
            getline(cin, edicao);

            livro = new LivroCientifico(categoria,titulo, autor, ano, disponivel,isbn,area,edicao);
            biblioteca.adicionarLivro(categoria, livro);
            break;
        }
        case 3: { // Livro Educativo
            string materia,isbn;
            int nivelEscolaridade;

            cout << "\t Digite a materia: ";
            getline(cin, materia);

            cout << "\t Digite o ISBN: ";
            getline(cin, isbn);
            cout << "\t Digite o nivel de escolaridade (1-Fundamental, 2-Medio, 3-Superior): ";
            cin >> nivelEscolaridade;

            livro = new LivroEducativo(categoria,titulo, autor, ano, disponivel,isbn, nivelEscolaridade,materia);
            biblioteca.adicionarLivro(categoria, livro);
            break;
        }
        case 4: { // Revista
            string tema,issn;
            cout << "\t Digite o tema: ";
            getline(cin, tema);

            cout << "\t Digite o ISSN: ";
            getline(cin, issn);

            livro = new Revista(categoria,titulo, autor, ano, disponivel,issn,tema);
            biblioteca.adicionarLivro(categoria, livro);
            break;
        }
        case 5: { // Jornal
            string seccao,issn;
            cout << "\t Digite a Seccao de circulação: ";
            getline(cin, seccao);

            cout << "\t Digite o ISSN: ";
            getline(cin, issn);

            livro = new Jornal(categoria,titulo, autor, ano, disponivel,issn,seccao);
            biblioteca.adicionarLivro(categoria, livro);
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
    cout << "\tSelecione uma categoria do utilizador"<< endl;
    cout << "\n\tEscolha uma opção: ";
    
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

    cout << "\tDigite o Nome do Utilizador: " ;
    cin.ignore(); 
    getline(cin, nome);

    cout << "\tDigite o NIF: ";
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
    cout << "\t Digite o NIF do utilizador : ";
    cin>> id_Pessoa;
    Pessoa *pessoa = bib.ProcurarUtilizador(id_Pessoa);
    if(!pessoa)return;

    retorno escolha =  RetornarType_String();
    if(!bib.listarLivrosComPaginacao(true,escolha.categoria))return;
    cout << "\t Digite o ISBN/ISSN do Livro que deseja : ";
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
    cout << "\t Digite o NIF do utilizador que procuras : ";
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
    cout << "\t Digite o NIF do utilizador que procuras : ";
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
    bool findUser=false,findLivro=false;
    Pessoa *pessoa=nullptr;
    Geral *livro=nullptr;
    retorno user = RetornarType_String_User();
    while (!findUser)
    {
        if(!bib.listarLeitores(true,user.categoria))return;
        cout << "\t Digite o NIF do utilizador : ";
        cin>> id_Pessoa;
        pessoa = bib.ProcurarUtilizador(id_Pessoa);
        if(pessoa)findUser=true;
    }

    pessoa->listarEmprestimos();

    if(pessoa->getNumeroDeEmprestimosTotais()<=0)return;

    while (!findLivro)
    {
        cout<< "\tDigite o ISBN/ISSN do Livro Deseja Devolver : ";
        cin >> id_Livro;
        livro = bib.ProcurarLivro(id_Livro);
        if(livro)findLivro=true;

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
        if ((emprestimo.getNifEmprestimo() == pessoa->getNIF()) && (emprestimo.getIDLivroEmprestimo() == livro->getCodigo())) {
            livro->setDisponivel();
            pessoa->decrementarEmprestimosAtivos();
            time_t dataAtual = time(nullptr);
            if(emprestimo.getDataDevolucaoEmprestimo() < dataAtual){
                pessoa->incrementarMulta();
                cout<<"O prazo de devolução já expirou, foi acrescentado uma multa de"<<5*(1 - pessoa->getDescontoMulta())<<"EUR.\n";
                system("pause");
            }
            cout << "Livro devolvido com sucesso.\n";
            bib.transformarReservaEmEmprestimo(emprestimo.getCategoriaLivroEmprestimo(),emprestimo.getIDLivroEmprestimo());
            system("pause");
            return; 
        }
    }

}



void ajustarCaracteres(string& str) {
    str.erase(0, str.find_first_not_of(' ')); // Remover espaços do início
    str.erase(str.find_last_not_of(' ') + 1); // Remover espaços do final
}

bool Uteis::LerLivrosPorCategoria(Biblioteca& biblioteca) {
    ifstream file("./data/livros.txt");
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: livros.txt" << endl;
        system("pause");
        return false;
    }

    string linha;
    while (getline(file, linha)) {
        stringstream ss(linha);
        string categoria, titulo, autor, isbn, issn, genero, tema, area, materia, seccao, disponivelStr,edicao;
        int ano = 0, faixaEtaria = 0, nivelEducacional = 0;
        bool disponivel = false;

        getline(ss, categoria, ';');
        ajustarCaracteres(categoria);

        getline(ss, titulo, ';');
        ajustarCaracteres(titulo);

        getline(ss, autor, ';');
        ajustarCaracteres(autor);

        string anoStr;
        getline(ss, anoStr, ';'); 
        ano = stoi(anoStr);       

        getline(ss, disponivelStr, ';');
        ajustarCaracteres(disponivelStr);
        disponivel = (disponivelStr == "1"); 

        Geral* livro = nullptr;

        if (categoria == "Ficcao") {
            string faixaEtariaStr;
            getline(ss, faixaEtariaStr, ';');
            faixaEtaria = stoi(faixaEtariaStr);

            getline(ss, isbn, ';');
            ajustarCaracteres(isbn);

            getline(ss, genero, ';');
            ajustarCaracteres(genero);

            livro = new LivroFiccao(categoria, titulo, autor, ano, disponivel, isbn, genero, faixaEtaria);
        } else if (categoria == "Educativo") {
            string nivelEducacionalStr;
            getline(ss, nivelEducacionalStr, ';');
            nivelEducacional = stoi(nivelEducacionalStr);

            getline(ss, isbn, ';');
            ajustarCaracteres(isbn);

            getline(ss, materia, ';');
            ajustarCaracteres(materia);

            livro = new LivroEducativo(categoria, titulo, autor, ano, disponivel, isbn, nivelEducacional, materia);
        } else if (categoria == "Cientifico") {
            getline(ss, area, ';');
            ajustarCaracteres(area);

            getline(ss, isbn, ';');
            ajustarCaracteres(isbn);

            string edicaoStr;
            getline(ss, edicaoStr, ';');

            livro = new LivroCientifico(categoria, titulo, autor, ano, disponivel, isbn,area, edicaoStr);
        } else if (categoria == "Revista") {
            getline(ss, tema, ';');
            ajustarCaracteres(tema);

            getline(ss, issn, ';');
            ajustarCaracteres(issn);

            livro = new Revista(categoria, titulo, autor, ano, disponivel, issn, tema);
        } else if (categoria == "Jornal") {
            getline(ss, seccao, ';');
            ajustarCaracteres(seccao);

            getline(ss, issn, ';');
            ajustarCaracteres(issn);

            livro = new Jornal(categoria, titulo, autor, ano, disponivel, issn, seccao);
        }

        if (livro != nullptr) {
            biblioteca.adicionarLivro(categoria, livro);
        }
    }

    file.close();
    return true;
}


bool Uteis::LerPessoasPorCategoria(Biblioteca& biblioteca) {
    ifstream file("./data/Pessoas.txt");
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: Pessoas.txt" << endl;
        system("pause");
        return false;
    }

    string linha;
    while (getline(file, linha)) {
        stringstream ss(linha);
        string nome, NIF,categoria;
        int NumeroDeEmprestimosTotal,NumeroDeEmprestimosAtivos,totalMultaPorPagar,totalMultaPago,NumeroDeReservas;

        getline(ss, categoria, ';');
        ajustarCaracteres(categoria);
        
        getline(ss, nome, ';');
        ajustarCaracteres(nome);

        getline(ss, NIF, ';');
        ajustarCaracteres(NIF);

        string StrtotalMultaPorPagar;
        getline(ss, StrtotalMultaPorPagar, ';');
        totalMultaPorPagar = stoi(StrtotalMultaPorPagar);

        string StrtotalMultaPago;
        getline(ss, StrtotalMultaPago, ';');
        totalMultaPago = stoi(StrtotalMultaPago);

        string StrNumeroDeEmprestimosTotal;
        getline(ss, StrNumeroDeEmprestimosTotal, ';');
        NumeroDeEmprestimosTotal = stoi(StrNumeroDeEmprestimosTotal);

        string StrNumeroDeEmprestimosAtivos;
        getline(ss, StrNumeroDeEmprestimosAtivos, ';');
        NumeroDeEmprestimosAtivos = stoi(StrNumeroDeEmprestimosAtivos);

        string StrNumeroDeReservas;
        getline(ss, StrNumeroDeReservas, ';');
        NumeroDeReservas = stoi(StrNumeroDeReservas);

        Pessoa* leitor = nullptr;

        if (categoria == "Estudante") {
            
            leitor = new Estudante( nome,  NIF,  NumeroDeEmprestimosTotal,  NumeroDeEmprestimosAtivos,  totalMultaPorPagar,  totalMultaPago, NumeroDeReservas, categoria, limitesPorCategoria[categoria], descontoPorCategoria[categoria]);

        } else if (categoria == "LeitorComum") {

            leitor = new LeitorComum( nome,  NIF,  NumeroDeEmprestimosTotal,  NumeroDeEmprestimosAtivos,  totalMultaPorPagar,  totalMultaPago, NumeroDeReservas, categoria, limitesPorCategoria[categoria], descontoPorCategoria[categoria]);

        } else if (categoria == "Professor") {

            leitor = new Professor( nome,  NIF,  NumeroDeEmprestimosTotal,  NumeroDeEmprestimosAtivos,  totalMultaPorPagar,  totalMultaPago, NumeroDeReservas, categoria, limitesPorCategoria[categoria], descontoPorCategoria[categoria]);

        } else if (categoria == "Senior") {

            leitor = new Senior( nome,  NIF,  NumeroDeEmprestimosTotal,  NumeroDeEmprestimosAtivos,  totalMultaPorPagar,  totalMultaPago, NumeroDeReservas, categoria, limitesPorCategoria[categoria], descontoPorCategoria[categoria]);
        }

        if (leitor != nullptr) {
            biblioteca.adicionarLeitor(categoria, leitor);
        }
    }

    file.close();
    return true;
}

void Uteis::addLimiteLivros(string categoria, int limite) {
    auto it = limitesPorCategoria.find(categoria);
    if (it != limitesPorCategoria.end()) {
        it->second = limite;
        cout << "Limite da categoria '" << categoria << "' atualizado para " << limite << ".\n";

    } else {
        limitesPorCategoria[categoria] = limite;
        cout << "Nova categoria '" << categoria << "' criada com limite " << limite << ".\n";
    }
}

void Uteis::MudarLimiteLivros(Biblioteca& bib) {
    retorno Retornado = RetornarType_String_User();
    int limite=-1;
    while (limite<0)
    {
        cout << "\tDigite o novo Limite de Livros para " << Retornado.categoria <<" : ";
        cin>> limite;
    }
    
    auto it = limitesPorCategoria.find(Retornado.categoria);
    if (it != limitesPorCategoria.end()) {
            it->second = limite;
            auto& leitores = bib.getleitores();
            auto it = leitores.find(Retornado.categoria);
            if (it == leitores.end()) {
                cout << "Nao existe nenhum Leitor dessa categoria.\n";
                return;
            }else{
                for (auto& categoria : leitores) {
                for ( auto& pessoa : categoria.second) {
                        pessoa->alterarLivrosMaximos(limite);
                    }
                 }
                cout << "Limite da categoria '" << Retornado.categoria << "' atualizado para " << limite << ".\n";
                system("pause");
            }
    }
}



bool Uteis::LerLimitesPorCategoria() {
    ifstream file("./data/limitesPorCategoria.txt");
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: limitesPorCategoria.txt" << endl;
        system("pause");
        return false;
    }

    string linha;
    while (getline(file, linha)) {
        stringstream ss(linha);
        string categoria;
        int limite;

        getline(ss, categoria, ';');
        ajustarCaracteres(categoria);

        string Strlimite;
        getline(ss, Strlimite, ';');
        limite = stoi(Strlimite);

        addLimiteLivros(categoria,limite);
    }

    file.close();
    return true;
}

bool Uteis::gravarLimitesPorCategoria(){
    ofstream file("./data/limitesPorCategoria.txt");
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: limitesPorCategoria.txt" << endl;
        return false;
    }

    for (auto& limit : limitesPorCategoria) {
        file << limit.first << " ; " << limit.second << "\n";
    }

    file.close();
    return true;
};


// Desconto


void Uteis::addDesconto(string categoria, double desconto) {
    auto it = descontoPorCategoria.find(categoria);
    if (it != descontoPorCategoria.end()) {
        it->second = desconto;
        cout << "Desconto da categoria do desconto '" << categoria << "' atualizado para " << desconto << ".\n";

    } else {
        descontoPorCategoria[categoria] = desconto;
        cout << "Nova categoria do desconto '" << categoria << "' criada com desconto " << desconto << ".\n";
    }
}

void Uteis::MudarDesconto(Biblioteca& bib) {
    retorno Retornado = RetornarType_String_User();
    int desconto=-1;
    while (desconto<0)
    {
        cout << "\tDigite o novo desconto das multas para " << Retornado.categoria <<" : ";
        cin>> desconto;
    }
    desconto = desconto / 100;
    
    auto it = descontoPorCategoria.find(Retornado.categoria);
    if (it != descontoPorCategoria.end()) {
            it->second = desconto;
            auto& leitores = bib.getleitores();
            auto it = leitores.find(Retornado.categoria);
            if (it == leitores.end()) {
                cout << "Nao existe nenhum Leitor dessa categoria.\n";
                return;
            }else{
                for (auto& categoria : leitores) {
                for ( auto& pessoa : categoria.second) {
                        pessoa->alterarDescontos(desconto);
                    }
                 }
                cout << "Desconto da categoria '" << Retornado.categoria << "' atualizado para " << desconto << ".\n";
                system("pause");
            }
    }
}



bool Uteis::LerDesconto() {
    ifstream file("./data/descontoPorCategoria.txt");
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: descontoPorCategoria.txt" << endl;
        system("pause");
        return false;
    }

    string linha;
    while (getline(file, linha)) {
        stringstream ss(linha);
        string categoria;
        double desconto;

        getline(ss, categoria, ';');
        ajustarCaracteres(categoria);

        string Strdesconto;
        getline(ss, Strdesconto, ';');
        desconto = stod(Strdesconto);
        addDesconto(categoria,desconto);
    }

    file.close();
    return true;
}

bool Uteis::gravarDesconto(){
    ofstream file("./data/descontoPorCategoria.txt");
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: descontoPorCategoria.txt" << endl;
        return false;
    }

    for (auto& desconto : descontoPorCategoria) {
        file << desconto.first << " ; " << desconto.second << "\n";
    }
    file.close();
    return true;
};

