fn main() {
    // ownership: rule of how to manege memory
    // compiler checks if memory is properly used

    // stack: last in, first out. push, pop. size must be fixed and known at compile
    // heap: memory allocator finds empty space and returns pointer.
    // function's local variables and passed value are pushed onto stack

    // scope of variables
    let s1 = "hello"; // s is string literal type, and valid until the end of current scope
    // string literal is immutable(?) and size is not known
    // s1 += ", world"; // error
    println!("s1: {}", s1); // hello, world

    let mut s2 = String::from("hello"); // request memory -> when we return the allocated memory? (look at the bottom)
    s2.push_str(", world");
    println!("s2: {}", s2); // hello, world

    // (1): move
    let x = 5;
    let y = x; // x and y are equal to 5, and they are pushed onto stack.

    let s3 = String::from("hello");
    let s4 = s3;
    println!("s4: {}", s4); // hello
    // String has pointer to memory, length, capacity, and they are stored in stack.
    // if s3 and s4 share the same pointer to heap region, that could lead to "double free error", that is, freeing memory twice.
    // So, Rust moves s3 into s4 (s3 is now invalid!)
    // therefore, this causes an error
    // println!("s3: {}", s3); // error: borrow of moved value

    // Rust will never create deep copy of heap data.

    // (2): clone (= make a deep copy)
    let s5 = String::from("hello");
    let s6 = s5.clone(); // heap data is copied by clone() method.
    println!("s5: {}, s6: {}", s5, s6);

    // (3): copy (valid for stack-only data)
    println!("x = {}, y = {}", x, y);
    // size of integer type are know and integer is in stack.

    // passing value to function
    let s7 = String::from("hello");
    takes_ownership(s7); // s7 is moved to s and s7 is no longer valid.
    // println!("s7: {}", s7); // error

    let z = 4;
    makes_copy(z);
    println!("z: {}", z); // works fine

    // return value
    let s8 = gives_ownership(); // s8 has the return value from gives_ownership.
    println!("s8: {}", s8);

    let s9 = String::from("hello");
    let s10 = takes_and_gives_ownership(s9); // s9 is moved to ss, and ss is moved to s10.
    println!("s10: {}", s10);

}// this scope is over, so memory allocated for s2 is returned (achived by drop function)

fn takes_ownership(s: String) {
    println!("in takes_ownership function. s: {}", s);
}// s goes out of scope and drop is called. memory for s is freed here.

fn makes_copy(i: i32) {
    println!("in makes_copy function. i: {}", i);
}// nothing happens.

fn gives_ownership() -> String {
    let some_string = String::from("hello");
    some_string
}// some_string is moved to s8.

fn takes_and_gives_ownership(ss: String) -> String {
    ss
}// ss is moved to s10.