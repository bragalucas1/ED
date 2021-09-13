#include "Tetris.h"
#include <iostream>

using namespace std;

///////////////CONSTRUTOR////////////////////////
Tetris::Tetris(int c): //recebe um inteiro indicando a largura (numero de colunas) que representara o jogo
    colunas(c){
    alturas = new int[c]; //altura da coluna C no jogo; numero de linhas no array do jogo[c];
    for(int i = 0; i < c; i++){ 
        alturas[i] = 0; //inicia todas alturas como 0
    }

    jogo = new char*[c]; //array representando a tela do jogo
    for(int i = 0; i < c; i++){
        jogo[i] = NULL;
    }
}


///////////////////MÉTODOS GET///////////////////
char Tetris::get(int c, int l) const{
//recebe dois argumentos: a coluna (primeiro argumento) e a linha (segundo argumento),
//de um pixel e retorna um caractere que representa o estado de tal pixel no jogo atual.
    if(l >= alturas[c]){
        return ' '; // testa se a altura que quer acessar esta alocada, se não significa que nao tem nada
    } 
    else{
     return jogo[c][l];
    }
}

int Tetris::getNumColunas() const{
//retorna o número de colunas (largura) do jogo Tetris. 
//Esse número deverá ser igual ao valor passado pelo construtor do jogo
    return colunas;
}

int Tetris::getAltura(int c) const{ 
//retorna a altura maxima do jogo atual
    return alturas[c];
}

int Tetris::getAltura() const{
//retorna a altura da coluna c do jogo.
//A altura de uma coluna é igual a altura do pixel (não vazio) mais alto da coluna. 
//Uma coluna onde todos os pixels são vazios possui altura 0.

    int max = alturas[0]; //atribui a primeira posição como a maior altuara
    for(int i = 1; i < colunas; i++){
        if(max < alturas[i]){ //acha uma altura maior
            max = alturas[i]; //atribui a ela
        }
    }
    return max;
}
/////////////////////////////////////////////////

void Tetris::removeColuna(int c){
//dado o índice c de uma coluna (0<= c < número de colunas), remove a coluna do jogo (diminuindo, assim, sua largura).
    int *newaltura = new int[colunas-1]; //alocamos um novo vetor a fim de guardar as alturas das colunas restantes
    int cursor = 0; //cursor auxiliar
    if(c == colunas-1){//tratamos o caso de ser a ultima posição 
        for(int i = 0; i < colunas-1; i++) {
            newaltura[cursor] = alturas[i]; //copia-se todas, exceto a ultima
            cursor++;
        }
    }else{ 
    //caso não sendo a ultima posição
        for(int i = 0; i < colunas; i++) {
            if(i == c){ //caso a coluna seja a que queremos excluir, pula-se e copia-se todas exceto esta
                i++;
            }
            newaltura[cursor] = alturas[i];
            cursor++;
        }
    }

    char **newjogo = new char*[colunas-1]; //cria-se um novo estado de jogo, porém com uma coluna a menos
    cursor = 0;
    
    //realiza a passagem de operações feitas acima para o estados atual do jogo
    if(c == colunas-1){
        for(int i = 0; i < colunas-1; i++){
            newjogo[cursor] = jogo[i];
            cursor++;
        }
        delete[] jogo[colunas-1]; //desalocamos a coluna excluida(no caso, a ultima posição)
    }
    else{
        for(int i = 0; i < colunas; i++){
            if(i == c){
                delete[] jogo[i];//desalocamos a coluna excluida 
                i++;
            }
            newjogo[cursor] = jogo[i];
            cursor++;
        }
    }

    delete[] jogo; //deleta o ''antigo'' game, com coluna a mais
    delete[] alturas; //deleta a ''antiga'' altura, com coluna a mais
    colunas--; //decrementa-se a coluna 

    alturas = newaltura; //altura recebe a nova altura após modificações das colunas
    jogo = newjogo; //jogo recebe novo jogo após modificações das colunas

}

