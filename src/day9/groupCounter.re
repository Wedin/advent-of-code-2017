let rec inGarbage = (stream:string, score:int, currLevel: int) => {

    switch stream {
        | "" => score;
        | _ => {
            let subbed = String.sub(stream, 1, String.length(stream) - 1);
            switch stream.[0] {
                | '>' => countScore(subbed, score, currLevel);
                | _ => inGarbage(subbed, score, currLevel);
            };
        };
    };
}
and inGroup = (stream:string, score:int, currLevel: int) => {
    switch stream {
        | "" => score;
        | _ => {
            let subbed = String.sub(stream, 1, String.length(stream) - 1);
            Js.log("gr: "++stream ++ " " ++  string_of_int(score) ++ " " ++  string_of_int(currLevel));
            switch (stream.[0]) {
                | '{' => inGroup(subbed, score, currLevel + 1);
                | '<' => inGarbage(subbed, score, currLevel);
                | '}' => {
                    switch (currLevel - 1) {
                        | 0 => countScore(subbed, score + currLevel, currLevel - 1);
                        | _ => inGroup(subbed, score + currLevel, currLevel - 1);
                    };
                };
                | _ => inGroup(subbed, score, currLevel);
            };
        };
    };
} and countScore = (stream:string, score:int, currLevel: int) => {
    switch stream {
        | "" => score;
        | _ => {
            let subbed = String.sub(stream, 1, String.length(stream) - 1);
            Js.log("cs "++stream ++ " " ++  string_of_int(score) ++ " " ++  string_of_int(currLevel));
            switch (stream.[0]) {
                | '{' => inGroup(subbed, score, currLevel + 1);
                | '}' => countScore(subbed, score + currLevel, currLevel - 1);
                | '<' => inGarbage(subbed, score, currLevel);
                | _ => countScore(subbed, score, currLevel);
            };
        };
    };
};

let score = (stream: string) => {
    countScore(stream, 0, 0);
};