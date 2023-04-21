// 1157 단어 공부

use std::collections::HashMap;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let chars = input.trim().chars();
    let mut map = HashMap::new();

    for c in chars {
        let count = map.entry(c.to_ascii_uppercase()).or_insert(0);
        *count += 1;
    }

    let (ch, freq) = map
        .iter()
        .max_by(|(_, lhs_v), (_, rhs_v)| lhs_v.cmp(rhs_v))
        .expect("map is empty");
    if map.iter().filter(|&(_, v)| v == freq).count() > 1 {
        println!("?");
    } else {
        println!("{ch}");
    }
}