char** Tetris::create(char id, int rot){
//FUNÇÃO AUXILIAR - recebe o id e a rotação da peça, criando ela JÁ rotacionada e retornando
//No jogo de Tetris ha 7 possiveis pecas (cada uma representada por um caractere distinto).   
    switch (id){
    case 'I':
        if(rot == 0 || rot == 180){//mesmo caso de rotação levando em conta os 2 graus de rotação
            char **I = new char*[4]; //cria-se a peça
            
            for(int i = 0; i < 4; i++){
                I[i] = new char[1];
            }

            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 1; j++){ //formatação da peça
                    I[i][j] = 'I'; //peça recebe o caractere I em todas dimensoes
                }
            }

            altp = 4; //altura e largura para o tipo de rotação especifica
            largp = 1;

            return I;
            break;
        }


        else if(rot == 90 || rot == 270){
            char **I = new char*[1];
            
            I[0] = new char[4];
            
            for(int j = 0; j < 4;j++){  //recebe apenas uma dimensão
                I[0][j] = 'I';
            }
            
            altp = 1;//altura e largura para o tipo de rotação especifica
            largp = 4;

            return I;
            break;
         }
    
    case 'J':

        if(rot == 0){
            char **J = new char*[2];
            for(int i = 0; i < 2 ; i++){
                J[i] = new char[4];
            }

            for(int i = 0; i < 2; i++){
                for(int j = 0;j < 4; j++){
                    if((i == 1 && j == 0) || (i == 1 && j == 1) || (i == 1 && j == 2)){ //formatação da peça
                        J[i][j] = ' ';
                    }
                    else{
                        J[i][j] = 'J';
                    } 
                }
            }

            altp = 2;//altura e largura para o tipo de rotação especifica
            largp = 4;

            return J;
            break;
        }
        

        else if(rot == 90){
            char **J = new char*[4];
            for(int i = 0; i < 4;i++){
                 J[i] = new char[2];
            }

            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 2; j++){
                    if((i == 0 && j == 0) || (i == 1 && j == 0) || (i == 2 && j == 0)){ //formatação da peça
                        J[i][j] = ' ';
                    }
                    else{
                        J[i][j] = 'J';
                    } 
                }
            }

            altp = 4;//altura e largura para o tipo de rotação especifica
            largp = 2;

            return J;
            break;
        }
        else if(rot == 180){
            char **J = new char*[2];
            for(int i = 0; i < 2; i++){
                J[i] = new char[4];
            }

            for(int i = 0; i < 2; i++){
                for(int j = 0;j < 4; j++){
                    if((i == 0 && j == 1) || (i == 0 && j == 2) || (i == 0 && j == 3)){ //formatação da peça
                        J[i][j] = ' ';
                    }
                    else{
                        J[i][j] = 'J';
                    }
                }
            }

            altp = 2;//altura e largura para o tipo de rotação especifica
            largp = 4;

            return J;
            break;
        }

        else if(rot == 270){
            char **J = new char*[4];
            for(int i = 0; i < 4; i++){
                 J[i] = new char[2];
            }

            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 2; j++){
                    if((i == 1 && j == 1) || (i == 2 && j == 1) || (i == 3 && j == 1)){ //formatação da peça
                        J[i][j] = ' ';
                    }
                    else{ 
                        J[i][j] = 'J';
                    }
                }
            }


            altp = 4;//altura e largura para o tipo de rotação especifica
            largp = 2;

            return J;
            break;
        }

    case 'L':
        if(rot == 0){
            char **L = new char*[2];
            for(int i = 0; i < 2; i++){
                 L[i] = new char[4];
            }

            for(int i = 0; i < 2 ; i++){
                for(int j = 0; j < 4; j++){
                    if((i == 1 && j == 1) || (i == 1 && j == 2) || (i == 1 && j == 3)){ //formatação da peça
                        L[i][j] = ' ';
                    }
                    else{
                        L[i][j] = 'L';
                    }
                }
            }

            altp = 2;//altura e largura para o tipo de rotação especifica
            largp = 4;

            return L;
            break;
        }

        else if(rot == 90){
            char **L = new char*[4];
            for(int i = 0; i < 4; i++){
                L[i] = new char[2];
            }

            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 2; j++){
                    if((i == 1 && j == 0) || (i == 2 && j == 0) || (i == 3 && j == 0)){ //formatação da peça
                        L[i][j] = ' ';
                    }
                    else{ 
                        L[i][j] = 'L';
                    }
                }
            }

            altp = 4;//altura e largura para o tipo de rotação especifica
            largp = 2;

            return L;
            break;
        }
        else if(rot == 180){
            char **L = new char*[2];
            for(int i = 0; i < 2; i++){
                L[i] = new char[4];
            }

            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 4; j++){
                    if((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 0 && j == 2)){ //formatação da peça
                        L[i][j] = ' ';
                    }
                    else{
                        L[i][j] = 'L';
                    }
                }
            }

            altp = 2;//altura e largura para o tipo de rotação especifica
            largp = 4;

            return L;
            break;
        }

        else if(rot == 270){
            char **L = new char*[4];
            for(int i = 0; i < 4; i++){
                L[i] = new char[2];
            }

            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 2; j++){
                    if((i == 0 && j == 1) || (i == 1 && j == 1) || (i == 2 && j == 1)){ //formatação da peça
                        L[i][j] = ' ';
                    }
                    else{
                        L[i][j] = 'L';
                    }
                }
            }

            altp = 4;//altura e largura para o tipo de rotação especifica
            largp = 2;

            return L;
            break;
        }

    case 'O':
    //Todos os casos de rotação da peça dão origem á mesma.
        {
            char **o = new char*[2];
            for(int i = 0; i < 2; i++){
                o[i] = new char[2];
            }

            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2;j++){
                    o[i][j] = 'O';
                }
            }

            altp = 2;//altura e largura para o tipo de rotação especifica
            largp = 2;

            return o;
            break;
        }

    case 'S':
        if(rot == 0 || rot == 180){
            char **S = new char*[2];
            for(int i = 0; i < 2; i++){
                S[i] = new char[3];
            }

            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 3; j++){
                    if((i == 0 && j == 0) || (i == 1 && j == 2)){ //formatação da peça
                        S[i][j] = ' ';
                    }
                    else{
                        S[i][j] = 'S';
                    }
                }
            }

            altp = 2;//altura e largura para o tipo de rotação especifica
            largp = 3;

            return S;
            break;
            }
        

        else if(rot == 90 || rot == 270){
            char **S = new char*[3];
            for(int i = 0; i < 3; i++){
                S[i] = new char[2];
            }

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 2; j++){ 
                    if((i == 0 && j == 1) || (i == 2 && j==0)){//formatação da peça
                        S[i][j] = ' ';
                    }
                    else{
                        S[i][j] = 'S';
                    }
                }
            }

            altp = 3;//altura e largura para o tipo de rotação especifica
            largp = 2;

            return S;
            break;

        }

    case 'T':
        if(rot == 0){
            char **T = new char*[2];
            for(int i = 0; i < 2; i++){
                T[i] = new char[3];
            }

            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 3; j++){
                    if((i == 1 && j == 0) || (i == 1 && j == 2)){ //formatação da peça
                        T[i][j] = ' ';
                    }
                    else{ 
                        T[i][j] = 'T';
                    }
                }
            }

            altp = 2;//altura e largura para o tipo de rotação especifica
            largp = 3;

            return T;
            break;

        }
        else if(rot == 90){
            char **T = new char*[3];
            for(int i = 0; i < 3; i++){
                T[i] = new char[2];
            }

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 2; j++){
                    if((i == 0 && j == 0) || (i == 2 && j == 0 )){ //formatação da peça
                        T[i][j] = ' ';
                    }
                    else{
                        T[i][j] = 'T';
                    }
                }
            }
            

            altp = 3;//altura e largura para o tipo de rotação especifica
            largp = 2;
            return T;
            break;

        }

        else if(rot == 180){
            char **T = new char*[2];
            for(int i = 0; i < 2; i++){
                T[i] = new char[3];
            }

            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 3; j++){
                    if((i == 0 && j==0) || (i ==0 && j==2)){ //formatação da peça
                        T[i][j] = ' ';
                    }
                    else{
                        T[i][j] = 'T';
                    }
                }
            }
        
            altp = 2;//altura e largura para o tipo de rotação especifica
            largp = 3;

            return T;
            break;

        }

        else if(rot == 270){
            char **T = new char*[3];
            for(int i = 0;i < 3; i++){
                T[i] = new char[2];
            }

            for(int i = 0; i < 3; i++){
                for(int j =0;j < 2; j++){
                    if((i == 0 && j == 1) || (i == 2 && j == 1)){//formatação da peça
                        T[i][j] = ' ';
                    }
                    else{
                        T[i][j] = 'T';
                    }
                }
            }
            

            altp = 3;//altura e largura para o tipo de rotação especifica
            largp = 2;

            return T;
            break;

        }


    case 'Z':
        if(rot ==0 || rot == 180){
            char **Z = new char*[2];
            for(int i = 0; i < 2 ;i++){
                Z[i] = new char[3];
            }

            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 3; j++){
                    if((i == 0 && j == 2) || (i == 1 && j == 0)){ //formatação da peça
                        Z[i][j] = ' ';
                    }
                    else{
                        Z[i][j] = 'Z';
                    }
                }
            }

            altp = 2;//altura e largura para o tipo de rotação especifica
            largp = 3;

            return Z;
            break;

        }

        else if(rot == 90 || rot == 270){
            char **Z = new char*[3];
            for(int i = 0; i < 3; i++){
                Z[i] = new char[2];
            }

            for(int i = 0; i < 3; i++){
                for(int j =0;j < 2;j++){
                    if((i == 0 && j == 0) || (i == 2 && j == 1)){ //formatação da peça
                        Z[i][j] = ' ';
                    }
                    else{ 
                        Z[i][j] = 'Z';
                    }
                }
            }

            altp = 3;//altura e largura para o tipo de rotação especifica
            largp = 2;

            return Z;
            break;
        }
    default:
        break;
    }
}

