
let numbers = [4; 2; 7; 2; 9; 4; 2; 6]

(* Calculate the mean using a list fold. *)
let calculate_mean numbers =
  let total = List.fold_left (+) 0 numbers in
  float_of_int total /. float_of_int (List.length numbers)

(* Sort the numbers and find the middle value. *)
let calculate_median numbers =
  let sorted = List.sort compare numbers in
  let n = List.length sorted in
  let middle = n / 2 in
  if n mod 2 = 1 then
    float_of_int (List.nth sorted middle)
  else
    float_of_int
      (List.nth sorted (middle - 1) + List.nth sorted middle)
    /. 2.0

(* Count occurrences and return every value tied for the highest frequency. *)
let calculate_mode numbers =
  let frequencies =
    List.fold_left
      (fun counts number ->
        if List.mem_assoc number counts then
          List.map
            (fun (value, count) ->
              if value = number then (value, count + 1)
              else (value, count))
            counts
        else
          counts @ [ (number, 1) ])
      []
      numbers
  in
  let highest =
    List.fold_left
      (fun current (_, count) -> max current count)
      0
      frequencies
  in
  frequencies
  |> List.filter (fun (_, count) -> count = highest)
  |> List.map fst
  |> List.sort compare

let () =
  if numbers = [] then
    print_endline "The list cannot be empty."
  else (
    Printf.printf "Numbers: ";
    List.iter (Printf.printf "%d ") numbers;
    print_newline ();
    Printf.printf "Mean: %.2f\n" (calculate_mean numbers);
    Printf.printf "Median: %.2f\n" (calculate_median numbers);
    Printf.printf "Mode: ";
    calculate_mode numbers
    |> List.iter (Printf.printf "%d ");
    print_newline ()
  )
