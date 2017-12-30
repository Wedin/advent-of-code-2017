let occurrencesOf = (wordToCheck: string, words) => {
  List.filter((currentWord) => {
    currentWord == wordToCheck;
  }, words);
};

let hasOneOccurenceOfEachWord = (words) => {
  List.for_all((x) => {
    List.length(occurrencesOf(x, words)) == 1;
  }, words);
};

let isValid = (passphrase: string) : bool => {
  Js.String.split(" ", passphrase) |> hasOneOccurenceOfEachWord;
};


let validateMultiple = (passphrases) => {
  Js.String.split("\n", passphrases) |> Array.to_list |> List.filter(x => String.length(x) > 0) |> List.map(isValid)
};

let run = () => {
  let passphrases = Node.Fs.readFileAsUtf8Sync("./src/day4/input.txt");
  let validPassphrases = validateMultiple(passphrases) |> List.fold_left((acc,value) => value ? acc + 1 : acc, 0);
  Js.log(validPassphrases);
  validPassphrases;
};

run();
