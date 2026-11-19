// 2798 블랙잭

use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("Failed to read from stdin");
    let mut input = input
        .split_whitespace()
        .map(|str| str.parse().expect("parse error"));

    let _ = input.next().expect("input error");
    let m = input.next().expect("input error");
    let cards: Vec<usize> = input.collect();

    let mut ans = 0;
    cards.iter().enumerate().for_each(|(i, card1)| {
        cards.iter().enumerate().skip(i + 1).for_each(|(k, card2)| {
            cards.iter().skip(k + 1).for_each(|card3| {
                let sum = card1 + card2 + card3;
                if sum <= m {
                    ans = ans.max(sum);
                }
            });
        });
    });

    println!("{ans}");
}
