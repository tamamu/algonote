

fn sort<T: Ord>(arr: &[T]) -> Vec<&T> {
    let l = arr.len();
    let mut res: Vec<&T> = arr.iter().collect();
    for i in 0..l {
        let val = &arr[i];
        let mut idx = 0;
        for j in 0..i {
            if *res[j] < *val {
                idx = j+1;
            }
        }
        if idx < i {
            for k in (idx..i).rev() {
                res[k+1] = res[k];
            }
        }
        println!("{}-th element's index is {}", i, idx);
        res[idx] = &arr[i];
    }
    res
}

fn main() {
    let data1 = [5, 3, 1, 7, 2];
    let data2 = [7,6,5,4,3,2,1];
    let data3 = [0, 1, 2, 3, 4];
    println!("{:?}",data1);
    let sorted1 = sort(&data1);
    println!("{:?}\n",sorted1);
    assert_eq!(sorted1, vec![&1,&2,&3,&5,&7]);
    println!("{:?}",data2);
    let sorted2 = sort(&data2);
    println!("{:?}\n",sorted2);
    assert_eq!(sorted2, vec![&1,&2,&3,&4,&5,&6,&7]);
    println!("{:?}",data3);
    let sorted3 = sort(&data3);
    println!("{:?}",sorted3);
    assert_eq!(sorted3, vec![&0,&1,&2,&3,&4]);
}
