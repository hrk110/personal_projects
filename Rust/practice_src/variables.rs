fn main() {
    // let mut x = 5;
    // println!("The value of x is: {}", x);
    // x = 6;
    // println!("The value of x is: {}", x);
    let x = 5;

    let x = x + 1;

    {
        let x = x * 2;
        println!("The value of x in the inner scope is: {}", x);
    }

    println!("The value of x is: {}", x);

    // Compound Types

    // (1) Tuple
    let tup: (i32, f64, u8) = (100, 1.5, 2); // Type can be different.

    let (x, y, z) = tup;

    println!("The value of x, y, z is: {}, {}, {}", x, y, z);
    println!("The value of x, y, z is: {}, {}, {}", tup.0, tup.1, tup.2);

    // (2) Array
    let a: [i32; 5] = [10, 20, 30, 40, 50]; // Type must be same. fixed length.
    // data is allocated in stack rather than heap.
    println!("The first elements of array a is {}", a[0]);

    let b = [1; 5]; // [1, 1, 1, 1, 1]
    println!("The second elements of array a is {}", b[1]);

    // let out_of_index = a[10]; // runtime error

    // function example
    print_labeled_measurement(5, 'h');
    let a = five();
    println!("The value of a is: {}", a);

    let b = plus_one(1);
    println!("The value of a is: {}", b);

}

fn print_labeled_measurement(value: i32, unit_label: char) {
    println!("The value of x is: {}{}", value, unit_label);
}

fn five() -> i32 {
    5
}

fn plus_one(x: i32) -> i32 {
    x + 1
}