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
#include <limits>
#include <functional>
#include <iostream>
#include "Exception.hpp"

#ifndef ANPI_ROOT_BISECTION_HPP
#define ANPI_ROOT_BISECTION_HPP

namespace anpi {

/**
 * Find the roots of the function funct looking for it in the
 * interval [xl,xu], using the bisection method.
 *
 * @param funct a std::function of the form "T funct(T x)"
 * @param xl lower interval limit
 * @param xu upper interval limit
 *
 * @return root found, or NaN if none could be found.
 *
 * @throws anpi::Exception if inteval is reversed or both extremes
 *         have same sign.
 */

template<typename T>
T rootBisection(const std::function<T(T)>& funct,T xl,T xu,const T eps) {
	T xr= xl;
	T fl =funct(xl);
	T ea=T();
	{
	int maxi = std::numeric_limits<T>::digits;
	for (int i = maxi; i > 0; --i) {
		T xrold(xr);
		xr = (xl+xu)/T(2);
		T fr = funct(xr);

		if(std::abs(xr) > std::numeric_limits<T>::epsilon()){
			ea = std::abs((xr-xrold)/xr)*T(100);
		}
		T cond = fl*fr;

		if (cond < T(0))
			xu = xr;
		else if (cond > T(0)){
			xl = xr;
			fl = fr;
		}
		else{
			ea = T(0);
			xr = (std::abs(fl) < std::numeric_limits<T>::epsilon())?xl:xr;
		}
		if(ea < std::sqrt(std::numeric_limits<T>::epsilon())) return xr;
	}
	}

	// TODO: Put your code in here!
	// Return NaN if no root was found
	return std::numeric_limits<T>::quiet_NaN();
}


}

#endif
