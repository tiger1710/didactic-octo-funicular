// 2484 알람 시계

use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut input = input
        .split_whitespace()
        .map(|str| str.parse().expect("parse error"));
    let h: usize = input.next().expect("input error");
    let m = input.next().expect("input error");

    let alarm = (h * 60 + m + 24 * 60 - 45) % (24 * 60);
    let h = alarm / 60;
    let m = alarm % 60;
    println!("{h} {m}");
}
