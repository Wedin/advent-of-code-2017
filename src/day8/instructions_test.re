open Jest;

describe("I Heard You Like Registers", () => {
  open Expect;

  test("Largest value in register for demo is 1", () => expect(Instructions.runPath("./src/day8/demo_input.txt")) |> toEqual(1));
});
