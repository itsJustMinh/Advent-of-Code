use std::fs::File;

mod day1;

const AOC_FUNCTIONS: [fn(File); 1] = [day1::solution];
const INPUT_DIRECTORY: &str = "input/";

fn main() {
    let day: usize;
    let test: bool;

    loop {
        let mut input = String::new();
        print!("Which day would you like to do: ");
        std::io::stdin().read_line(&mut input).unwrap();
        input = input.trim().to_string();

        match input.parse::<usize>() {
            Ok(res) => {
                if (1..=25).contains(&res) {
                    day = res;
                    break;
                }
            }
            Err(_) => (),
        }
    }

    loop {
        let mut input = String::new();
        print!("Are you using the test file [T] or final file [F]? ");
        std::io::stdin().read_line(&mut input).unwrap();

        input = input.to_uppercase();

        match input.as_str() {
            "T" => {
                test = true;
                break;
            }
            "F" => {
                test = false;
                break;
            }
            _ => (),
        }
    }

    let file_path = format!(
        "{INPUT_DIRECTORY}day-{}{}.txt",
        day - 1,
        if test { "-test" } else { "" }
    );

    match File::open(&file_path) {
        Ok(aoc_file) => AOC_FUNCTIONS[day - 1](aoc_file),
        Err(_) => println!("Could not find {file_path}! Exiting..."),
    }
}
