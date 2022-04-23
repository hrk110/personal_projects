
fn main() {
    // hashmap
    use std::collections::HashMap;

    // construction
    let mut scores = HashMap::new();
    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 50);

    // another way
    let teams = vec![String::from("Blue"), String::from("Yellow")];
    let initial_score = vec![10, 50];
    let mut scores2: HashMap<_, _>
        = teams.into_iter().zip(initial_score.into_iter()).collect();

    let field_name = String::from("Favorite color");
    let field_value = String::from("Blue");
    let mut map = HashMap::new();
    map.insert(field_name, field_value);
    // println!("field_name and field_value is {} and {}", field_name, field_value); // they were already moved.

    let team_name = String::from("Blue");
    let score = scores.get(&team_name);
    if let Some(score_value) = score {
        println!("score is {}", score_value);
    }
    for (key, value) in &scores {
        println!("{}: {}", key, value);
    }

    let mut scores3 = HashMap::new();
    scores3.insert(String::from("Blue"), 10);
    scores3.insert(String::from("Blue"), 25);
    println!("{:?}", scores3); // {"Blue": 25}, overwritten

    println!("{:?}", scores3.entry(String::from("Blue"))); // Entry(OccupiedEntry { key: "Blue", value: 25, .. })
    println!("{:?}", scores3.entry(String::from("Yellow"))); // Entry(VacantEntry("Yellow"))
    scores3.entry(String::from("Yellow")).or_insert(50);
    scores3.entry(String::from("Blue")).or_insert(50);
    println!("{:?}", scores3); // {"Blue": 25, "Yellow": 50}

    let text = "hello world wonderful world";
    let mut map2 = HashMap::new();
    for word in text.split_whitespace() {
        let count = map2.entry(word).or_insert(0);
        // or_insert() returns mutable reference if value exists
        // inserts parameter as new value and returns mutable reference if value does not exists.
        // therefore, in either case, count is reference to value which is associated to word.
        *count += 1;
    }
    println!("{:?}", map2);

}
