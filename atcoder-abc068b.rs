use std::io;

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();

    stdin
        .read_line(&mut buf)
        .unwrap();

    let n: usize = buf.trim().parse().unwrap();

    let mut m = 1;

    for i in 1..n {
        if m * 2 <= n {
            m *= 2;
        } else {
            break;
        }
    }

    println!("{}", m);
}
