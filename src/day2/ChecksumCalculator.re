let convertRowToArray = (row) => {
  String.length(row) > 0 ? Js.String.split("\t", row) |> Array.map((item) => int_of_string(item)) : [||];
};

let minMaxDiff = (rowInput) => {
  switch rowInput {
    | [||] => 0;
    | row => {
      let rowMin = Array.fold_left(min, 99999999999999999, row);
      let rowMax = Array.fold_left(max, 0, row);
      Js.log(rowMax - rowMin);
      rowMax - rowMin;
    };
  };
};

let convertInput = (input) => {
  Js.String.split("\n", input) |> Array.map(convertRowToArray);
};

let calc = (input) => {
  let converted = convertInput(input);
  let minMaxChecksum = Array.map(minMaxDiff, converted) |> Array.fold_left((x,y) => x+y, 0);
  minMaxChecksum
};

let run = () => {
  let input = Node.Fs.readFileAsUtf8Sync("./src/day2/input.txt");
  let checksum = calc(input);
  Js.log("Result: " ++ string_of_int(checksum));
  checksum;
};

/*run();*/
