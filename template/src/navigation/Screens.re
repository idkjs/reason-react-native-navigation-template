// IMPORTANT:
// IF YOU ADD A SCREEN BELOW, ALSO ADD IT TO THE ARRAY BELOW
// otherwise the screen will not be registered and the app
// will crash
type t = [
  | `Demo_Home
  | `Demo_AuthenticatedApp
  | `Demo_UnAuthenticatedApp
  | `Demo_Settings
  | `Demo_Login
];

// important, make sure that every screen is listed here
// ideally we generate this list automatically by using a ppx like
// https://github.com/janestreet/ppx_enumerate
// the only problem is that this PPX doesn't support bucklescript
// (isn't packaged as a binary NPM package)
// this could be useful in other parts of the app as well
let screens: array(t) = [|
  `Demo_Home,
  `Demo_Login,
  `Demo_AuthenticatedApp,
  `Demo_Settings,
  `Demo_UnAuthenticatedApp,
|];

external toString: t => string = "%identity";
