/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   functor.h
 * Author: Irene Muñoz C
 *
 * Last update 9-3-18
 */

#ifndef FUNCTOR_H
#define FUNCTOR_H

#include <cmath>
#include <iostream>
int NumFuncion = 1;// Esta elige la funcion a utilizar
template <typename T>
class functor {
public:

	//Evalúa la funcion
	inline T operator ( ) (T x){

		if(NumFuncion ==1){// Pide la funcion 1 en este caso 
			return abs(x)-exp(-x);
		}
		else if(NumFuncion == 2){// Pide al funcion 2
			return  exp(-x*x)-exp(-(x-3)*(x-3)/3);
		}
		 // Pide la funcion 3		 
	     return x*x-atan(x);

	}

	// Selecciona la función que se va a evaluar
	void setFuntion(int num){
		NumFuncion = num;
	}

};

#endif /* FUNCTOR_H */