bool Tetris::adicionaForma(int coluna, int linha, char id, int rotacao){
//Recebe como argumentos: coluna (um inteiro), linha (inteiro), o id de uma peca (um caractere)
//e uma rotacao (um inteiro que pode valer 0, 90, 180 ou 270).

    char **peca = create(id,rotacao); //recebe a peça a ser inserida por meio da função auxiliar 
    
    //faz a verificação se é possivel inserir na posição soliciatada 
    if(linha + 1 - altp < 0 || coluna + largp > colunas || coluna < 0){ //caso a peça colida com um pixel ja existente
        for(int i = 0; i < altp; i++){                    //ou quando um pixel não vazio estiver fora da area da tela
            delete[] peca[i];
        }
        delete[] peca;
        return false;  //retorna false e não altera o estado atual do jogo 
    }
    
    int alt = 0;

    if(getAltura() > linha){ 
        alt  = getAltura();
    }
    else{
         alt = linha + 1;
    }

    char **newjogo = new char*[colunas];

    for(int i = 0; i < colunas; i++){
        newjogo[i] = new char[alt];  //uma matriz temp semelhante a antiga porém suportando a nova peça 
    }
   
    for(int i = 0; i < colunas; i++){
        for(int j = 0; j < alt;j++){
            newjogo[i][j] = ' '; //preenche os espaços sobressalentes em "branco" 
        }
    }
    //realiza-se uma aritmetica de matrizes, passando os dados da matriz original para a matriz temporaria
    for(int i = 0; i < colunas; i++){
        for(int j = 0; j < alturas[i];j++){
            newjogo[i][j] = jogo[i][j];
        }
    }
    //adicionamos a peça a ser inserida na matriz temporaria
    for(int i = 0; i < largp; i++){
        for(int j = 0; j < altp; j++){
            if(newjogo[coluna+i][linha-j] != ' ' && peca[j][i] != ' ' ){ //se a peça colidir com outra não é possivel adiciona-la

                for(int i = 0; i < colunas; i++){
                    delete[] newjogo[i];
                }
                delete[] newjogo;

                for(int i = 0;i < altp;i++){
                    delete[] peca[i];
                }
                delete[] peca;

                return false;
            }
            else{ 
            //caso seja possivel inserir a peça, o espaço em branco dela não deve sobrepor uma peça já setada
                if(newjogo[coluna + i][linha-j] == ' ' && peca[j][i] != ' '){ 
                    newjogo[coluna +i][linha-j] = peca[j][i];
                }
            }
        }
    }
    //consideramos a nova altura sem os espaços em branco atribuidos acima 
    for(int i = 0; i < colunas; i++){
        for(int j = 0;j < alt;j++){
            if(newjogo[i][j] != ' '){
                alturas[i] = (j+1);
            }
        }
    }

    //copia a matriz auxiliar para a matriz original do jogo
    int aux = 0;
    for(int i = 0; i < colunas;i++){
        aux = 0;
        delete[] jogo[i];
        jogo[i] = new char[alturas[i]];
        for(int j = 0; j < alturas[i]; j++){
            jogo[i][aux] = newjogo[i][j];
            aux++;
        }
    }
    
    for(int i = 0; i < colunas; i++){
        delete[] newjogo[i];
    }
    delete[] newjogo;


    for(int i = 0; i < altp; i++){
        delete[] peca[i];
    }
    delete[] peca;

    return true;
    
}

