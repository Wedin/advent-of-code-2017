open Jest;

describe("Count groups", () => {
  open Expect;
  test("{} has score 1", () =>
    expect(GroupCounter.score("{}")) |> toEqual(1)
  );
  test("{{{}}} has score 1", () =>
    expect(GroupCounter.score("{{{}}}")) |> toEqual(6)
  );
  test("{{},{}} has score 1", () =>
    expect(GroupCounter.score("{{},{}}")) |> toEqual(5)
  );
  test("{{{},{},{{}}}} has score 1", () =>
    expect(GroupCounter.score("{{{},{},{{}}}}")) |> toEqual(16)
  );
  test("{<a>,<a>,<a>,<a>} has score 1", () =>
    expect(GroupCounter.score("{<a>,<a>,<a>,<a>}")) |> toEqual(1)
  );
  test("{{<ab>},{<ab>},{<ab>},{<ab>}} has score 1", () =>
    expect(GroupCounter.score("{{<ab>},{<ab>},{<ab>},{<ab>}}")) |> toEqual(9)
  );
  test("{{<!!>},{<!!>},{<!!>},{<!!>}} has score 1", () =>
    expect(GroupCounter.score("{{<!!>},{<!!>},{<!!>},{<!!>}}")) |> toEqual(9)
  );
  /* test("{{<a!>},{<a!>},{<a!>},{<ab>}} has score 1", () =>
    expect(GroupCounter.score("{{<a!>},{<a!>},{<a!>},{<ab>}}")) |> toEqual(3)
  ); */
});