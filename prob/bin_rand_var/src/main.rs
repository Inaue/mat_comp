fn main() {

    const N: u128 = 100;
    const P: f32   = 0.75;
    const S: u128 = 70;

    for i in 0..=N {

        println!("{} -> {}, {}", i, bin_rand_var_prob(N, P, i as u128), bin_rand_var_dist_2(N, P, i as u128));
    }
}

fn fac(n: u128) -> u128 {
    
    (1..=n).product()
}

fn comb(n: u128, r: u128) -> u128 {

    let diff:  u128 = n - r;
    let maior: u128 =
    match r.cmp(&diff) {
        
        std::cmp::Ordering::Less    => n - r,
        std::cmp::Ordering::Equal   => r,
        std::cmp::Ordering::Greater => r,
    };

    ((maior + 1)..=n).product::<u128>() / fac(n - maior)
}

fn comb_2(n: u128, r: u128) -> u128 {

    if r == 0 || n == r {

        return 1 as u128;
    }
    else if n < r {

        return 0 as u128;
    }

    let mut contador:    u128 = 1;
    let mut numerador:   u128 = n;

    for denominador in 1..=r {
        
        contador  *= numerador;
        contador  /= denominador;
        numerador -= 1;
    }

    contador
}

fn perm(n: u128, r: u128) -> u128 {

    fac(n) / fac(n - r)
}

fn bin_rand_var_prob(n: u128, p: f32, s: u128) -> f32 {

    let combinacoes:   u128 = comb_2(n.try_into().unwrap(), s.try_into().unwrap());
    let probabilidade: f32  = p.powi((s as u128).try_into().unwrap()) * (1.00 - p).powi(((n - s) as u128).try_into().unwrap()) * combinacoes as f32;

    probabilidade
}

fn bin_rand_var_dist(n: u128, p: f32, s: u128) -> f32 {

    let mut prob_i:    f32 = bin_rand_var_prob(n, p, 0);
    let mut sum:       f32 = 0.0;
    let mut numerador: f32 = n as f32;
    let     const_fat: f32 = p / (1.0 - p);

    for i in 1..=s {
        
        sum       += prob_i;
        prob_i    *= const_fat * numerador / (i as f32);
        numerador -= 1.0;
    }

    sum += prob_i;

    sum
}

fn bin_rand_var_dist_2(n: u128, p: f32, s: u128) -> f32 {

    let mut prob_i:      f32 = bin_rand_var_prob(n, p, s);
    let mut sum:         f32 = 0.0;
    let mut denominador: f32 = (n - s + 1) as f32;
    let     const_fat:   f32 = (1.0 - p) / p;

    for i in (0..s).rev() {
        
        sum         += prob_i;
        prob_i      *= const_fat * (i + 1) as f32 / denominador;
        denominador += 1.0;
    }

    sum += prob_i;

    sum
}
