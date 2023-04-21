// 10869 사칙연산

use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    // 두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오.
    let mut input = input
        .split_whitespace()
        .map(|str| str.parse().expect("can't parse"));
    let a: i32 = input.next().unwrap();
    let b = input.next().unwrap();

    println!("{} {} {} {} {}", a + b, a - b, a * b, a / b, a % b);
}
