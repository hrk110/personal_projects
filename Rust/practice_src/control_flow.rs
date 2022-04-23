fn main() {
    // control_flow
    let number = 7;
    if number < 5 {
        println!("condition was true.");
    } else {
        println!("condition was false.");
    }

    // error: condition must be bool type.
    // if number { ~~ }

    // if is an expression
    let condition = true;
    let x = if condition {5} else {6};
    println!("The value of x is: {}", x);

    // error, type must be the same.
    // let x = if condition {5} else {"six"};


    // loop
    // loop {
        // println!("again!");
    // }

    let mut count = 0;
    'counting_up: loop {
        println!("count = {}", count);
        let mut remaining = 10;

        loop {
            println!("remaining = {}", remaining);
            if remaining == 9 {
                break;
            }
            if count == 2 {
                break 'counting_up;
            }
            remaining -= 1;
        }

        count += 1;
    }
    println!("End count = {}", count);

    // return from loop
    let mut counter = 0;
    let result = loop {
        counter += 1;

        if counter == 10 {
            break counter * 2;
        }
    };
    println!("The result is: {}", result);

    // while
    let array = [1,2,3,4,5];
    let mut index = 0;

    while index < 5 {
        println!("The value is: {}", array[index]);
        index += 1;
    }

    // for loop used for array
    for element in array {
        println!("The value is {}", element);
    }

    for i in (1..4).rev() {
        println!("{}!", i);
    }
    println!("LIFTOFF!");

    println!("The value is: {}", fibonacci(4));
}

fn fibonacci(n: i32) -> i32 {
    if n <= 2 {
        1
    } else {
        fibonacci(n-1) + fibonacci(n-2)
    }
}
