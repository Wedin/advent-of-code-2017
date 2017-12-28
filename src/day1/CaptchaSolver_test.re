open Jest;

describe("Simple captcha", () => {
  open Expect;

  test("1122", () => expect(CaptchaSolver.solve("1122")) |> toBe(3));
  test("1111", () => expect(CaptchaSolver.solve("1111")) |> toBe(4));
  test("1234", () => expect(CaptchaSolver.solve("1234")) |> toBe(0));
  test("91212129", () => expect(CaptchaSolver.solve("91212129")) |> toBe(9));
});
