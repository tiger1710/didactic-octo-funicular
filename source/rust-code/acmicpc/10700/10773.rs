// 10773 제로

use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");

    let mut input = input.split_whitespace().map(|str| str.parse().expect("parse error")).skip(1);
    let mut stack: Vec<usize> = Vec::new();

    while let Some(num) = input.next() {
        match num {
            0 => {
                stack.pop();
            },
            _ => {
                stack.push(num);
            }
        }
    }

    let sum: usize = stack.iter().sum();
    println!("{sum}");
}
