let parse_input = (path : string) => {
    let programs = Node.Fs.readFileAsUtf8Sync(path) |> Js.String.split("\n");

    let programWithChildren = Array.map(program => Js.String.split("->", program), programs);

    let (prgNames, prgChildren) = Array.fold_left(((accName, accChild), program) => {
        let programName = Js.String.split(" ", program[0])[0];
        let children = Array.length(program) > 1 ? program[1] |> Js.String.split(",") : [||];
        let children = Array.map(child => Js.String.replace(" ", "", child), children);

        switch (programName) {
            | "" => (accName, accChild);
            | _ => ([programName, ...accName], Array.append(children, accChild));
        };
    },([], [||]),  programWithChildren);

    (prgNames, Array.to_list(prgChildren));
};

let bottomTower = (input: string) => {
    let (prgs, chld) = parse_input(input);
    let root = List.find(prgName => {
        let inChildren = try (List.find(name => name == prgName, chld)) {
            | Not_found => "";
        };
        Js.String.length(inChildren) == 0;
    }, prgs);
    Js.log(root);
    root;
};

let run = () => {
    bottomTower("./src/day7/input.txt");
};

run();
