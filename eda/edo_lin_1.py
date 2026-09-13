import sympy as sp

x  = sp.Symbol('x')
t  = sp.Symbol('t')
c1 = sp.Symbol('c1')
c2 = sp.Symbol('c2')

def calcula_fator_integrante_edo_lin_1(coef_y, x):

    return sp.simplify(c1 * sp.exp(sp.integrate(coef_y, x)))

def calcula_derivada_do_produto(coef_y, constante, x):

    return sp.simplify(constante * calcula_fator_integrante_edo_lin_1(coef_y, x))

def calcula_produto(coef_y, constante, x):

    return sp.simplify(sp.integrate(calcula_derivada_do_produto(coef_y, constante, x), x) + c2)

def calcula_y(coef_y, constante, x):

    mu = sp.simplify(calcula_fator_integrante_edo_lin_1(coef_y, x))

    return sp.simplify(calcula_produto(coef_y, constante, x) / mu)

def resolve_edo_lin_1(coef_y, constante, x):

    print('    m = ' + str(calcula_fator_integrante_edo_lin_1(coef_y, x)))
    print('(my)\' = ' + str(calcula_derivada_do_produto(coef_y, constante, x)))
    print('   my = ' + str(calcula_produto(coef_y, constante, x)))
    print('    y = ' + str(calcula_y(coef_y, constante, x)))

    return calcula_y(coef_y, constante, x)

def avalia_y(x, y, x0, y0):

    print(' y(' + str(x0) + ') = ' + str(sp.simplify(y.subs(x, x0))) + ' = ' + str(y0))
