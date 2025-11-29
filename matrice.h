#ifndef MATRICE_H
#define MATRICE_H
struct matrice {
	int ligne;
	int colone;
	float ** coeficient;
} typedef matrice;


matrice add(matrice * m1, matrice * m2);
matrice sub(matrice * m1, matrice * m2);
matrice dot(matrice * m1, matrice * m2);
matrice T(matrice * m1);

#endif
