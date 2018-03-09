/**
 * Copyright (C) 2018
 * Área Académica de Ingeniería en Computadoras, ITCR, Costa Rica
 *
 * This file is part of the numerical analysis lecture CE3102 at TEC
 *
 * @Author: Pablo Alvarado
 * @Date  : 10.02.2018
 */

#include <cmath>
#include <algorithm>
#include <iostream>
#include <limits>
#include <functional>

#include "Exception.hpp"

#ifndef ANPI_ROOT_SECANT_HPP
#define ANPI_ROOT_SECANT_HPP

namespace anpi {

  /**
   * Find a root of the function funct looking for it starting at xi
   * by means of the secant method.
   *
   * @param funct a functor of the form "T funct(T x)"
   * @param xi initial position
   * @param xii second initial position
   *
   * @return root found, or NaN if no root could be found
   */
  template<typename T>
  T rootSecant(const std::function<T(T)>& funct,T xi,T xii,const T eps) {
    /*
    std::cout << "Root Secand Called" << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "xi: " << xi  << " xii: " << xii << std::endl;
    */
    // TODO: Put your code in here!
    const int MAXIT=30;
    T xl,rts;
    T fl= funct(xi);
    T f = funct(xii);
    if (std::abs(fl) < abs(f)) {
      rts=xi;
      xl=xii;
      std::swap(fl,f);
    } else {
      xl=xi;
      rts=xii;
    }
    for (int j=0;j<MAXIT;j++) {
      T dx=(xl-rts)*f/(f-fl);
      xl=rts;
      fl=f;
      rts += dx;
      f=funct(rts);
      if (std::abs(dx) < eps || f == (T)0.0) return rts;
    }


    // Return NaN if no root was found
    return std::numeric_limits<T>::quiet_NaN();
  }

}

#endif
