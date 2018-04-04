// Binary Search

use std::cmp::{Ord, Ordering};

/* rust/src/libcore/slice/mod.rs

   fn binary_search_by<'a, F>(&'a self, mut f: F) -> Result<usize, usize>
        where F: FnMut(&'a T) -> Ordering
    {
        let s = self;
        let mut size = s.len();
        if size == 0 {
            return Err(0);
        }
        let mut base = 0usize;
        while size > 1 {
            let half = size / 2;
            let mid = base + half;
            // mid is always in [0, size), that means mid is >= 0 and < size.
            // mid >= 0: by definition
            // mid < size: mid = size / 2 + size / 4 + size / 8 ...
            let cmp = f(unsafe { s.get_unchecked(mid) });
            base = if cmp == Greater { base } else { mid };
            size -= half;
        }
        // base is always in [0, size) because base <= mid.
        let cmp = f(unsafe { s.get_unchecked(base) });
        if cmp == Equal { Ok(base) } else { Err(base + (cmp == Less) as usize) }
}

*/

fn boundary<F>(ok: usize, ng: usize, f: F) -> Result<usize, usize>
    where F: Fn(&usize) -> Ordering
{
    let mut size = (ok as i32 - ng as i32).abs();
    if size == 0 {
        return Err(0);
    }
    let mut a = ok;
    let mut b = ng;
    let mut ans = Err(0);
    while size > 1 {
        let half = size / 2;
        let mid = (a + b) / 2;
        match f(&mid) {
            Ordering::Less => {
                a = mid;
            },
            Ordering::Greater => {
                b = mid;
            },
            Ordering::Equal => {
                ans = Ok(mid);
                break;
            }
        }
        size -= half;
    }

    if ans.is_err() {
        Err(b)
    } else {
        ans
    }
}

fn binary_search<T>(s: &Vec<T>, target: &T) -> Result<usize, usize>
    where T: Ord
{
    boundary(0, s.len() - 1, |i|{s[*i].cmp(target)})
}

fn main() {
    let g = vec![1,1,1,2,3,3,4,5,8,9,10,13,15];
    println!("target:{:?}", g);
    let res = binary_search(&g, &5);
    println!("5 -> {:?} ({})", res, g[res.unwrap()]);
    let res = binary_search(&g, &6);
    println!("6 -> {:?} ({})", res, g[res.unwrap_err()]);
    let res = binary_search(&g, &0);
    println!("0 -> {:?} ({})", res, g[res.unwrap_err()]);
    let res = binary_search(&g, &20);
    println!("20 -> {:?} ({})", res, g[res.unwrap_err()]);
}
