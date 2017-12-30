open Jest;

describe("High-entropy passphrases", () => {
  open Expect;

  test("aa bb cc dd ee valid", () => expect(PassphraseValidator.isValid("aa bb cc dd ee")) |> toBe(true));
  test("aa bb cc dd aa invalid", () => expect(PassphraseValidator.isValid("aa bb cc dd aa")) |> toBe(false));
  test("aa bb cc dd aaa valid", () => expect(PassphraseValidator.isValid("aa bb cc dd aaa")) |> toBe(true));
});
