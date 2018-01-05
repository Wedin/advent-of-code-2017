/* Helper since parsing file includes empty lines */
let input_to_int_list = (path : string) => {
  let instructions = Node.Fs.readFileAsUtf8Sync(path) |> Js.String.split("\n");
  let rec inner = (rows, acc) => {
    switch (rows) {
      | [] => List.rev(acc);
      | [hd, ...tl] => {
        String.length(hd) > 0 ? inner(tl, [int_of_string(hd), ...acc]) : inner(tl, acc);
      };
    };
  };
  inner(Array.to_list(instructions), []);
};

let rec step = (numSteps:int, index:int, instructions : array(int), modifier) : int =>  {
  switch (Array.get(instructions, index)) {
    | currentInstruction => {
      /* instructions[index] = instructions[index] + 1; */
      instructions[index] = modifier(instructions[index]);
      step(numSteps + 1, currentInstruction + index, instructions, modifier);
    };
    | exception Invalid_argument("index out of bounds") => numSteps;
  }
};

let countSteps = (instructions: array(int), modifier) :int => {
  step(0, 0, instructions, modifier);
};

let addOneModifier = (elem) => {
  elem + 1;
};

let strangeJumpModifier = (elem) => {
  elem >= 3 ? elem - 1 : elem + 1;
};

let run = () => {
  let instructions = "./src/day5/input.txt" |> input_to_int_list |> Array.of_list;
  let numSteps = countSteps(instructions, addOneModifier);
  Js.log(numSteps);
  numSteps;
};

let run_step2 = () => {
  let instructions = "./src/day5/input.txt" |> input_to_int_list |> Array.of_list;
  let numSteps = countSteps(instructions, strangeJumpModifier);
  Js.log(numSteps);
  numSteps;
};

/* run_step2(); */
