fn main() {
    // string
    let mut s1 = String::new(); // empty string

    let s2 = "initial string".to_string();
    let s3 = String::from("initial string"); // equivalent to the line above

    let mut s4 = String::from("foo");
    let s5 = "bar";
    s4.push_str(s5); // parameter is &str type, so move does not occur.
    println!("s4 is {}", s4); // s4 is foobar

    let mut s6 = String::from("lo");
    s6.push('l');
    println!("s6 is {}", s6); // s6 is lol

    let s7 = String::from("Hello, ");
    let s8 = String::from("world!");
    let s9 = s7 + &s8; // + operator takes &str as parameter, so we use reference
    /* take ownership of s7, and append a copy of s8 */
    // println!("s7, s8, s9 is {}, {}, {}", s7, s8, s9); // s7 is moved and can no longer be used, so this causes error.
    println!("s9 is {}", s9); // s9 is Hello, world!

    let s10 = String::from("tic");
    let s11 = String::from("tac");
    let s12 = String::from("toe");
    let s13 = format!("{}-{}-{}", s10, s11, s12);
    println!("s13 is {}", s13); // s13 is tic-tac-toe
    /* s10, s11, s12 are just borrowed, not moved */

    let s14 = String::from("hello");
    // let h = s14[0]; // error, because each character uses more than 1 byte.
    for c in s14.chars() {
        println!("{}", c); // works fine
    }
    for c in "こんにちは".chars() {
        println!("{}", c); // also works fine
    }
    for b in "さようなら".bytes() {
        println!("{}", b); // 15 scalar values, because each character needs 3 bytes:
        // 227 129 149 227 130 136 227 129 134 227 129 170 227 130 137
    }
}