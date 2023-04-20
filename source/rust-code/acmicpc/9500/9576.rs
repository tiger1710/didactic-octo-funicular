// 9576 책 나눠주기

use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).expect("input error");
    let mut input = input
        .split_whitespace()
        .map(|str| str.parse().expect("can't parse"));

    let t = input.next().expect("input error");
    for _ in 0..t {
        let mut nums = Vec::new();
        let n = input.next().expect("input error");
        let m = input.next().expect("input error");
        for _ in 0..m {
            let a = input.next().expect("input error");
            let b = input.next().expect("input error");
            nums.push((b - 1, a - 1));
        }
        nums.sort();

        let mut used = vec![false; n];
        for (b, a) in nums {
            for used in used.iter_mut().take(b + 1).skip(a) {
                if !*used {
                    *used = true;
                    break;
                }
            }
        }

        let count = used.iter().filter(|&&u| u).count();
        println!("{count}");
    }
}
