use std::{env, fs::File, io::Write};

mod day1;

const AOC_FUNCTIONS: [fn(File); 1] = [day1::solution];
const INPUT_DIRECTORY: &str = "input/";

fn main() {
    let args = env::args().collect::<Vec<String>>();

    let day = set_day(&args);
    let test = set_test(&args);

    let file_path = format!(
        "{INPUT_DIRECTORY}day-{}{}.txt",
        day,
        if test { "-test" } else { "" }
    );

    match File::open(&file_path) {
        Ok(aoc_file) => AOC_FUNCTIONS[day - 1](aoc_file),
        Err(_) => println!("Could not find {file_path}! Exiting..."),
    }
}

fn set_day(args: &[String]) -> usize {
    if let Some(day) = args
        .iter()
        .position(|arg| arg == "--day")
        .and_then(|idx| args.get(idx + 1))
        .and_then(|val| val.parse::<usize>().ok())
        .filter(|&num| (1..=25).contains(&num))
    {
        return day;
    }

    loop {
        let mut input = String::new();
        print!("Which day would you like to do: ");
        std::io::stdout().flush().unwrap();
        std::io::stdin().read_line(&mut input).unwrap();
        input = input.trim().to_string();

        if let Ok(res) = input.parse::<usize>() {
            if (1..=25).contains(&res) {
                return res;
            }
        }
    }
}

fn set_test(args: &[String]) -> bool {
    if let Some(test) = args
        .iter()
        .position(|arg| arg == "--test")
        .and_then(|idx| args.get(idx + 1))
    {
        return test == "true";
    }

    loop {
        let mut input = String::new();
        print!("Are you using the test file [T] or final file [F]? ");
        std::io::stdout().flush().unwrap();
        std::io::stdin().read_line(&mut input).unwrap();

        input = input.trim().to_uppercase();

        match input.as_str() {
            "T" => return true,
            "F" => return false,
            _ => (),
        }
    }
}
