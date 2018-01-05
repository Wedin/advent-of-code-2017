let list_to_string = (l : list(int)) => {
    List.map(string_of_int, l) |> List.fold_left((x, y) => x ++ y, "");
};

let higestWithIndex = (l : list(int)) => {
       List.mapi((value, index) => (value, index), l)
        |> List.fold_left(((highestIndex, highestValue), (currIndex, currValue)) => {
            currValue > highestValue ? (currIndex, currValue) : (highestIndex, highestValue)

        }, (0, min_int));
};

let updateBlocks = (blocks: array(int), index, value) => {
    blocks[index] = 0;
    let rec updateBlocks' = (blocks: array(int), index, value) => {
        switch value {
            | 0 => Array.to_list(blocks)
            | _ => {
                blocks[index] = blocks[index] + 1;
                let nextIndex = (index + 1) mod Array.length(blocks);
                updateBlocks'(blocks, nextIndex, value - 1)
            };
        };
    };

    updateBlocks'(blocks, (index + 1) mod Array.length(blocks), value);
};

let rec redistributeBlocks' = (blocks : list(int), oldStates : list(string), steps) => {
    let hasOldState = List.exists((elem) => elem == list_to_string(blocks), oldStates);
    switch hasOldState {
        | true => steps;
        | _ => {
            let (selectedBankIndex, selectedBank) = higestWithIndex(blocks);
            /* Js.log(Array.of_list(blocks)); */
            let updatedBlocks = updateBlocks(Array.of_list(blocks), selectedBankIndex, selectedBank);
            /* Js.log(Array.of_list(updatedBlocks)); */
            redistributeBlocks'(updatedBlocks, [list_to_string(blocks), ...oldStates], steps + 1);
        };
    };
};

let redistributeBlocks = (blocks : list(int)) => {
    redistributeBlocks'(blocks, [], 0);
};

let run = () => {
    let blocks = [2, 8, 8, 5, 4, 2, 3, 1, 5, 5, 1, 2, 15, 13, 5, 14];
    let numSteps = redistributeBlocks(blocks);
    Js.log(numSteps);
    numSteps;
};

run();
