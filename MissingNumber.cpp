// MissingNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root 
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest);
	}
}

void build_max_heap(int A[], int n) {
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(A, n, i);
}

void imprimirArreglo(int A[],int n) {
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

int missingNumber(int A[]) {
	int highest = A[0]; //se toma el elemento mas grande del arreglo proporcionado
	if (highest % 2 == 0) { //si el numero es par
		return highest + 2;
	}
	else {
		return highest + 1;
	}
}

int main()
{
	//se piden cuantos casos de prueba habran
	int T;
	cout << "Cuantas pruebas habran: ";
	cin >> T;
	//Se crea un arreglo que tendra todas las respuestas
	int respuestas[10];

	//se iteran todos los casos
	for (int i = 0; i < T; i++) {
		//se pedira escoger el tamano del arreglo en esa iteracion
		int N;
		cout << "Cual es el tamano del arreglo: ";
		cin >> N;
		//Se crea un arreglo de ese tamano
		int A[105];
		cout << "Ingrese los datos del arreglo: ";
		//se itera para llenar los elementos del arreglo
		for (int j = 0; j < N; j++) {
			cin >> A[j];
		}

		build_max_heap(A, N); // se arreglo el arreglo como un max heap

		respuestas[i] = missingNumber(A); //se guarda el missing number del arreglo de esa iteracion
		


	}

	//se muestran los missing number de cada caso
	for (int i = 0; i < T; i++) {
		cout << "El missing number del caso " << i + 1 << " es: " << respuestas[i] << endl;
	}

	return 0;
}

