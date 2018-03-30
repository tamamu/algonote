use std::io;

fn contain(num: usize) -> usize {
	let g1 = vec![1,3,5,7,8,10,12];
	let g2 = vec![4,6,9,11];
	if g1.contains(num) {
		0
	} else if g2.contains(num) {
		1
	} else {
		2
	}
}

fn main() {
	let stdin = io::stdin();
	let mut buf = String::new();

	stdin.read_line(&mut buf).unwrap();

	let xy: Vec<usize> = buf.split_whitespace().map(|n| n.parse().unwrap()).collect();

	let a = contain(xy[0]);
	let b = contain(xy[1]);

	if a == b {
		println!("Yes");
	} else {
		println!("No");
	}
}
