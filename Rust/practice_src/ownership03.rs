fn main() {
    // ownership03
    let mut s1 = String::from("hello world");
    let word = first_word(&s1);
    println!("word: {}", word); // 5
    s1.clear(); // what does the value of word mean?

    let s2 = String::from("hello world");
    let hello = &s2[0..5];  // String slice. has pointer to starting position and length
    let world = &s2[6..11];

    let mut s3 = String::from("hello world");
    let word2 = first_word_2(&s3);
    // s3.clear(); // need mutable reference. word is immutable reference(slice) and active here, so this causes an error.
    println!("word: {}", word2); // hello

    let s3 = "Hello, world!"; // type is &str and this is immutable reference
    let a = [1, 2, 3, 4, 5];
    let slice = &a[1..3]; // &[2, 3], and the type is &[i32].

}

fn first_word(s: &String) -> usize {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() { // (index, reference to element)
        if item == b' ' {
            return i;
        }
    }
    s.len()
}

fn first_word_2(s: &str) -> &str {
    let bytes = s.as_bytes();
    for (i,  &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }
    &s[..]
}