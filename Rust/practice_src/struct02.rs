// struct 02

#[derive(Debug)] // use Debug trait
struct Rectangle {
    width: u32,
    height: u32,
}

fn main() {
    // naive version
    let width1 = 30;
    let height1 = 50;
    println!(
        "The area of rectangle is {} square pixels.",
        area1(width1, height1)
    );

    // tuple version
    let rect1 = (30, 50);
    println!(
        "The area of rectangle is {} square pixels.",
        area2(rect1)
    );

    // struct version
    let rect2 = Rectangle{
        width: 30,
        height: 50,
    };
    println!(
        "The area of rectangle is {} square pixels.",
        area3(&rect2)
    );
    // rect2 keeps ownership

    /* without Debug trait...
    println!("rect2 is {}", rect2); // error. structs have no default Display.
    println!("rect2 is {:?}", rect2); // still get an error. debug trait is not implement */
    println!("rect2 is {:?}", rect2); // works fine: rect2 is Rectangle { width: 30, height: 50 }
    println!("rect2 is {:#?}", rect2); // also fine and get result like this:
    /* rect2 is Rectangle {
        width: 30,
        height: 50,
    } */

    // use dbg! macro
    let scale = 2;
    let rect3 = Rectangle {
        width: dbg!(30 * scale),
        height: 30,
    };
    dbg!(&rect3);
    /* results:
    [src/main.rs:49] 30 * scale = 60
    [src/main.rs:53] &rect3 = Rectangle {
        width: 60,
        height: 30,
    } */

}

fn area1(width: u32, height: u32) -> u32 { // Are width and height really related??
    width * height
}

fn area2(dimensions: (u32, u32)) -> u32 {
    dimensions.0 * dimensions.1
    // better, but using index is not good.
    // we're not sure which actually denotes width.
}

fn area3(rect: &Rectangle) -> u32 { // no move from rect2
    rect.width * rect.height
}