open Jest;

describe("High-entropy passphrases", () => {
  open Expect;

  test("0 3 0 1 -3 has 5 steps", () => expect(MazeInstructions.countSteps([|0,3,0,1,-3|])) |> toBe(5));
});
