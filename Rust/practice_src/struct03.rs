// struct 03
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

// method
impl Rectangle {
    fn area(&self) -> u32 { // "&self" is equivalent to "self: &Self". borrow the instance immutably.
    // other option: &mut self (mutable), self(rarely used)
        self.width * self.height
    }

    // method which have other parameter
    fn can_hold(&self, rect: &Rectangle) -> bool {
        self.width > rect.width && self.height > rect.height
    }

    // associated function, not method (first parameter is not self)
    fn square(size: u32) -> Rectangle { // used as a constructor
        Rectangle {
            width: size,
            height: size,
        }
    }
}

fn main() {
    let rect1 = Rectangle {
        width: 30,
        height: 50,
    };
    println!("The area of the rectangle is {} square pixels.", rect1.area());

    let rect2 = Rectangle {
        width: 10,
        height: 40,
    };
    let rect3 = Rectangle {
        width: 60,
        height: 45,
    };
    println!("Can rect1 hold rect2? {}", rect1.can_hold(&rect2));
    println!("Can rect1 hold rect3? {}", rect1.can_hold(&rect3));

    let sq = Rectangle::square(3);
    println!("sq is {:?}", sq); // sq is Rectangle { width: 3, height: 3 }
}
