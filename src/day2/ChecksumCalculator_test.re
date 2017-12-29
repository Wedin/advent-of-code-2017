open Jest;

describe("Example spreadsheet", () => {
  open Expect;

  test("5 1 9 5", () => expect("5\t1\t9\t5" |> ChecksumCalculator.convertRowToArray |> ChecksumCalculator.minMaxDiff) |> toBe(8));
  test("7 5 3", () => expect("7\t5\t3" |> ChecksumCalculator.convertRowToArray |> ChecksumCalculator.minMaxDiff) |> toBe(4));
  test("2 4 6 8", () => expect("2\t4\t6\t8" |> ChecksumCalculator.convertRowToArray |> ChecksumCalculator.minMaxDiff) |> toBe(6));

  test("5 1 9 5\n7 5 3\n2 4 6 8\n", () => expect(ChecksumCalculator.calc("5\t1\t9\t5\n7\t5\t3\n2\t4\t6\t8")) |> toBe(18));
});
