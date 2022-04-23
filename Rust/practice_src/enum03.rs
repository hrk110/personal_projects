fn main() {
    // enum 03
    let config_max = Some(3u8);
    match config_max {
        Some(max) => println!("The maximum is configured to be {}", max),
        _ => (), // this is annoying
    }

    if let Some(max) = config_max {
        println!("The maximum is configured to be {}", max);
    }
}
