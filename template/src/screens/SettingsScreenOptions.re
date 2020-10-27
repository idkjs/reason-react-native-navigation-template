let id = "Settings";
let name = `Demo_Settings;
let screen = () =>
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
                    optionsTopBarTitle(~text="Settings", ~color="white", ()),
                  ~background=optionsTopBarBackground(~color="#4d089a", ()),
                  (),
                ),
              ~bottomTab=optionsBottomTab(~text="Settings", ()),
              (),
            )
          ),
        (),
      ),
  );

let push = () => {
  Navigation.pushChild(id, screen());
};
