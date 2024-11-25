#include "../include/LivroEducativo.h"


LivroEducativo::LivroEducativo(string titulo, string autor, int ano, bool disponivel,string ISBN,int Nivel_Educacional,string Materia):Geral(titulo,autor,ano, disponivel),ISBN(ISBN),Nivel_Educacional(Nivel_Educacional)
{
    //ctor
}

LivroEducativo::~LivroEducativo()
{
    //dtor
}

void LivroEducativo::descricao() const
{
    // Chama o método descricao da classe base
    Geral::descricao();
    // Adiciona a descrição específica da subclasse
    cout << "Codigo ISBN: " << ISBN << "\n";
    cout << "Nivel Educacional: ";
    switch (Nivel_Educacional)
    {
    case 1:
        cout <<"Fundamental";
        break;
    case 2:
        cout <<"Medio";
        break;
    case 3:
        cout <<"Superior";
        break;
    }
    cout << "\nMateria " << Materia << "\n";
}