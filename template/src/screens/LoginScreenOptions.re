let id = "Login";
let name = `Demo_Login;
let screen: unit => Navigation.layoutStackChildren =
  () =>
    Navigation.layoutStackChildren(
      ~component=
        Navigation.layoutComponent(
          ~id,
          ~name,
          ~options=
            Navigation.(
              navigationOptions(
                ~topBar=
                  optionsTopBar(
                    ~title=
                      optionsTopBarTitle(~text="Login", ~color="white", ()),
                    ~background=optionsTopBarBackground(~color="#4d089a", ()),
                    (),
                  ),
                (),
              )
            ),
          (),
        ),
    );
