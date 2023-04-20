// 1422 숫자의 신

use std::io::{self, Read};
use std::iter;

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).expect("input error");
    let mut input = input.split_whitespace().skip(1);

    let n: usize = input
        .next()
        .expect("input error")
        .parse()
        .expect("can't parse");
    let mut nums: Vec<_> = input.collect();
    let &biggest = nums
        .iter()
        .max_by(|lhs, rhs| lhs.len().cmp(&rhs.len()).then(lhs.cmp(rhs)))
        .expect("nums is empty");
    let n = n - nums.len();
    let repeat_biggest = iter::repeat(biggest).take(n);
    nums.extend(repeat_biggest);

    nums.sort_by(|&lhs, &rhs| {
        (lhs.to_owned() + rhs)
            .cmp(&(rhs.to_owned() + lhs))
            .reverse()
    });

    let ans = nums.iter().fold(String::new(), |acc, str| acc + str);

    println!("{ans}");
}
