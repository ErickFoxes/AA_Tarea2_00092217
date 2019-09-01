// Escribir un programa que invierta el contenido de una cola y lo guarde en una pila
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//Cola
struct Nodo{
	int dato;
	Nodo *sig;
}*inicio,*fin;

class Cola{
	public:
		Cola(){
			inicio=NULL;
			fin=NULL;
		}
		Nodo* crearNodo(int valor){
			Nodo *n = new Nodo;
			n->dato = valor;
			n->sig = NULL;
			return n;
		}
		void push(int valor){
			Nodo *n =crearNodo(valor);
			if(!inicio){
				inicio=n;
				fin=n;
			}else{
				fin->sig=n;
				fin=n;
			}
		}
		void pop(){
			Nodo *temp = inicio;
			inicio = inicio->sig;
			free(temp);
		}

		int retornarUltimoValor(){
			return inicio->dato;
		}
			
		int contarNodos(){
            Nodo *temp = inicio;
			if(!inicio)
			    return 0;
			else{
				int cont=1;
				while(temp){
					cont++;
					temp = temp ->sig;
				}
				return cont;
			}
		}
		
		void mostrarCola(){
			Nodo *temp = inicio;
			if(!inicio)
			    cout<<"Cola vacio"<<endl;
			else{
				while(temp){
					cout<<temp->dato<<", ";
					temp = temp ->sig;
				}
			}

		}
};
//pila
struct NodoPila{
	int dato;
	NodoPila *sig;
}*iniciop;

class Pila{
	public:
		Pila(){
			iniciop=NULL;
		}
		NodoPila* crearNodo(int valor){
			NodoPila *n = new NodoPila;
			n->dato = valor;
			n->sig = NULL;
			return n;
		}
		void push(int valor){
			NodoPila *n =crearNodo(valor);
			n->sig = iniciop;
			iniciop = n;
		}
		void pop(){
			NodoPila *temp = iniciop;
			iniciop = iniciop->sig;
			free(temp);
		}
		
		void mostrarPila(){
			NodoPila *temp = iniciop;
			if(!iniciop)
			    cout<<"Pila vacio"<<endl;
			else{
				while(temp){
					cout<<temp->dato<<", ";
					temp = temp ->sig;
				}
			}

		}
};

int main()
{
	//crear la cola y la pila
    Pila p1;
    Cola c1;
    //mostrarlas
    p1.mostrarPila();
    c1.mostrarCola();
    //aagregar los datos a la cola
	c1.push(6);
	c1.push(7);
	c1.push(8);
	//mostrar la cola
	cout<<"Cola:"<<endl;
	
	c1.mostrarCola();
	cout<<endl;
	//Agregar los datos de la cola a la pila
	for(int i=0;i<=c1.contarNodos();i++ ){
        p1.push(c1.retornarUltimoValor());
        c1.pop();
	}
	//mostrar pila llena y la cola vacia
	cout<<"Pila:"<<endl;
	p1.mostrarPila();
	cout<<endl;
	c1.mostrarCola();
	cout<<endl;
	system("PAUSE");
}
