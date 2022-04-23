use std::env;
use std::process;
use minigrep::Config;

// eprintln! print error message to stderr.

fn main() {
    // Accept command line arguments.
    let args: Vec<String> = env::args().collect(); // turn iterator into vector, with collect().
    let config = Config::new(&args) // returns Result<Config, &'static str>
        .unwrap_or_else(|err| { // unwrap if Ok
            eprintln!("Problem parsing arguments: {}", err); // |err| is argument which outer unwrap has and is passed to inner closure
            // This prints: Problem parsing arguments: not enough arguments
            process::exit(1);
    });

    // println!("search for {} in file {}", config.query, config.filename);
    // deal with potential error later.


    /* For improvement:
    (1) Prevent main() from taking multiple functionality // solved
    (2) Group related variables to one struct // solved
    (3) Prepare detailed error message for users // solved
    (4) Put in one place the error handling codes for future maintenance
    => moved everything that is not main() function (namely, except error handling) into lib.rs.
    */

    // All we have to do is detect error because run return nothing in success case.
    if let Err(e) = minigrep::run(config) {
        eprintln!("Application error: {}", e);
        process::exit(1);
    }
}
