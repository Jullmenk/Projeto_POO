#include "../include/Geral.h"

Geral::Geral(string titulo,  string autor, int ano, bool disponivel): titulo(titulo), autor(autor), ano(ano), disponivel(disponivel) {}


 void Geral::descricao() const
{
    cout << "Titulo: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "Ano: " << ano << endl;
    cout << "Disponibilidade: " << (disponivel ? "Disponivel" : "Indisponivel") << endl;
}