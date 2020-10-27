let welcomeScreen: Navigation.layoutStackChildren =
  Navigation.(
    layoutStackChildren(
      ~component=
        Navigation.layoutComponent(
          ~name=`Demo_Home,
          ~options=
            Navigation.navigationOptions(
              ~animations=
                Navigation.optionsAnimations(
                  ~setRoot=Navigation.waitForRender(~waitForRender=true, ()),
                  (),
                ),
              (),
            ),
          (),
        ),
    )
  );

let root =
  Navigation.(
    rootOptions(
      ~root=
        stackOptions(
          ~stack=
            layoutStack(
              ~children=[|welcomeScreen|],
              ~options=
                navigationOptions(
                  ~animations=
                    optionsAnimations(
                      ~setRoot=waitForRender(~waitForRender=true, ()),
                      (),
                    ),
                  (),
                ),
              (),
            ),
          (),
        ),
      (),
    )
  );
let setAuthRoot = () =>
  Navigation.setRoot(Stacks.authenticated) |> Js.Promise.resolve;
let setAppRoot = () =>
  Navigation.setRoot(Stacks.notAuthenticated) |> Js.Promise.resolve;

// Fetch the token from storage then navigate to our appropriate place
let setRoot = () => {
  ReactNativeAsyncStorage.getItem("userToken")
  |> Js.Promise.then_(stringOrNull => {
       // This will switch to the App screen or Auth screen and this loading screen will be unmounted and thrown away.

       Js.log2("CHECKING_AUTH_TOKEN", stringOrNull);
       switch (Js.Null.toOption(stringOrNull)) {
       | None => Js.Promise.resolve(setAppRoot())
       | Some(_stringOrNull) => Js.Promise.resolve(setAuthRoot())
       };
     });
};
let isLoggedIn = true;
// Register all screens before setting the root.
RegisterScreens.register();
// This is how you do conditional navigation basically.
Navigation.onAppLaunched(() => {
  SetDefaultOptions.setDefaultOptions();
  setRoot() |> Js.Promise.then_(_result => {Js.Promise.resolve()}) |> ignore;
});
