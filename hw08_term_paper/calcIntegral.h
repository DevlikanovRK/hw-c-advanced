#ifndef CALCINTEGRAL_H
#define CALCINTEGRAL_H

float calcIntegralSquare(float xl, float xr, size_t n, function f);
float calcIntegralTrap(float xl, float xr, size_t n, function f);
float calcIntegralSimpson(float xl, float xr, size_t n, function f);
float calcIntegralMonteCarlo(float xl, float xr, float fmax, size_t n, function f);

#endif
