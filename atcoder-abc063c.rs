use std::io;

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();

    stdin.read_line(&mut buf).unwrap();

    let n: usize = buf.trim().parse().unwrap();

    let mut s: Vec<usize> = Vec::new();
    let mut sum: usize = 0;
    let mut non10: Vec<usize> = Vec::new();

    for i in 0..n {
        buf = String::new();
        stdin.read_line(&mut buf).unwrap();
        s.push(buf.trim().parse().unwrap());
        sum += s[i];
        if s[i] % 10 > 0 {
            non10.push(s[i]);
        }
    }

    non10.sort();
    if sum % 10 == 0 {
        if non10.len() == 0 {
            sum = 0;
        } else {
            sum -= non10[0];
        }
    }

    println!("{}", sum);
}
