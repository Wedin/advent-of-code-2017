module InstructionsDb = Map.Make(String);

let highestEver = ref(0);

type instruction = {
    register: string,
    modifier: (int, int) => int,
    modifier_amount: int,
    target_register: string,
    comparer: (int, int) => bool,
    target_value: int
};

let getModifier = (modifier: string) => {
    switch modifier {
        | "inc" => (+)
        | "dec" => (-)
        | _ => raise(Not_found)
    };
};

let getConditionCompare = (comparer: string) => {
    switch comparer {
        | ">" => (>)
        | "<" => (<)
        | ">=" => (>=)
        | "<=" => (<=)
        | "!=" => (!=)
        | "==" => (==)
        |  _ => raise(Not_found)
    };
};

let parseInstructions = (path: string) => {
    let inputInstructions = Node.Fs.readFileAsUtf8Sync(path) |> Js.String.split("\n");

    let instructions = Array.fold_left((acc, instruction) => {
        let firstIndex = Js.String.indexOf(" ", instruction);
        let name = Js.String.substring(0, firstIndex, instruction) |> Js.String.trim;
        let rest = Js.String.substringToEnd(firstIndex, instruction);

        let ifIndex = Js.String.indexOf("if", rest);
        let [|modifier, modifier_amount|] = Js.String.substring(0, ifIndex, rest) |> Js.String.trim |> Js.String.split(" ");
        let [|target_register, comparer, target_value|] = Js.String.substringToEnd(ifIndex + 3, rest)
            |> Js.String.trim
            |> Js.String.split(" ");
        let instruction = {
            register: name,
            modifier: getModifier(modifier),
            modifier_amount: int_of_string(modifier_amount),
            target_register: target_register,
            comparer: getConditionCompare(comparer),
            target_value: int_of_string(target_value)
        };
        [instruction, ...acc];
    }, [], inputInstructions);

    List.rev(instructions);
};

let createRegisters = (instructions) => {
    List.fold_left((accMap, instruction) => {
        InstructionsDb.add(instruction.register, 0, accMap);
    }, InstructionsDb.empty, instructions);
};

let printMapLine = (key, value) => {
    print_string("key: " ++ key ++ " val " ++ string_of_int(value));
};

let printMap = (map) => {
    InstructionsDb.iter(printMapLine, map);
};

let findHigest = (registers) => {
    InstructionsDb.bindings(registers)
        |> List.map(((_, value)) => value)
        |> List.fold_left(max, min_int);
};

let runInstructions = (instructions, registers) => {

    List.fold_left((registers, instruction) => {

        let currentHigest = findHigest(registers);
        if (currentHigest > highestEver^) {
            highestEver := currentHigest;
        };

        let targetRegisterValue = InstructionsDb.find(instruction.target_register, registers);
        let registerValue = InstructionsDb.find(instruction.register, registers);
        if (instruction.comparer(targetRegisterValue, instruction.target_value)) {
            InstructionsDb.add(instruction.register, instruction.modifier(registerValue, instruction.modifier_amount), registers);
        } else {
            registers;
        };
    }, registers, instructions);
};

let runPath = (path: string) => {
    let instructions = parseInstructions(path);
    let registers = createRegisters(instructions);
    let modifiedRegisters = runInstructions(instructions, registers);
    findHigest(modifiedRegisters);
};

let run = () => {
    let highest = runPath("./src/day8/input.txt");
    Js.log(highest);
    Js.log(highestEver^);
};

/* run(); */
