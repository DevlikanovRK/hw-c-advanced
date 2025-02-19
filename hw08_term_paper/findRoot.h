#ifndef FINDROOT_H
#define FINDROOT_H

int signF(float x, function f);
float rootFindLine(float xl, float xr, float eps, function f);
float rootFindDiv(float xl, float xr, float eps, function f);
float rootFindDiv2(float xl, float xr, float eps, function f);
float rootFindChord(float xl, float xr, float eps, function f);
float rootFindTangent(float xn, float eps, function f, function df);
float rootFindCombine(float xl, float xr, float eps, function f, function df, function ddf);

#endif
