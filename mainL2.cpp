#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <math.h>


int menu() {
	int flag = 0;
	while(flag == 0) {
		cout<<endl<<" --- MENÚ ---"
		<<endl<<"1.- Ejercicio 1: Figura"
		<<endl<<"2.- Ejercicio 2: Logaritmos"
		<<endl<<"3.- Ejercicio 3: Precisión"
		<<endl<<endl<<"4.- Salir."
		<<endl<<endl<<"Por favor, ingrese una opción: ";
		cin>>flag;

		if (flag < 1 || flag > 4) {
			flag = 0;
			cout<<"Opción inválida. Por favor, intente de nuevo."<<endl<<endl;
		}		
	}
	return flag;
}

int main() {
	int opt = 0;
	do {
		switch(opt = menu()) {
			case 1: {
					int num = 0; 
					cout<<endl<<"Ingrese un número entero: ";
					cin>>num;
					while (num <= 0) {
						cout<<endl<<"Número inválido. Por favor, ingrese un nuevo número: ";
						cin>>num;
					}
					int rows = 2*(num + 1);
					int cols = 2*rows - 1;
					int half = cols/2;
					int half2 = half/2;
					for (int i = 0; i < rows; i++) {
						for (int j = 0; j < cols; j++) {
							if ((j >= half-i && j <= half + i) || (j == half || j == half2)) {
								cout<<"*";
							} else {
								cout<<" ";
							}
					}
						cout<<endl;
					}
					cout<<endl;
				}
				break;
			case 2: {
				double num = 0;
				cout<<"Ingrese un número: ";
				cin>>num;
				cout<<endl<<"log("<<num<<") = ";
				double num_round = 0;
				
				if (num > 10) {
					if (num > 5) {
						num_round = 10;
					} else {
						num_round = 0;
					}
				}

				num_round = num/10;
				num_round = round(num_round);

				while (num_round >= 10) {
					cout<<"log(10) +";
					num_round = num_round/10;
				}
				int nump = 0;
				for (int i = 1; num_round <= 1.3; i++) {
					num_round = num_round/i;
					nump = i;
				}
				cout<<"log("<<nump<<") + log("<<num_round<<")";
				}
			       	break;
			case 3:{
				double y = 0.0;
				double p = 0.0;
				double x = 0.0;
				double m = 0.0;
				cout<<"Por favor, ingrese un valor y: ";
				cin>>y;
				while (y < 0) {
					cout<<"Por favor, ingrese un valor positivo: ";
					cin>>y;
				}
				cout<<"Ingrese la precisión: ";
				cin>>p;
				while (p < 0) {
					cout<<"Por favor, ingrese un valor positivo: ";
					cin>>p;
				}
				cout<<"Ingrese un valor m: ";
				cin>>m;
				while (m < 0) {
					cout<<"Por favor, ingrese un valor positivo: ";
					cin>>m;
				}
				x = p;
				while (sqrt(x)*m < y) {
					x = x+p;
			       }
				cout<<"El valor final de x es "<<x<<" utilizando el método de la aproximación.";
			       }
				break;
			case 4:
				cout<<endl<<"Cerrando programa..."<<endl;
				opt = 4;
				break;
		}
	} while (opt != 4);
	return 0;
}