void Tetris::removeLinhasCompletas(){
//Remove todos os pixels do jogo que estiverem em linhas completas (linhas que não contém espaço em branco). 
//Ao remover uma linha completa os pixels acima de tal linha são “deslocados para baixo”.

    int cont, linha, contBrancos;
    do{
        cont = 0;
        linha = -1; //a linha deve começar com -1 pois a linha 1 representa na matriz a linha 0.
        
        for(int i = 0; i < getAltura(); i++){ //procuramos por linhas completas
            cont = 0;
            for(int j = 0; j < colunas;j++){
                if(i > alturas[j]-1) { //se a altura da coluna não chega até a linha verificada, ela não é completa
                    cont = 0;
                    break;
                }
                if(jogo[j][i] != ' '){
                    cont++; // faz a contagem dos elementos na linha
                }
            }
            if(cont == colunas) {//se o numero de elementos na linha for igual ao de colunas, ela esta cheia
                linha = i; 
                break;
            }
        }
        if(cont == 0){ //não encontramos mais linhas pra remover
            return;
        } 
        //remove as linhas
        int x = 0;
        for(int i = 0; i < colunas; i++){
            x = 0;
            
            while(alturas[i] == 0){
                i++;
            }
            char *line = new char[alturas[i]-1];
            for(int j = 0; j < alturas[i]; j++){
                if(j == linha){ 
                    j++;
                }
                if(j >= alturas[i]){
                     break;
                }
                line[x] = jogo[i][j];
                x++;
            }
            alturas[i]--;
            delete [] jogo[i];
            jogo[i] = line;
        }

        //realizamos o ajuste das linhas com caracteres em "branco"
        contBrancos = 0;
        for(int i=0;i < colunas;i++){
            contBrancos = 0;
            for(int j = 0;j < alturas[i]; j++){
                if(jogo[i][j] == ' '){
                    contBrancos++;   
                }             
            }

            if(contBrancos == alturas[i]){
                delete[] jogo[i];
                jogo[i] = NULL;
                alturas[i] = 0;
            }
        }

    }while(true); 
}
/////////////////OPERADOR DE ATRIBUIÇÃO///////////////
Tetris &Tetris::operator=(const Tetris &other){
    
   if(alturas != NULL || jogo!=NULL){
        delete[] alturas;

        for(int i = 0; i < colunas; i++){
            delete[] jogo[i];
        }
        delete[] jogo;
    }

    colunas = other.colunas;
    alturas = new int[colunas];
    for(int i = 0; i < colunas; i++){
        alturas[i] = other.alturas[i];
    }
    
    jogo = new char*[colunas];
    for(int i = 0; i < colunas; i++){
        jogo[i] = new char[alturas[i]];
    }

    for(int i = 0; i < colunas; i++){
        for(int j = 0; j < alturas[i]; j++){
            jogo[i][j] = other.jogo[i][j];
        }
    }
    return *this;
}
///////////////////CONSTRUTOR DE CÓPIA///////////
Tetris::Tetris(const Tetris& other){
    alturas = NULL;
    jogo = NULL;

    *this = other;
}
/////////////////////DESTRUTOR///////////////////
Tetris::~Tetris(){
    for(int i = 0;i < colunas; i++){
        delete []jogo[i];
    }

    delete []jogo;
    delete []alturas;
}
/////////////////////////////////////////////////