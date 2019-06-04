use std::env;

fn main() {
  let args: Vec<String> = env::args_os().collect();
  println!("{:?}", args);
}
