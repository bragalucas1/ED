#ifndef TETRIS_H
#define TETRIS_H


class Tetris{
    private:
    //Array dinamico representando a tela do jogo
    char **jogo;
    //Variável que armazena o numero de colunas
    int colunas;
    //Array inteiro de alturas
    int *alturas;
    //Função auxiliar da função adicionaForma que recebe a peça e retorna ela ja rotacionada
    char **create(char id, int rot); 
    //Variaveis auxiliares que representam as dimensões da peça, altura e largura respectivamente
    int alturap, largurap; 
    
    public:
    //Construtor padrão da classe
    Tetris(int c);
    //Construtor de cópia
    Tetris(const Tetris&);
    //Destrutor padrão da classe
    ~Tetris();

    //*******MÉTODOS GET*******//
    //Método get padrão - retorna o pixel do jogo atual
    char get(int c, int l) const;

    //Método get que retorna o numero de colunas
    int getNumColunas() const;

    //Método get que retorna a altura maxima do jogo
    int getAltura(int c) const;

    //Método get que retorna a altura da coluna c do jogo
    int getAltura() const;
    //**************************//

    //Função responsável por adicionar elementos no jogo
    bool adicionaForma(int coluna, int linha, char id, int rotacao);

    //Função que remove linhas completas
    void removeLinhasCompletas();

    //Funçao para remover colunas
    void removeColuna(int c);

    //Operador de atribuição
    Tetris &operator=( const Tetris &);


};

#endif