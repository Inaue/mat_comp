fn main() {

    const N: usize = 10;
    let   p: f32   = 0.01;

    println!("{}", 1.00 - (bin_rand_var(N, 0, p) + bin_rand_var(N, 1, p)));
}

fn fac(n: i32) -> i32 {
    
    (1..=n).product()
}

fn comb(n: i32, r: i32) -> i32 {

    fac(n) / (fac(r) * fac(n - r))
}

fn perm(n: i32, r: i32) -> i32 {

    fac(n) / fac(n - r)
}

fn bin_rand_var(n: usize, s: usize, p: f32) -> f32 {

    let combinacoes: i32 = comb(n.try_into().unwrap(), s.try_into().unwrap());
    p.powi(s as i32) * (1.00 - p).powi((n - s) as i32) * combinacoes as f32
}
