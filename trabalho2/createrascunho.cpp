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


        if(rot == 90 || rot == 270){
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

            for(int i = 0; i< 2; i++){
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
        

        if(rot == 90){
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
        if(rot == 180){
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

        if(rot == 270){
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

        if(rot == 90){
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
        if(rot == 180){
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

        if(rot == 270){
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
        

        if(rot == 90 || rot == 270){
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
        if(rot == 90){
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

        if(rot == 180){
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

        if(rot == 270){
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

        if(rot == 90 || rot == 270){
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