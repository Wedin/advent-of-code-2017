let subEnd = (stream:string, start:int) => {
    String.sub(stream, start, String.length(stream) - start);
};

let rec inGarbage = (stream:string, score:int, currLevel: int) => {
    switch stream {
        | "" => score; /* Can this really happen? */
        | _ => {
            switch stream.[0] {
                | '>' => countScore(subEnd(stream, 1), score, currLevel);
                | '!' => inGarbage(subEnd(stream, 2), score, currLevel);
                | _ => inGarbage(subEnd(stream, 1), score, currLevel);
            };
        };
    };
} and countScore = (stream:string, score:int, currLevel: int) => {
    switch stream {
        | "" => score;
        | _ => {
            let subbed = subEnd(stream, 1);
            switch (stream.[0]) {
                | '{' => countScore(subbed, score, currLevel + 1);
                | '}' => countScore(subbed, score + currLevel, currLevel - 1);
                | '<' => inGarbage(subbed, score, currLevel);
                | '!' => inGarbage(subEnd(stream, 2), score, currLevel);
                | _ => countScore(subbed, score, currLevel);
            };
        };
    };
};

let score = (stream: string) => {
    countScore(stream, 0, 0);
};

let run = () => {
    let input = Node.Fs.readFileAsUtf8Sync("./src/day9/input.txt") |> String.trim;
    let result = score(input);
    Js.log(result);
};

run();
