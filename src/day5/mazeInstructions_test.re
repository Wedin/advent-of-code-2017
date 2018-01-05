open Jest;

describe("High-entropy passphrases: 1", () => {
  open Expect;

  test("0 3 0 1 -3 has 5 steps", () => expect(MazeInstructions.countSteps([|0,3,0,1,-3|], MazeInstructions.addOneModifier)) |> toBe(5));
});


describe("High-entropy passphrases: 2", () => {
  open Expect;

  test("0 3 0 1 -3 has 10 steps", () => expect(MazeInstructions.countSteps([|0,3,0,1,-3|], MazeInstructions.strangeJumpModifier)) |> toBe(10));
});
