use std::env;


fn main() {
    let all_args: Vec<String> = env::args().collect();
    let args: array = &all_args[1..];

    println!("I got {:?} arguments: {:?}", args.len(), &args);
}
