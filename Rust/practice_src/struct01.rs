// struct 01

// struct definition
struct User {
    active: bool,
    username: String,
    email: String,
    sign_in_count: u64,
}
// reference type(&str) can be used as field, but then we must set "lifetime".

// tuple struct: name the whole struct, but do not have names of each field
struct Color(i32, i32, i32);
struct Point(i32, i32, i32);

// Unit-like struct: without any fields
struct AlwaysEqual;

fn main() {
    // creating an instance
    let mut user1 = User {
        email: String::from("someone@example.com"),
        username: String::from("someusername123"),
        active: true,
        sign_in_count: 1,
    }; // keys can be in any order.

    user1.email = String::from("anotheremail@example.com");

    let user2 = User {
        email: String::from("another@example.com"),
        ..user1 // struct update syntax: using user1's data
    };
    // user1 instance can no longer be used here, because user1's username, whose type is String, is moved to user2.

    // tuple struct instance
    let black = Color(0,0,0);
    let origin = Point(0,0,0);
    // function which takes Color as parameter cannot take Point as parameter

    // unit-like struct instance
    let subject = AlwaysEqual;

}

// As a return value of a function
fn build_user(email: String, username: String) -> User {
    User {
        email, // field init shorthand: parameter and key have the same name
        username,
        active: true,
        sign_in_count: 1
    }
}