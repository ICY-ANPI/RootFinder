/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Irene
 *
 * Last edited 9-3-18
 */

#include <stdio.h>
#include "iostream"
#include "resolver.h"
#include "functor.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    functor<double> f;
    resolver<double> r;
    
    //funcion sqr(x) -exp(-x), entre 0 y 1
    cout<<"Newton Raphson: "<<r.NewtonRaphson(f,0,1)<<endl;
    
    return 0;
}

