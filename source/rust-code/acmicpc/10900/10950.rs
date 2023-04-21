// 10950 A+B - 3

use std::io::{self, Read};
use std::fmt::Write;

fn main() {
    let mut input = String::new();
    let mut output = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut input = input
        .split_whitespace()
        .map(|str| str.parse().expect("can't parse"));

    let t = input.next().unwrap();

    (0..t).for_each(|_| {
        let a = input.next().unwrap();
        let b = input.next().unwrap();
        let sum = a + b;
        writeln!(output, "{sum}").expect("can't write to output");
    });
    println!("{output}");
}
