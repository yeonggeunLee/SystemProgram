use std::collections::BTreeMap;
use std::io;

struct Student {
    midterm_score: i32,
    final_score: i32,
}

fn main() {
    let mut input = String::new();
    let mut num_students = String::new();

    println!("Enter the number of students: ");
    io::stdin().read_line(&mut num_students).expect("Failed to read line");
    let num_students: i32 = num_students.trim().parse().expect("Invalid input");

    let mut students: BTreeMap<String, Student> = BTreeMap::new();

    for _ in 0..num_students {
        let mut name = String::new();
        let mut midterm_score = String::new();
        let mut final_score = String::new();

        println!("Enter student name: ");
        io::stdin().read_line(&mut name).expect("Failed to read line");
        let name = name.trim().to_string();

        println!("Enter midterm score: ");
        io::stdin().read_line(&mut midterm_score).expect("Failed to read line");
        let midterm_score: i32 = midterm_score.trim().parse().expect("Invalid input");

        println!("Enter final score: ");
        io::stdin().read_line(&mut final_score).expect("Failed to read line");
        let final_score: i32 = final_score.trim().parse().expect("Invalid input");

        students.insert(name, Student { midterm_score, final_score });
    }

    println!("Student Information:");
    for (name, student) in &students {
        println!("Name: {}, Midterm: {}, Final: {}", name, student.midterm_score, student.final_score);
    }

    let mut search_name = String::new();
    println!("Enter a name to search: ");
    io::stdin().read_line(&mut search_name).expect("Failed to read line");
    let search_name = search_name.trim();

    match students.get(search_name) {
        Some(student) => {
            println!("Student found: Name: {}, Midterm: {}, Final: {}", search_name, student.midterm_score, student.final_score);
        },
        None => {
            println!("Student not found.");
        }
    }
}

