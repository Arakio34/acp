#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

float moyenne(float * x , int size){
	float sum = 0.0;
	for(int i = 0; i<size;i++){
		sum += x[i];
	}
	return sum/size;

}

float correlation(float * x, float * y, int size){

	float numerateur = 0.0 ; 
	float denominateur = 0.0 ; 

	float mean_x =  moyenne(x,size);
	float mean_y =  moyenne(y,size);

	float somme_x = 0.0;
	float somme_y = 0.0;

	printf("Moyenne x %f, Moyenne y %f\n",mean_x, mean_y);

	for( int i = 0; i < size; i++){
		somme_x = somme_x + pow((x[i] - mean_x),2);
		somme_y = somme_y + pow((y[i] - mean_y),2); 
	}
	numerateur = ((somme_x) * (somme_y))/size;
	denominateur = sqrt((somme_x)/size) * sqrt((somme_y)/size);
	printf("somme_x : %f somme_y : %f\n",somme_x,somme_y);
	if(denominateur == 0.0){
		printf("Erreur denominateur null\n");
		return -1;
	}
	return numerateur/denominateur;
}

int main(){
	srand(time(NULL));
	int taille = 10; 
	int mean = 50;
	float var = 6;
	// Generation des donnees 
	float * x =  malloc(sizeof(float) * taille);
	float * y =  malloc(sizeof(float) * taille);

	for(int i = 0; i < taille; i++){
		x[i] =  (double)rand() / RAND_MAX ;
		y[i] =  (double)rand() / RAND_MAX ;
	}

	
	for(int i = 0; i < taille; i++){
		printf("x[i] %f \n",(x[i]));
		printf("y[i] %f \n",(y[i]));
	}

	printf("Moyenne %f \n",moyenne(y,taille));
	printf("Correlation %f \n",correlation(x,y,taille));
	
	free(x);
	free(y);
}
