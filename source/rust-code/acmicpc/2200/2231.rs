// 2231 분해합

use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");

    let mut input = input
        .split_whitespace()
        .map(|str| str.parse().expect("parse error"));

    let n: usize = input.next().unwrap();

    let mut result = 0;
    for i in 1..n {
        let mut sum = i;
        let mut num = i;
        while num > 0 {
            sum += num % 10;
            num /= 10;
        }
        if sum == n {
            result = i;
            break;
        }
    }

    println!("{result}");
}
