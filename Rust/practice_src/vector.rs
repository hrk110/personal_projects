#[derive(Debug)]
enum MultipleTypeForVector {
    Int(i32),
    Float(f64),
    Text(String),
}

fn main() {
    // vector
    let v1: Vec<i32> = Vec::new();
    let v2 = vec![1,2,3];
    let mut v3 = Vec::new();
    v3.push(5);
    v3.push(6);
    v3.push(7);
    v3.push(8);
    println!("The values in v3 is {:?}", v3); // [5, 6, 7, 8]

    let v4 = vec![1, 2, 3, 4, 5];
    let third: &i32 = &v4[2]; // &i32
    println!("The third element is {}", third); // 3

    match v4.get(2) { // Option<i32>
        Some(third) => println!("The third element is {}", third),
        None => println!("There is no third element."),
    }

    let mut v5 = vec![1,2,3,4,5];
    let first = &v5[0]; // immutable borrow
    // v5.push(6); // needs mutable borrow for possible reallocation, so this line causes error
    println!("The first element is: {}", first);

    // iteration
    let v6 = vec![100, 46, 23];
    for i in &v6 { // immutable reference
        println!("{}", i);
    }

    let mut v7 = vec![100, 46, 23];
    for i in &mut v7 { // mutable reference
        *i += 50;
    }
    for i in &v7 {
        println!("{}", i);
    }

    // vector which has multiple types
    let row = vec![
        MultipleTypeForVector::Int(3),
        MultipleTypeForVector::Text(String::from("blue")),
        MultipleTypeForVector::Float(4.5),
    ];
    println!("row: {:?}", row);
}
