

fn sort<T: Ord>(arr: &[T]) -> Vec<&T> {
    let mut res: Vec<&T> = Vec::with_capacity(arr.len());
    res
}

fn main() {
    let data = [5, 3, 1, 7, 2];
    let sorted = sort(&data);
    println!("{:?}",sorted);
}
