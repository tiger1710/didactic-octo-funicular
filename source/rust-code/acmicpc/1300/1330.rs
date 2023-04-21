// 1330 두 수 비교하기

use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).expect("input error");
    let mut input = input.split_whitespace().map(|str| str.parse().expect("can't parse"));
    let a: i32 = input.next().unwrap();
    let b = input.next().unwrap();

    match a.cmp(&b) {
        std::cmp::Ordering::Less => println!("<"),
        std::cmp::Ordering::Equal => println!("=="),
        std::cmp::Ordering::Greater => println!(">"),
    }
}
