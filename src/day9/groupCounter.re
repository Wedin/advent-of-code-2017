/* Todo: rewrite to work with char arrays instead of strings.. 🙈 */

let subEnd = (stream:string, start:int) => {
    String.sub(stream, start, String.length(stream) - start);
};

let rec inGroupGarbage = (stream:string, score:int, currLevel: int) => {
    switch stream {
        | "" => score; /* Can this really happen? */
        | _ => {
            switch stream.[0] {
                | '>' => countGroupScore(subEnd(stream, 1), score, currLevel);
                | '!' => inGroupGarbage(subEnd(stream, 2), score, currLevel);
                | _ => inGroupGarbage(subEnd(stream, 1), score, currLevel);
            };
        };
    };
} and countGroupScore = (stream:string, score:int, currLevel: int) => {
    switch stream {
        | "" => score;
        | _ => {
            let subbed = subEnd(stream, 1);
            switch (stream.[0]) {
                | '{' => countGroupScore(subbed, score, currLevel + 1);
                | '}' => countGroupScore(subbed, score + currLevel, currLevel - 1);
                | '<' => inGroupGarbage(subbed, score, currLevel);
                | '!' => inGroupGarbage(subEnd(stream, 2), score, currLevel);
                | _ => countGroupScore(subbed, score, currLevel);
            };
        };
    };
};

let groupScore = (stream: string) => {
    countGroupScore(stream, 0, 0);
};

let rec inGarbage = (stream:string, score:int) => {
    switch stream {
        | "" => score; /* Can this really happen? */
        | _ => {
            switch stream.[0] {
                | '>' => countGarbageScore(subEnd(stream, 1), score);
                | '!' => inGarbage(subEnd(stream, 2), score);
                | _ => inGarbage(subEnd(stream, 1), score + 1);
            };
        };
    };
} and countGarbageScore = (stream:string, score:int) => {
    switch stream {
        | "" => score;
        | _ => {
            let subbed = subEnd(stream, 1);
            switch (stream.[0]) {
                | '{' => countGarbageScore(subbed, score);
                | '}' => countGarbageScore(subbed, score);
                | '<' => inGarbage(subbed, score);
                | '!' => inGarbage(subEnd(stream, 2), score);
                | _ => countGarbageScore(subbed, score);
            };
        };
    };
};

let countGarbage = (stream: string) => {
    countGarbageScore(stream, 0);
};

let run = () => {
    let input = Node.Fs.readFileAsUtf8Sync("./src/day9/input.txt") |> String.trim;
    /* let result = groupScore(input); */
    let result = countGarbage(input);
    Js.log(result);
};

run();
