open Jest;

describe("Recursive circus: lowest program", () => {
  open Expect;

  test("Find lowest program", () => expect(RecursiveCircus.bottomTower("./src/day7/demo_input.txt")) |> toEqual("tknk"));
});
