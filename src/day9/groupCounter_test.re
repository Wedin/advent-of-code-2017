open Jest;

describe("Count groups", () => {
  open Expect;
  test("{} has score 1", () =>
    expect(GroupCounter.groupScore("{}")) |> toEqual(1)
  );
  test("{{{}}} has score 1", () =>
    expect(GroupCounter.groupScore("{{{}}}")) |> toEqual(6)
  );
  test("{{},{}} has score 1", () =>
    expect(GroupCounter.groupScore("{{},{}}")) |> toEqual(5)
  );
  test("{{{},{},{{}}}} has score 1", () =>
    expect(GroupCounter.groupScore("{{{},{},{{}}}}")) |> toEqual(16)
  );
  test("{<a>,<a>,<a>,<a>} has score 1", () =>
    expect(GroupCounter.groupScore("{<a>,<a>,<a>,<a>}")) |> toEqual(1)
  );
  test("{{<ab>},{<ab>},{<ab>},{<ab>}} has score 1", () =>
    expect(GroupCounter.groupScore("{{<ab>},{<ab>},{<ab>},{<ab>}}")) |> toEqual(9)
  );
  test("{{<!!>},{<!!>},{<!!>},{<!!>}} has score 1", () =>
    expect(GroupCounter.groupScore("{{<!!>},{<!!>},{<!!>},{<!!>}}")) |> toEqual(9)
  );
  test("{{<a!>},{<a!>},{<a!>},{<ab>}} has score 1", () =>
    expect(GroupCounter.groupScore("{{<a!>},{<a!>},{<a!>},{<ab>}}")) |> toEqual(3)
  );
});

describe("Count garbage", () => {
  open Expect;
  test("{} has score 0", () =>
    expect(GroupCounter.countGarbage("{}")) |> toEqual(0)
  );
  test("<random characters> has score 17", () =>
    expect(GroupCounter.countGarbage("<random characters>")) |> toEqual(17)
  );
  test("<<<<> has score 3", () =>
    expect(GroupCounter.countGarbage("<<<<>")) |> toEqual(3)
  );
  test("<{!>}> has score 2", () =>
    expect(GroupCounter.countGarbage("<{!>}>")) |> toEqual(2)
  );
  test("<!!> has score 0", () =>
    expect(GroupCounter.countGarbage("<!!>")) |> toEqual(0)
  );
  test("<!!!!> has score 0", () =>
    expect(GroupCounter.countGarbage("<!!!!>")) |> toEqual(0)
  );
  test("<{o\"i!a,<{i<a> has score 0", () =>
    expect(GroupCounter.countGarbage("<{o\"i!a,<{i<a>")) |> toEqual(10)
  );

});