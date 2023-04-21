// 10809 알파벳 찾기

use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    ('a'..='z').for_each(|ch| {
        if let Some(idx) = input.find(ch) {
            print!("{idx} ");
        } else {
            print!("-1 ");
        }
    });
}
