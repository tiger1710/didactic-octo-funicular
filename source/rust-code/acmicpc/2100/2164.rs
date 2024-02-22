// 2164 카드2

use std::collections::VecDeque;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");

    let mut input = input
        .split_whitespace()
        .map(|str| str.parse().expect("parse error"));

    let n = input.next().expect("input error");
    let mut cards: VecDeque<_> = (1..=n).collect();
    loop {
        let throw = cards.pop_front().expect("cards is empty");
        if let Some(top) = cards.pop_front() {
            cards.push_back(top);
        } else {
            println!("{throw}");
            break;
        }
    }
}
