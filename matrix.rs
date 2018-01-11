use std::default;

type Mat<T> = Vec<Vec<T>>;

fn multiply<T: Copy>(a: Mat<T>, b: Mat<T>) -> Mat<T>
    where T: default::Default
    + std::ops::Mul
    + std::ops::AddAssign<<T as std::ops::Mul>::Output> {
    let row = a.len();
    let col = b[0].len();
    let n = a[0].len();
    let mut res: Mat<T> = Vec::new();
    for i in 0..row {
        let mut res_row = Vec::new();
        for j in 0..col {
            let mut p = Default::default();
            for k in 0..n {
                p += a[i][k] * b[k][j];
            }
            res_row.push(p);
        }
        res.push(res_row);
    }


    res
}

fn main() {
    let m: Mat<f64> = vec![
        vec![1f64,2f64],
        vec![3f64,4f64]
    ];
    let n: Mat<f64> = vec![
        vec![5f64,6f64],
        vec![7f64,8f64],
    ];
    let res = multiply(m, n);
    println!("{:?}", res);
}
