/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   resolver.h
 * Author: Irene
 *
 * Created on 9 de marzo de 2018, 02:50 AM
 */

#ifndef RESOLVER_H
#define RESOLVER_H
#include <stdio.h>
#include "iostream"
#include <stdlib.h>
#include "math.h"
using namespace std;

template<typename T>
class resolver{
public:
//Calcula las raices por medio de Newton Raphson
//Entradas: 
    //intervaloIn = limite interior
    //intervaloSup = limite superior
template <typename F> T NewtonRaphson(F & funct,double intervaloIn, double intervaloSup){
	T x0;
	double a = intervaloIn; // Numero 1 del rango total
	double b = intervaloSup; // Numero 2 del rango total 
	int i = 8; // Itera valor y obtiene el punto inicial
	x0 = puntoInicial(funct,a,b,i);

	double x1; // Siguiente aproximación
			double error;    // x1 -x0 diferencia de aproximaciones
			int itera; // Cantidad de iteraciones
			bool converge = true; 
			int max_itera =100; // Cantidad maxima de iteraciones que vamos a permitir
			double tol = 0.01; // Tolerancia, se compara con error para finalizar, el error debe ser <= que la tolerancia
			itera = 1;  // Inicializamos itera en 1
			while(1) {

				if (itera > max_itera) {
					converge = false;   // Cuando se pasa de la max cantidad de iteraciones(mal portada)
					break;

				} else {
					x1 = x0 - funct(x0) / func_derivada(x0); // La nueva aproximación
					error = fabs(x1 - x0);  // Calcula el error 
					if (error <= tol) { // Condición de finalización
						converge = true;
						break;
					} else {
						x0 = x1;
						itera++;
					}
				}
			}
			if (converge) {
				return x1;
			} else {
				cout << "Error: muchas iteraciones sin llegar a resultado con Newton Raphson" << endl;
			}
			return 0;
    }
template <typename F>T puntoInicial(F & funct,T i1, T i2, int intervalos){
		int intervaloPts = intervalos + 1;
		double ancho = (i2 - i1) / intervalos;
		for (int i = 0; i < intervaloPts; i++) {
			i1 = i1 + ancho;
			if (funct(i1) > 0){
				return i1 - ancho;
			}
		}
		return i1 - 3 * ancho; // Cuando no hay cambio de signo, retorna la mitad del itervalor

	}
T func_derivada(T x)
	{
		return 2*x-cos(x); // Derivada de la función a utilizar

	}

};

#endif /* RESOLVER_H */

