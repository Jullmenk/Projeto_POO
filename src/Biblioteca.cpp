#include "../include/Biblioteca.h"
#include "../include/Livros/LivroCientifico.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include <cstdlib> 

Biblioteca::~Biblioteca() {
    for (auto& categoria : livrosPorCategoria) {
        for (auto& livro : categoria.second) {
            delete livro;
        }
    }
}

void Biblioteca::adicionarLivro(const string& categoria, Geral* livro) {
    livrosPorCategoria[categoria].push_back(livro);
}

void Biblioteca::removerLivro(const string& categoria, int codigo) {
    auto it = livrosPorCategoria.find(categoria);
    if (it != livrosPorCategoria.end()) {
        auto& listaLivros = it->second;
        auto livroIt = find_if(listaLivros.begin(), listaLivros.end(),
                                    [codigo](Geral* livro) { return livro->getCodigo() == codigo; });

        if (livroIt != listaLivros.end()) {
            delete *livroIt;  // Libera a memória
            listaLivros.erase(livroIt);  // Remove da lista
        }
    }
}

// void Biblioteca::listarLivros() const {
//     if(livrosPorCategoria.empty()){
//         cout << "Lista se encontra vazia";
//     }
//     else{
//         for (const auto& categoria : livrosPorCategoria) {
//             cout << "\nCategoria: " << categoria.first << "\n";
//             for (const auto& livro : categoria.second) {
//                 livro->descricao();
//                 cout << "-------------------\n";
//             }
//         }
//     }
// }

void Biblioteca::listarLivrosDisponiveis() const {
    for (const auto& categoria : livrosPorCategoria) {
        for (const auto& livro : categoria.second) {
            if (livro->isDisponivel()) {
                livro->descricao();
                cout << "-------------------\n";
            }
        }
    }
}

Geral* Biblioteca::buscarLivro(int codigo) {
    for (auto& categoria : livrosPorCategoria) {
        for (auto& livro : categoria.second) {
            if (livro->getCodigo() == codigo) {
                return livro;
            }
        }
    }
    return nullptr;
}

void Biblioteca::RelatorioCategoria(const string& cat) const {
    auto it = livrosPorCategoria.find(cat);
    if (it != livrosPorCategoria.end()) {
        cout << "\nRelatorio da categoria: " << cat << "\n";
        for (const auto& livro : it->second) {
            livro->descricao();
        }
    } else {
        cout << "Categoria nao encontrada.\n";
    }
}

void Biblioteca::listarLivrosComPaginacao(){
     // Vetor para manter a lista total de livros (com a categoria associada)
    vector<pair<string, Geral*>> todosLivros;

    if(livrosPorCategoria.empty()){
        cout << "Lista se Encontra vazia \n saindo...\n";
        return;
    }


    for (const auto& categoria : livrosPorCategoria) {
        for (const auto& livro : categoria.second) {
            todosLivros.emplace_back(categoria.first, livro); // (Categoria, Livro)
        }
    }

    const int itensPorPagina = 5;
    int totalItens = todosLivros.size();
    int totalPaginas = (totalItens + itensPorPagina - 1) / itensPorPagina; 
    int paginaAtual = 0;

    int opcao = -1;
    while (opcao != 0) {
        system("cls"); 


        int inicio = paginaAtual * itensPorPagina;
        int fim = min(inicio + itensPorPagina, totalItens);

        cout << "Pagina " << (paginaAtual + 1) << " de " << totalPaginas << "\n";
        cout << "-----------------------------\n";

        for (int i = inicio; i < fim; ++i) {
            cout << "[" << (i + 1) << "] ";
            cout << "Categoria: " << todosLivros[i].first << " | ";
            todosLivros[i].second->descricao();
            cout << "-------------------\n";
        }

        // Opções de navegação
        cout << "-----------------------------\n";
        cout << "1 - Pagina Anterior | 2 - Proxima Pagina | 0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        // Navegação
        if (opcao == 1 && paginaAtual > 0) {
            paginaAtual--;
        } else if (opcao == 2 && paginaAtual < totalPaginas - 1) {
            paginaAtual++;
        } else if (opcao == 0) {
            cout << "Saindo...\n";
        } else {
            cout << "Opcao invalida.\n";
        }
    }
}


// bool Biblioteca::SaveToFile(string nf)
// {
//     cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
//     return true;
// }

// bool Biblioteca::LoadFile(string nf)
// {
//     cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
//     return true;
// }


// void Biblioteca::Prorrogacao_Emprestimos()
// {
//     cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
// }
// void Biblioteca::Sistema_Notificacoes_Atraso()
// {
//     cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
// }

// bool Biblioteca::Add_Leitores()
// {
//     cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
//     return true;
// }
// bool Biblioteca::Add_Leitor(Pessoa *P)
// {
//     cout << "Um dia faco este metodo <" << __FUNCTION__ << ">" << endl;
//     return true;
// }

