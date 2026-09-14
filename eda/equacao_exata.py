exec(open('edo_lin_1.py').read())

import sympy as sp

x  = sp.Symbol('x')
y  = sp.Symbol('y')
c1 = sp.Symbol('c1')
c2 = sp.Symbol('c2')

def calcula_fator_integrante_y_equacao_exata(dmdy, dndx, coef_m, y):

    print('')

    return resolve_edo_lin_1((dmdy - dndx) / coef_m, 0, y)

def calcula_fator_integrante_x_equacao_exata(dmdy, dndx, coef_n, x):

    print('')

    return resolve_edo_lin_1((dndx - dmdy) / coef_n, 0, x)

def resolve_equacao_nao_exata(coef_m, coef_n, x, y):

    dmdy = sp.simplify(sp.diff(coef_m, y))
    dndx = sp.simplify(sp.diff(coef_n, x))

    print('dm/dy = ' + str(dmdy))
    print('dn/dx = ' + str(dndx))

    if dmdy == dndx:
        return resolve_equacao_exata(coef_m, coef_n, x, y)

    mu = calcula_fator_integrante_x_equacao_exata(dmdy, dndx, coef_n, x)

    if mu.diff(y) != 0:
        mu = calcula_fator_integrante_y_equacao_exata(dmdy, dndx, coef_m, y)

    mu = mu.subs(c1, 1).subs(c2, 1)

    print('')
    print('mu = ' + str(mu))
    print('')

    return resolve_equacao_exata(coef_m * mu, coef_n * mu, x, y)


def resolve_equacao_exata(coef_m, coef_n, x, y):

    dmdy = sp.simplify(sp.diff(coef_m, y))
    dndx = sp.simplify(sp.diff(coef_n, x))

    print('dm/dy = ' + str(dmdy))
    print('dn/dx = ' + str(dndx))
    
    im   = coef_m.integrate(x)
    dhdy = coef_n - im.diff(y)
    h    = dhdy.integrate(y) + c1

    print('    p = ' + str(im) + ' + h')
    print('dh/dy = ' + str(dhdy))
    print('    h = ' + str(h))
    print('')
    print(str(im + h - c1) + ' = ' + str(c2))

    return im + h

def avalia_c(equacao, x0, y0, x, y):

    print('c = ' + str(sp.simplify(equacao.subs(x, x0).subs(y, y0))))
