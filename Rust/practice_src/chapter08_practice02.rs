use std::io;

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("failed to read input.");
    print!("input: {}", input);

    let mut output = String::new();
    let mut first_char = 'h';

    let mut is_first = true;
    for c in input.chars() {
        if is_first {
            // start with consonant
            if !['a', 'e', 'i', 'o', 'u'].contains(&c) {
                first_char = c;
            }
            // start with vowel
            else {
                output.push(c);
            }
            is_first = false;
        } else {
            if c != '\n' { // eliminate last character (newline)
                output.push(c);
            }
        }
    }
    let output = format!("{}-{}ay", output, first_char);
    println!("output: {}", &output);

}
