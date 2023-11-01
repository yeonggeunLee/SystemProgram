use std::io;

fn main() {
    let mut rows = String::new();
    let mut cols = String::new();

    println!("Enter the number of rows: ");
    io::stdin().read_line(&mut rows).expect("Failed to read line");
    let rows: usize = rows.trim().parse().expect("Invalid input");

    println!("Enter the number of columns: ");
    io::stdin().read_line(&mut cols).expect("Failed to read line");
    let cols: usize = cols.trim().parse().expect("Invalid input");

    if rows == 0 || cols == 0 {
        println!("Invalid matrix size. Rows and columns must be greater than 0.");
        return;
    }

    let mut matrix_a: Vec<Vec<i32>> = vec![vec![0; cols]; rows];
    let mut matrix_b: Vec<Vec<i32>> = vec![vec![0; cols]; rows];
    let mut matrix_c: Vec<Vec<i32>> = vec![vec![0; cols]; rows];

    println!("Enter elements of matrix A:");
    for i in 0..rows {
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read line");
        let elements: Vec<i32> = input.split_whitespace()
            .map(|s| s.trim().parse().expect("Invalid input"))
            .collect();
        if elements.len() != cols {
            println!("Invalid number of elements in row. Expected: {} elements.", cols);
            return;
        }
        matrix_a[i] = elements;
    }

    println!("Enter elements of matrix B:");
    for i in 0..rows {
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read line");
        let elements: Vec<i32> = input.split_whitespace()
            .map(|s| s.trim().parse().expect("Invalid input"))
            .collect();
        if elements.len() != cols {
            println!("Invalid number of elements in row. Expected: {} elements.", cols);
            return;
        }
        matrix_b[i] = elements;
    }

    for i in 0..rows {
        for j in 0..cols {
            matrix_c[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    }

    println!("Resulting matrix C:");
    for i in 0..rows {
        for j in 0..cols {
            print!("{} ", matrix_c[i][j]);
        }
        println!();
    }
}

