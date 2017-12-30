open Jest;


describe("Spiral Memory: coordinates", () => {
  open Expect;

  test("1 coordinates (0,0)", () => expect(SpiralMemory.getCoordinates(1)) |> toEqual((0,0)));
  test("2 coordinates (1,0)", () => expect(SpiralMemory.getCoordinates(2)) |> toEqual((1,0)));
  test("3 coordinates (1,1)", () => expect(SpiralMemory.getCoordinates(3)) |> toEqual((1,1)));
  test("4 coordinates (0,1)", () => expect(SpiralMemory.getCoordinates(4)) |> toEqual((0,1)));
  test("5 coordinates (-1,1)", () => expect(SpiralMemory.getCoordinates(5)) |> toEqual((-1,1)));
  test("6 coordinates (-1,0)", () => expect(SpiralMemory.getCoordinates(6)) |> toEqual((-1,0)));
  test("7 coordinates (-1,-1)", () => expect(SpiralMemory.getCoordinates(7)) |> toEqual((-1,-1)));
  test("8 coordinates (0, -1)", () => expect(SpiralMemory.getCoordinates(8)) |> toEqual((0,-1)));
  test("9 coordinates (1,-1)", () => expect(SpiralMemory.getCoordinates(9)) |> toEqual((1,-1)));
  test("10 coordinates (2,-1)", () => expect(SpiralMemory.getCoordinates(10)) |> toEqual((2,-1)));
  test("13 coordinates (2,2)", () => expect(SpiralMemory.getCoordinates(13)) |> toEqual((2,2)));
  test("15 coordinates (0,2)", () => expect(SpiralMemory.getCoordinates(15)) |> toEqual((0,2)));
  test("16 coordinates (-1,2)", () => expect(SpiralMemory.getCoordinates(16)) |> toEqual((-1,2)));
  test("17 coordinates (-2,2)", () => expect(SpiralMemory.getCoordinates(17)) |> toEqual((-2,2)));
  test("18 coordinates (-2,1)", () => expect(SpiralMemory.getCoordinates(18)) |> toEqual((-2,1)));
  test("19 coordinates (-2,0)", () => expect(SpiralMemory.getCoordinates(19)) |> toEqual((-2,0)));
  test("20 coordinates (-2,-1)", () => expect(SpiralMemory.getCoordinates(20)) |> toEqual((-2,-1)));
  test("21 coordinates (-2,-2)", () => expect(SpiralMemory.getCoordinates(21)) |> toEqual((-2,-2)));
  test("22 coordinates (-1,-2)", () => expect(SpiralMemory.getCoordinates(22)) |> toEqual((-1,-2)));
  test("23 coordinates (0,-2)", () => expect(SpiralMemory.getCoordinates(23)) |> toEqual((0,-2)));
  test("24 coordinates (1,-2)", () => expect(SpiralMemory.getCoordinates(24)) |> toEqual((1,-2)));
  test("25 coordinates (2,-2)", () => expect(SpiralMemory.getCoordinates(25)) |> toEqual((2,-2)));
});



describe("Spiral Memory", () => {
  open Expect;

  test("1 carried 0 steps", () => expect(SpiralMemory.calcDistance(1)) |> toBe(0));
  test("12 carried 3 steps", () => expect(SpiralMemory.calcDistance(12)) |> toBe(3));
  test("23 carried 2 steps", () => expect(SpiralMemory.calcDistance(23)) |> toBe(2));
  test("1024 carried 31 steps", () => expect(SpiralMemory.calcDistance(1024)) |> toBe(31));
});

