// 1436 영화감독 숌

use std::io::{self, Read};
// use std::fmt::Write;

fn main() {
    let mut input = String::new();
    // let mut output = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");

    let n: usize = input.trim().parse().expect("Failed to parse input");

    let mut count: usize = 0;
    let mut num: usize = 0;

    while count < n {
        num += 1;
        if num.to_string().contains("666") {
            count += 1;
        }
    }

    println!("{num}");
}
