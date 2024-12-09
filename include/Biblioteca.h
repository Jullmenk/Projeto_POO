#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include <list>
#include <map>
#include <fstream>
#include "Pessoas/Pessoa.h"
#include "Livros/Geral.h"
#include "Utils/Emprestimos.h"
using namespace std;
#include <cstdlib>

class Biblioteca {
private:
    // Armazena os livros organizados por categoria
    map<string, list<Geral*>> livrosPorCategoria;
    map<string, list<Emprestimo>> emprestimosPorCategoria;
    map<string, list<Emprestimo>> reservasPorCategoria;
    map<string, list<Pessoa*>> leitores;

public:
    Biblioteca() = default;
    virtual ~Biblioteca();
    //File
    bool GravarLivrosPorCategoria();
    bool GravarEmprestimosPorCategoria();
    bool GravarReservasPorCategoria();
    bool GravarPessoasPorCategoria();

    bool LerLivrosPorCategoria();

    //Livro
    map<string, list<Geral*>>& getLivrosPorCategoria();
    map<string, list<Pessoa*>>& getleitores();
    map<string, list<Emprestimo>>& getEmprestimosPorCategoria();

    void listarLivrosDisponiveis() const;
    void adicionarLivro(const string& categoria, Geral* livro);
    Geral* buscarLivro(string codigo);
    void removerLivro(const string& categoria, string codigo);
    bool listarLivrosComPaginacao(bool forSearch,string categoria);
    Geral* ProcurarLivro(string id);

    //Leitor
    void adicionarLeitor(string categoria,Pessoa* leitor);
    bool listarLeitores(bool forSearch,string categoria);
    Pessoa* buscarLeitor(string NIF) const;
    Pessoa* ProcurarUtilizador(string id);

    //Emprestimo
    void registrarEmprestimo(Pessoa* leitor, Geral* livro);
    void RelatorioEmprestimosTipoDeLivro(string cat);
    void RelatorioMultasPendentes();
    void Prorrogacao_Emprestimos();
    void Sistema_Notificacoes_Atraso();
    void registrarReserva(Pessoa* leitor, Geral* livro);
    void transformarReservaEmEmprestimo(string cat,string idLivro); 



};

#endif // BIBLIOTECA_H
