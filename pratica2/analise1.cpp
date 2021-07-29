
//Exemplo de analise de complexidade:
//Note que simplificamos ao máximo na notacao O (removendo o n, ja que O(n^2 +n) = O(n^2), pois a parte quadratica "pesa mais")
//Complexidade: O(n^2 + m + n) = O(n^2 + m)
//O(n² + m + n)
void funcao1(int n, int m){ 
	for(int i=0;i<n;i++) //n
		for(int j=0;j<n;j++)//n
			ct *= j;

	for(int k=0;k<m;k++) //m
		ct += 10;

	for(int k=0;k<n;k++) //N
		ct += 10;
}


//(n² + n²) = O(n²)
void funcao2(int n, int m) { 
	for(int i=0;i<n;i++) //n
		for(int j=0;j<n;j++)//n
			ct *= j;
	
	for(int k=0;k<m;k++) //1 - pois passa constantes
		funcao1(30,40);

	for(int k=0;k<n;k++) //n²
		funcao1(n,200);
}

//(n*k) + m/100000 = O(nk + m)
void funcao3(int n, int m, int k) {
	for(int i=0;i<n;i++)//n
		for(int j=0;j<k;j++)//k
			ct *= m;

	for(int i=0;i<m/100000;i++) {//(m/100000)
		ct += k;
	}
}

//O(N²)
void funcao4(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {//n
		if(v[i]%2==0) break;//
		for(int j=0;j<n;j++) {//n
			ct += v[i] + v[j];//
		}
	}
}
//O(N²)
void funcao5(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {//n
		for(int j=0;j<n;j++) {//n
			ct++;//1
			if(ct%2==0) break;
		}
	}
}

//O(N²)
void funcao6(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {//n		
		for(int j=0;j<n;j++) {//n
			ct+= log(n);//
		}
	}
}
//O(N²)
void funcao7(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=1;i<n;i++) {		//n		
		for(int j=i;j<n;j++) {	//n(detalhe pro começo de j) - somatorio - n(n+1)/2
			ct+= log(n);
		}
	}
}
//O(N*log(m))
void funcao8(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {		
		for(int j=0;j<log(m);j++) {
			ct += sin(k);
		}
	}
}

//Responda (alem de analisar a complexidade): o que essa funcao faz?
//O(log n)
void funcao9(int n) {  //calcula e retorna o valor do log na base 10.
	if(n==0) return 0;	//O(log n)
	return funcao9(n/10)+1;
}
//O(log n + logm)
void funcao10(int n, int m, int k, int v[]) {
	if(n==0 && m==0) return 1;
	if(n==0) return funcao10(n,m/2,k,v);
	else return funcao10(n/2,m,k,v);
}

void funcao11(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) { //n
		for(int j=0;j<v[i];j++){ //
			ct += k;
		}
	}
}
//(n*n*n) = O(n³)
int funcao12(int n) {
    int ans = 0;
    for(int i=5;i<n;i++) //n	
		for(int j=3;j<n;j++)//n
	          for(int k=1;k<n;k++) {//n
	             ans += 2;
	             if(ans%10==0) break;
	          }
     return ans;
}
//u*(v + (f/2)*(v/2)) = O(u*(v+fv) ) = O(ufv)
double funcao13(int v,int u, int f) {
	double ans = 0;
	for(int i=0;i<u;i++) {
	   for(int j=0;j<v;j++) ans -= log(i*j);
	   ans += log(u+i);
	   for(int j2=0;j2<f/2;j2++)//f/2 * v/2
	   	for(int k=v/2;k<v;k++) //v/2
	   		ans += log(j2*k); 
	}
	return ans;
}


//Analise a complexidade de melhor e pior caso dessa função
//Diga não apenas a complexidade, mas também explique quando esses tempos ocorrem

//Melhor caso: quando está na primeira posição do vetor. Complexidade: O(1).
//Pior caso: quando não esta no vetor OU está na ultima posição. Complexidade: O(N).
void funcao14(int n, int m, int k, int v[]) {
	int ct = 0;      
	for(int i=0;i<n;i++) {//n 
		if(v[i]==m)
			return i;		
	}
	return -1;
}

//Analise a complexidade de melhor e pior caso dessa função
//Diga não apenas a complexidade, mas também explique quando esses tempos ocorrem

//Melhor caso: n = 5 --> O(1), pois não entrará no loop.
//Pior caso:O(N³) - para valores significantes de N, entrará dentro de todos os loops aninhados, configurando complexidade n³.
int funcao15(int n, int w) {
    int ans = w;
    for(int i=5;i<n;i++) //n
		for(int j=3;j<n;j++)//n 
	          for(int k=1;k<n;k++) {//n
	             ans += 2;
	             if(ans%10==0) break;
	          }
     return ans;
}

//n*m = O(NM)
int funcao16(int n, int w) {
    double ans = w;
    for(int i=0;i<n;i++) //1
    	for(int j=0;j<n;n--)//n 
    		for(int k=0;k<m;k++)//m	
    			ans += 3.14;
    	
    
    return ans;
}