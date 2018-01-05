open Jest;

describe("Memory Realloc", () => {
  open Expect;

  test("Get one higest with index", () => expect(MemoryRealloc.higestWithIndex([0,2,7,0])) |> toEqual((2, 7)));
  test("Get first higest with index", () => expect(MemoryRealloc.higestWithIndex([0,2,1,2])) |> toEqual((1, 2)));


  test("0 2 7 2 has 5 cycles", () => expect(MemoryRealloc.redistributeBlocks([0,2,7,0])) |> toBe(5));
});
