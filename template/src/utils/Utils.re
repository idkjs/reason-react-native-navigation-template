let nullToOption = stringOrNull =>
  Js.Promise.resolve(stringOrNull->Js.Null.toOption);
let nullableToOption = stringOrNull =>
  Js.Promise.resolve(stringOrNull->Js.Nullable.toOption);
