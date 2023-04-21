// 2753 윤년

use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let year: usize = input.trim().parse().expect("parse error");

    if (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0) {
        println!("1");
    } else {
        println!("0");
    }
}
