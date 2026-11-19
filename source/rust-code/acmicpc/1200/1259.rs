// 1259 팰린드롬수

use std::io::{self, Read};
use std::fmt::Write;

fn main() {
    let mut input = String::new();
    let mut output = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");

    let mut nums: Vec<_> = input.split_whitespace().collect();
    nums.pop();

    for num in nums {
        let str = num.chars();
        let rev = num.chars().rev();
        if str.eq(rev) {
            writeln!(output, "yes").expect("Unable to write");
        } else {
            writeln!(output, "no").expect("Unable to write");
        }
    }

    print!("{output}");
}
