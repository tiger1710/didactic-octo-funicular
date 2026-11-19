// 11050 이항 계수 1

use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");

    let mut input = input
        .split_whitespace()
        .map(|str| str.parse::<usize>().expect("parse error"));
    let n = input.next().expect("input error");
    let k = input.next().expect("input error");

    // (binom{N}{K})
    // = (N! / (K! * (N-K)!))
    // = (N * (N-1) * ... * (N-K+1)) / (K * (K-1) * ... * 1)

    let ans = (n - k + 1..=n).fold(1, |acc, x| acc * x) / (1..=k).fold(1, |acc, x| acc * x);
    println!("{ans}");
}
