fn main() {
    // ownership02:reference and borrowing
    let s1 = String::from("hello");
    let len = calculate_length(&s1); // s1's ownership does not move. just a reference.
    println!("The length of '{}' is {}.", s1, len);

    let s2 = String::from("hello");
    change(&s2);

    let mut s3 = String::from("hello");
    change_modified(&mut s3); // mutable reference

    // multiple reference for the same data
    let mut s4 = String::from("hello");
    let r1 = &s4;
    let r2 = &s4; // no problem
    let r3 = &mut s4;
    // println!("{}, {}, and {}", r1, r2, r3); // error. we cannot have mutable reference when we have immutable reference for the same data.

    let mut s5 = String::from("hello");
    let r4 = &s5;
    let r5 = &s5; // no problem
    println!("{} and {}", r4, r5);
    let r6 = &mut s5;
    println!("{}", r6); // no problem, because the scope of r4 & r5 ends at line 22 (last used)

    // prevent dangling reference
    // let reference_to_nothing = dangle();


}

fn calculate_length(s: &String) -> usize {
    s.len()
}// s does not have ownership, so nothing happens.

fn change(some_string: &String) {
    // some_string.push_str(", world"); // error! cannot modify borrowed value.
}

fn change_modified(some_string: &mut String) {
    some_string.push_str(", world");
}

/*
fn dangle() -> &String {
    let s = String::from("hello");
    &s
}// s is dropped here, so return value is dangling reference!
*/
// solution is this:
fn no_dangle() -> String {
    let s = String::from("hello");
    s
}// s is moved to return value