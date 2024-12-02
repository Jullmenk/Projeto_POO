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

map<string, list<Geral*>>& Biblioteca::getLivrosPorCategoria() {
     return livrosPorCategoria; 
    }
map<string, list<Pessoa*>>& Biblioteca::getleitores() {
    return leitores;
}

void Biblioteca::adicionarLivro(const string& categoria, Geral* livro) {
    livrosPorCategoria[categoria].push_back(livro);
}

void Biblioteca::removerLivro(const string& categoria, string codigo) {
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

Geral* Biblioteca::buscarLivro(string codigo) {
    for (auto& categoria : livrosPorCategoria) {
        for (auto& livro : categoria.second) {
            if (livro->getCodigo() == codigo) {
                return livro;
            }
        }
    }
    return nullptr;
}


bool Biblioteca::listarLivrosComPaginacao(bool forSearch,string categoria){

    auto it = livrosPorCategoria.find(categoria);
    if (it == livrosPorCategoria.end() || it->second.empty()) {
        cout << "Nao ha livros na categoria *"<<categoria<<"*\n";
        system("pause");
        return false;
    }

    vector<Geral*> todosLivros(it->second.begin(), it->second.end());

    const int itensPorPagina = 5;
    int totalItens = todosLivros.size();
    int totalPaginas = (totalItens + itensPorPagina - 1) / itensPorPagina; 
    int paginaAtual = 0;

    int opcao = -1;
    while (opcao != 0) {
        system("cls"); 


        int inicio = paginaAtual * itensPorPagina;
        int fim = min(inicio + itensPorPagina, totalItens);
        forSearch&&cout<<"**********Guarde o IDENTIFICADOR do que deseja para depois poder requisitar\n";
        cout << "Pagina " << (paginaAtual + 1) << " de " << totalPaginas << "\n";

        for (int i = inicio; i < fim; ++i) {
            cout << "[" << (i + 1) << "] ";
            todosLivros[i]->descricao();
        }

        // Opções de navegação
        cout << "1 - Pagina Anterior | 2 - Proxima Pagina | 0 - " <<(!forSearch?"Sair\n":"Escolher o meu livro");
        cout << "\nEscolha: ";
        cin >> opcao;

        // Navegação
        if (opcao == 1 && paginaAtual > 0) {
            paginaAtual--;
        } else if (opcao == 2 && paginaAtual < totalPaginas - 1) {
            paginaAtual++;
        } else if (opcao == 0) {
            cout << "Saindo...\n";
            return true;
        } else {
            cout << "Opcao invalida.\n";
        }
    }
}

void Biblioteca::registrarReserva(Pessoa* leitor, Geral* livro) {
    // Adicionar o livro à lista de reservas da categoria
    int opc;
    cout << "O Livro neste momento encontra-se indisponivel, deseja reserva-lo? \n";
    cout << "1 - Reservar | 0 - Sair\n";
    cout << "Escolha :";
    cin>> opc;

    if(opc==1){
    Emprestimo reserva(leitor->getNIF(), leitor->getNome(), livro->getCategoria(), livro->getTitulo(), time(0), time(0), false);
    reservasPorCategoria[livro->getCategoria()].push_back(reserva); 
    leitor->adicionarReserva(reserva);
    cout << "Livro reservado com sucesso!\n";
    }else{
        cout<<"Livro nao reservado, saindo...\n";
    }
    system("pause");
}

  void Biblioteca::registrarEmprestimo(Pessoa* leitor,Geral *livro, time_t dataEmprestimo) {
    // Verificar se o livro está disponível ou se há reservas
    bool temp;

    if (!livro->isDisponivel()) {
        if(!leitor->PodeReservar()){
            cout <<"Esse leitor Ja atingiu o numero maximo de reservas permitido\n";
            system("pause");
        } else{
        registrarReserva(leitor, livro);
        }
        return;
    }

    if(!leitor->PodeEmprestar()){
        cout<<"Esse leitor Ja atingiu o numero maximo de Emprestimos permitido, devolva alguns livros\n";
        system("pause");
        return;
    }

    // Calcular a data de devolução de acordo com o tipo de leitor e tipo de livro
    int prazo = leitor->getPrazoDevolucao(livro->getCategoria());
    time_t dataDevolucao = dataEmprestimo + (prazo * 24 * 60 * 60);
    /*
     converte o número de dias (prazo) para segundos:
        1 dia = 24 horas
        1 hora = 60 minutos
        1 minuto = 60 segundos
        Logo, o total de segundos em um dia é 24 * 60 * 60 = 86.400 segundos.
    */

    Emprestimo novoEmprestimo(leitor->getNIF(), leitor->getNome(), livro->getCategoria(), livro->getTitulo(), dataEmprestimo, dataDevolucao, true);

    emprestimosPorCategoria[livro->getCategoria()].push_back(novoEmprestimo);

    leitor->adicionarEmprestimo(novoEmprestimo);
    
    livro->setInDisponivel();
    cout << "Emprestimo realizado com sucesso!\n";\
    system("pause");
}

// void Biblioteca::transformarReservaEmEmprestimo(Pessoa* leitor, Geral* livro) {
//     // Verificar se o livro está disponível
//     if (livrosPorCategoria[livro->getCategoria()].size() > 0) {
//         // Se houver reservas para o livro, transformá-las em empréstimo
//         for (auto it = reservasPorCategoria[livro->getCategoria()].begin(); it != reservasPorCategoria[livro->getCategoria()].end(); ++it) {
//             if (it->getNIF() == leitor->getNIF()) {
//                 // Criar o empréstimo baseado na reserva
//                 Emprestimo novoEmprestimo = *it;
//                 novoEmprestimo.setEmprestado(true); // Tornar a reserva um empréstimo
//                 time_t dataEmprestimo = time(0);
//                 novoEmprestimo.setDataEmprestimo(dataEmprestimo);
//                 int prazo = leitor->getPrazoDevolucao(livro->getCategoria());
//                 novoEmprestimo.setDataDevolucao(dataEmprestimo + (prazo * 24 * 60 * 60));

//                 // Adicionar o empréstimo à lista de empréstimos
//                 emprestimosPorCategoria[livro->getCategoria()].push_back(novoEmprestimo);

//                 // Remover a reserva
//                 reservasPorCategoria[livro->getCategoria()].remove(*it);

//                 // Adicionar o livro à lista de livros emprestados
//                 livrosPorCategoria[livro->getCategoria()].remove(livro);

//                 cout << "Reserva transformada em empréstimo com sucesso!\n";
//                 return;
//             }
//         }
//     } else {
//         cout << "O livro não está disponível no momento.\n";
//     }
// }

    // Listar todos os empréstimos de uma categoria
    // void listarEmprestimosPorCategoria(const string& categoria) const {
    //     auto it = emprestimosPorCategoria.find(categoria);
    //     if (it != emprestimosPorCategoria.end()) {
    //         cout << "Empréstimos na categoria: " << categoria << "\n";
    //         for (const auto& emprestimo : it->second) {
    //             emprestimo.mostrarDetalhes();
    //             cout << "----------------------\n";
    //         }
    //     } else {
    //         cout << "Nenhum empréstimo registrado na categoria " << categoria << ".\n";
    //     }
    // }


void Biblioteca::adicionarLeitor(string categoria, Pessoa* leitor) {
    leitores[categoria].push_back(leitor);
    cout << "Leitor " << leitor->getNome() << " adicionado a biblioteca.\n";
}

bool Biblioteca::listarLeitores(bool forSearch,string categoria){
     // Vetor para manter a lista total de livros (com a categoria associada)

    auto it = leitores.find(categoria);
    if (it == leitores.end() || it->second.empty()) {
        cout << "Nao ha Leitores na categoria *"<<categoria<<"*\n";
        system("pause");
        return false;
    }

    vector<Pessoa*> Vleitor(it->second.begin(), it->second.end());

    const int itensPorPagina = 5;
    int totalItens = Vleitor.size();
    int totalPaginas = (totalItens + itensPorPagina - 1) / itensPorPagina; 
    int paginaAtual = 0;

    int opcao = -1;
    while (opcao != 0) {
        system("cls"); 


        int inicio = paginaAtual * itensPorPagina;
        int fim = min(inicio + itensPorPagina, totalItens);
        
        forSearch&&cout<< "**********Guarde o IDENTIFICADOR do Utilizador que deseja para depois poder requisitar**********\n\n";


        cout << "Pagina " << (paginaAtual + 1) << " de " << totalPaginas << "\n";

        for (int i = inicio; i < fim; ++i) {
            cout << "[" << (i + 1) << "] ";
            Vleitor[i]->descricao();
        }

        // Opções de navegação
        cout << "1 - Pagina Anterior | 2 - Proxima Pagina | 0 - " <<(!forSearch?"Sair":"Escolher o Utilizador");
        cout << "\nEscolha: ";
        cin >> opcao;

        // Navegação
        if (opcao == 1 && paginaAtual > 0) {
            paginaAtual--;
        } else if (opcao == 2 && paginaAtual < totalPaginas - 1) {
            paginaAtual++;
        } else if (opcao == 0) {
            cout << "Saindo...\n";
            return true;
        } else {
            cout << "Opcao invalida.\n";
        }
    }
}

void Biblioteca::RelatorioMultasPendentes(){
 if (leitores.empty()) {
        cout << "Nao ha leitores cadastrados.\n";
        return;
    }

    cout << "Relatorio de Multas Pendentes\n";

    // Mapa para agrupar multas por tipo de leitor
    map<string, double> multasPorTipo;

    // Iterar por todas as categorias de leitores
    for (const auto& categoriaLeitores : leitores) {
        for (const auto& leitor : categoriaLeitores.second) {
            double multaPendente = leitor->calcularMultaTotal();
            if (multaPendente > 0) {
                // Agrupar as multas por categoria de leitor
                multasPorTipo[leitor->getCategoria()] += multaPendente;

                // Exibir detalhes individuais (opcional)
                cout << "Leitor: " << leitor->getNome()
                     << " | NIF: " << leitor->getNIF()
                     << " | Multa Pendente: " << multaPendente << " EUR\n";
            }
        }
    }

    // Exibir o resumo das multas por tipo de leitor
    cout << "\nResumo das Multas por Tipo de Leitor:\n";
    for (const auto& entry : multasPorTipo) {
        cout << "Categoria: " << entry.first << " | Total de Multas: " << entry.second << " EUR\n";
    }
}

void Biblioteca::RelatorioEmprestimosTipoDeLivro(string cat){
    auto it = emprestimosPorCategoria.find(cat);
    if (it != emprestimosPorCategoria.end()) {
        cout << "\nRelatorio da categoria: " << cat << "\n";
        cout << "Emprestimos: \n";
        for (const auto& emprestimo : it->second) {
            emprestimo.Descricao();
        }

        cout << "Tipo de Leitor que mais requisita:";
        map<string, int> contadorTiposDeLeitores;

        for (const auto& LeitoresCat : leitores) { // Iterar por categorias de leitores
            for (const auto& leitor : LeitoresCat.second) { // Iterar por leitores específicos
                // Verificar se o leitor possui empréstimos dessa categoria
                for (const auto& emprestimo : it->second) {
                    if (emprestimo.getNif() == leitor->getNIF()) {
                        // Incrementar o contador do tipo de leitor
                        contadorTiposDeLeitores[leitor->getCategoria()]++;
                    }
                }
            }
        }

        // Determinar o tipo de leitor mais frequente
        string tipoMaisFrequente;
        int maxCount = 0;

        for (const auto& entry : contadorTiposDeLeitores) { // Iterar manualmente no map
                const string& tipo = entry.first;
                int count = entry.second;

                if (count > maxCount) {
                    maxCount = count;
                    tipoMaisFrequente = tipo;
                }
            }

            cout << "Tipo de Leitor que mais requisita: " << tipoMaisFrequente
                 << " (" << maxCount << " emprestimos)\n";
        } else {
            cout << "Categoria nao encontrada.\n";
    }
}