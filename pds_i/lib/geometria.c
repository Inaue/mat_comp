#include <math.h>
#include "geometria.h"

double area_do_triangulo(double base, double altura)
{
    return (base * altura) / 2;
}

double area_do_circulo(double raio)
{
    return M_PI * raio * raio;
}