use std::io;

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();

    stdin
        .read_line(&mut buf)
        .unwrap();

    let ab: Vec<usize> = buf.split_whitespace().map(|n| n.parse().unwrap()).collect();

    buf = String::new();

    stdin
        .read_line(&mut buf)
        .unwrap();

    let splited: Vec<&str> = buf.trim().split("-").collect();
    let mut flag = true;

    if splited.len() == 2 {
        for ch in splited[0].chars().chain(splited[1].chars()) {
            flag = ch.is_digit(10);
        }
        flag = (splited[0].len() == ab[0]) && (splited[1].len() == ab[1]);
    } else {
        flag = false;
    }

    println!("{}", if flag { "Yes" } else { "No"} );
}
