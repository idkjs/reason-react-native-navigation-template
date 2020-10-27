// run this by replacing index.js with `require('./src/SimpleRootExample.bs.js');`

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

// Register all screens before setting the root.
RegisterScreens.register();
// This is how you do conditional navigation basically.
Navigation.onAppLaunched(() => {
  Navigation.setRoot(root) |> Js.Promise.resolve |> ignore
});
