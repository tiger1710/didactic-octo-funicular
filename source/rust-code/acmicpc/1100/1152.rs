// 1152 단어의 개수

use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let ans = input.split_whitespace().count();
    println!("{ans}");
}
