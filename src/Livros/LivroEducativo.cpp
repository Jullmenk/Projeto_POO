#include "../../include/Livros/LivroEducativo.h"


LivroEducativo::LivroEducativo(string categoria,string titulo, string autor, int ano, bool disponivel,string isbn,int Nivel_Educacional,string Materia):Geral(categoria,titulo,autor,ano, disponivel),isbn(isbn),Nivel_Educacional(Nivel_Educacional),Materia(Materia)
{
    //ctor
}

LivroEducativo::~LivroEducativo()
{
           cout << categoria << "destruído com sucesso.\n";
}

void LivroEducativo::descricao() const {
    Geral::descricao();
    cout << " | ISBN: " << isbn
         << " | Nível Educacional: ";
    switch (Nivel_Educacional) {
        case 1: cout << "Fundamental"; break;
        case 2: cout << "Médio"; break;
        case 3: cout << "Superior"; break;
    }
    cout << " | Matéria: " << Materia << endl;
}

string LivroEducativo::getCodigo() const {
    return isbn;
}

bool LivroEducativo::escreverFicheiro(ofstream& file) {
    Geral::escreverFicheiro(file);
    file
    << Nivel_Educacional << " ; "
    << isbn << " ; "
    << Materia << " \n";
    return true;
}


void LivroEducativo::AlterarInformacaoDoLivro(){
    int type=0;
    int nivelEscolaridade=0;

    while(type<1 || type>2){
    system("cls");
    cout << "\nNos Livros Educativos Só é possivel alterar o Nível de Escolaridade e a Matéria\n";
    cout << "\t1. Nível de Escolaridade" << endl;
    cout << "\t2. Matéria" << endl;
    cout << "Selecione o Número do que deseja alterar : ";
    cin>> type;
    }

    switch (type)
    {
    case 1:
        while(nivelEscolaridade<1 || nivelEscolaridade>3){
        cout << "\n Digite o novo  Nível de Escolariadade (1-Fundamental, 2-Medio, 3-Superior) : ";
        cin >> nivelEscolaridade;
        }
        Nivel_Educacional = nivelEscolaridade;
        break;
    case 2:
        cout << "\n Digite a nova Matéria : ";
        cin.ignore(); 
        getline(cin, Materia);
        break;
    }
}