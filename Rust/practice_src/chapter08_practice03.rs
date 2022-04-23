use std::collections::HashMap;
use std::io;

fn main() {
    let mut employee_list = HashMap::new();

    loop {
        println!("\nEnter the command: ");
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("invalid input");

        let command_seq: Vec<&str> = input.split_whitespace().collect();
        if let Some(command) = command_seq.get(0) { // get first word
            match *command { // if command is valid, execute
                "Add" => {
                    if command_seq.len() == 4 && command_seq[2] == "to" {
                        let name = String::from(command_seq[1]);
                        let department = String::from(command_seq[3]);
                        employee_list.entry(name).or_insert(department);
                        println!("Added.");
                    } else {
                        println!("usage: Add [name] to [department]");
                    }
                },
                "Show" => {
                    if let Some(department) = command_seq.get(1) {
                        println!("People in {}:", department);
                        for (key, value) in &employee_list {
                            if value == department { println!("{}", key) }
                        }
                    } else {
                        for department in employee_list.values() {
                            println!("People in {}:", department);
                            for (key, value) in &employee_list {
                                if value == department { println!("{}", key) }
                            }
                        }
                    }
                },
                "Quit" => break,
                _ => println!("invalid command. try again."),
            }
        }

    }
}
