import sympy as sp

x  = sp.Symbol('x')
t  = sp.Symbol('t')
y  = sp.Symbol('y')
c1 = sp.Symbol('c1')
c2 = sp.Symbol('c2')
c3 = sp.Symbol('c3')

def integra_coef_x(coef_x, x):

    return sp.simplify(sp.integrate(coef_x, x)) + c1

def integra_coef_y(coef_y, y):

    return sp.simplify(sp.integrate(coef_y, y)) + c2

def resolve_separavel_1(coef_x, coef_y, x, y):

    print('dh/dy = ' + str(integra_coef_y(coef_y, y)))
    print('dh/dx = ' + str(integra_coef_x(coef_x, x)))
    print(str((integra_coef_y(coef_y, y) - c2) - (integra_coef_x(coef_x, x) - c1)) + ' = ' + str(c3))

    return (integra_coef_y(coef_y, y) - c2) - (integra_coef_x(coef_x, x) - c1)

def avalia_c3(equacao, x0, y0, x, y):

    print('c3 = ' + str(sp.simplify(equacao.subs(x, x0).subs(y, y0))))

