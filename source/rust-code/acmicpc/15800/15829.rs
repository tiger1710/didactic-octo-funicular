// 15829 Hashing

use std::io::{self, Read};

const R: usize = 31;
const M: usize = 1234567891;

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");

    let input = input
        .split_whitespace()
        .nth(1)
        .expect("Failed to get input");

    let p = |i: usize| -> usize {
        let mut acc = 1;
        for _ in 0..i {
            acc = acc * R % M;
        }
        acc
    };
    let hash = input.chars().enumerate().fold(0, |acc, (i, c)| {
        let c = c as usize - 'a' as usize + 1;
        (acc + c * p(i)) % M
    }) % M;

    println!("{hash}");
}
