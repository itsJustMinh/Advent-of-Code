use std::{
    env,
    fs::{self},
    io::Write,
};

mod day1;
mod day2;
mod day3;

const AOC_FUNCTIONS: [fn(&[String]); 3] = [day1::solution, day2::solution, day3::solution];

fn main() {
    let args = env::args().collect::<Vec<String>>();

    let day = set_day(&args);
    let test = set_test(&args);
    let mut input_dir = "input/";


    if let Some(dir) = &args
        .iter()
        .position(|arg| arg == "--input-dir")
        .and_then(|idx| args.get(idx + 1))
    {
        if let Ok(metadata) = fs::metadata(dir) {
            if metadata.is_dir() {
                input_dir = dir;
            }
        }
    }

    let file_path = format!(
        "{input_dir}day-{}{}.txt",
        day,
        if test { "-test" } else { "" }
    );

    match fs::read_to_string(&file_path) {
        Ok(file_string) => {
            let lines = file_string
                .trim()
                .lines()
                .map(|line| line.to_string())
                .collect::<Vec<String>>();
            AOC_FUNCTIONS[day - 1](&lines);
        }
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
