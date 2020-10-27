let settingStack =
  Navigation.(
    layoutStackChildren(
      ~component=
        layoutComponent(
          ~id="Settings",
          ~name=`Demo_Settings,
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
    )
  );
let loginStack =
  Navigation.(
    layoutStack(
      ~id="Login",
      ~children=[|LoginScreenOptions.screen()|],
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
    )
  );
let homeStack =
  Navigation.(
    layoutStackChildren(
      ~component=
        layoutComponent(
          ~id="Home",
          ~name=`Demo_Home,
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
    )
  );
let bottomTabs: Navigation.optionsBottomStack =
  Navigation.optionsBottomStack(
    ~id="BottomTabs",
    ~children=[|homeStack, settingStack|],
    ~options=
      Navigation.navigationOptions(
        ~bottomTabs=
          Navigation.optionsBottomTabs(
            ~drawBehind=true,
            ~translucent=true,
            ~backgroundColor="red",
            (),
          ),
        (),
      ),
    (),
  );
let notLoggedIn: Navigation.layoutStackChildren =
  Navigation.(
    layoutStackChildren(
      ~component=
        Navigation.layoutComponent(
          ~name=`Demo_UnAuthenticatedApp,
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
let loggedIn: Navigation.layoutStackChildren =
  Navigation.(
    layoutStackChildren(
      ~component=
        Navigation.layoutComponent(
          ~name=`Demo_AuthenticatedApp,
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

let root = stack =>
  Navigation.(
    rootOptions(
      ~root=
        stackOptions(
          ~stack=
            layoutStack(
              ~children=[|stack|],
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

let notAuthenticated = root(notLoggedIn);
let authenticated = root(loggedIn);
let mainRoot =
  Navigation.rootOptions(~root=Navigation.stackOptions(~bottomTabs, ()), ());
