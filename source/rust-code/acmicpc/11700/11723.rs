// 11723 집합

use std::io::{self, Write, BufWriter};


fn main() {
    let mut input = String::new();
    let mut writer = BufWriter::new(io::stdout());
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    let m = input.trim().parse::<u32>().unwrap_or(0);
    let mut set: u32 = 0b00000000000000000000;
    for _ in 0..m {
        let mut line = String::new();
        io::stdin()
            .read_line(&mut line)
            .expect("Failed to read line");
        let mut line = line.split_whitespace();
        let command = line.next().unwrap();
        let num = line.next().unwrap_or_default().parse::<u32>().unwrap_or(1);
        let bit = 0b00000000000000000001 << (num - 1);
        match command {
            "add" => {
                set |= bit;
            }
            "remove" => {
                set &= !bit;
            }
            "check" => {
                if set & bit == bit {
                    writeln!(writer, "1").unwrap();
                } else {
                    writeln!(writer, "0").unwrap();
                }
            }
            "toggle" => {
                set ^= bit;
            }
            "all" => {
                set = 0b11111111111111111111;
            }
            "empty" => {
                set = 0b00000000000000000000;
            }
            _ => {}
        }
    }
}
