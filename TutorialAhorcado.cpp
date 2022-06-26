#include <iostream>

using namespace std;

void LimpiarPantalla();
void JugarPartida();
void Dibujar();

char eleccion;
string palabras[] = {"monitor","microfono","televisor","telefono","caja","fibron","teclado","pc","collar","manzana"};
string palabra , fallidas; 
int nA;
int vida;
bool correcta, completa;

int main(){
	while(true){
		vida = 6;
		palabra = "";
		fallidas = "";
		LimpiarPantalla();
		cout<<"\t::::MENU::::"<<endl;
		cout<<"1) Jugar Partida."<<endl;
		cout<<"2) Salir."<<endl;
		cout<<"Eleccion: ";
		cin>>eleccion;
		switch(eleccion){
			case '1':
				JugarPartida();
				break;
			case '2':
				return 0;
				break;
		}
	}
}

void JugarPartida(){
	srand((int)time(NULL));
	nA = rand()%10;
	
	for(int i = 0; i < (int)palabras[nA].size(); i++){
		palabra += "-";
	}
	
	while(vida > 0){
		LimpiarPantalla();
		cout<<"\t::: A H O R C A D O :::"<<endl;
		Dibujar();
		cout<<"Fallos: "<<fallidas;
		cout<<"  Progreso: "<<palabra<<endl;
		cout<<"Ingrese una letra(minuscula): ";
		cin>>eleccion;
		
		correcta = false;
		for(int i = 0; i < (int)palabras[nA].size(); i++){
			if(palabras[nA][i] == eleccion){
				palabra[i] = eleccion;
				correcta = true;	
			}
		}
		if(!correcta){
			vida--;
			fallidas += eleccion;
		}
		
		completa = true;
		for(int i = 0; i < (int)palabra.size(); i++){
			if(palabra[i] == '-'){
				completa = false;
			}
		}
		if(completa){
			LimpiarPantalla();
			cout<<"\t::: A H O R C A D O :::"<<endl;
			Dibujar();
			cout<<"Palabra: "<<palabras[nA]<<endl;
			cout<<"Ganaste. Ingresa un caracter para continuar: ";
			cin>>eleccion;
			return;
		}
	}
	LimpiarPantalla();
	cout<<"\t::: A H O R C A D O :::"<<endl;
	Dibujar();
	cout<<"Palabra: "<<palabras[nA]<<endl;
	cout<<"Perdiste. Ingresa un caracter para continuar: ";
	cin>>eleccion;
	return;
}

void Dibujar(){
	switch(vida){
		case 6:
		cout<<"  --------"<<endl;
		cout<<"  |      |"<<endl;
		cout<<"  |"<<endl;
		cout<<"  |"<<endl;
		cout<<"  |"<<endl;
		cout<<"  |"<<endl;
		cout<<"  |"<<endl;
		cout<<" ---"<<endl;
		break;
		case 5:
		cout<<"  --------"<<endl;
		cout<<"  |      |"<<endl;
		cout<<"  |      O"<<endl;
		cout<<"  |"<<endl;
		cout<<"  |"<<endl;
		cout<<"  |"<<endl;
		cout<<"  |"<<endl;
		cout<<" ---"<<endl;
		break;
		case 4:
		cout<<"  --------"<<endl;
		cout<<"  |      |"<<endl;
		cout<<"  |      O"<<endl;
		cout<<"  |      |"<<endl;
		cout<<"  |"<<endl;
		cout<<"  |"<<endl;
		cout<<"  |"<<endl;
		cout<<" ---"<<endl;
		break;
		case 3:
		cout<<"  --------"<<endl;
		cout<<"  |      |"<<endl;
		cout<<"  |      O"<<endl;
		cout<<"  |     /|"<<endl;
		cout<<"  |"<<endl;
		cout<<"  |"<<endl;
		cout<<"  |"<<endl;
		cout<<" ---"<<endl;
		break;
		case 2:
		cout<<"  --------"<<endl;
		cout<<"  |      |"<<endl;
		cout<<"  |      O"<<endl;
		cout<<"  |     /|\\"<<endl;
		cout<<"  |"<<endl;
		cout<<"  |"<<endl;
		cout<<"  |"<<endl;
		cout<<" ---"<<endl;
		break;
		case 1:
		cout<<"  --------"<<endl;
		cout<<"  |      |"<<endl;
		cout<<"  |      O"<<endl;
		cout<<"  |     /|\\"<<endl;
		cout<<"  |     /"<<endl;
		cout<<"  |"<<endl;
		cout<<"  |"<<endl;
		cout<<" ---"<<endl;
		break;
		case 0:
		cout<<"  --------"<<endl;
		cout<<"  |      |"<<endl;
		cout<<"  |      O"<<endl;
		cout<<"  |     /|\\"<<endl;
		cout<<"  |     / \\"<<endl;
		cout<<"  |"<<endl;
		cout<<"  |"<<endl;
		cout<<" ---"<<endl;
		break;
	}
}

void LimpiarPantalla(){
	if(system("clear") == -1){
		cout<<"Error al borrar la pantalla.";
	}
}
