enum IpAddr {
    V4(u8, u8, u8, u8),
    V6(String),
}

enum Message {
    Quit,                       // unit struct
    Move { x: i32, y: i32},     // struct
    Write(String),              // tuple struct
    ChangeColor(i32, i32, i32), // tuple struct
}

impl Message {
    fn call(&self) {
        // method body here.
    }
}

/* this is included in the prelude:
enum Option<T> {
    None,
    Some(T),
}
*/

fn main() {
    // enum01
    let home = IpAddr::V4(127,0,0,1);
    let loopback = IpAddr::V6(String::from("::1"));

    let m = Message::Write(String::from("hello"));
    m.call();

    // option
    let some_number = Some(5);             // can infer the type: Option<i32>
    let some_string = Some("a string");    // also can infer the type: Option<&str>
    let absent_number: Option<i32> = None; // cannot infer from None, so must annotate the type

    let x: i8 = 5;
    let y: Option<i8> = Some(6);
    // let sum = x + y; // error, because x and y have different types.
    // avoid errors by designating possible null variant to Option<T>.
    // And we can run different code depending on which variant the enum has.


}
