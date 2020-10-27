open ReactNative;
let styles =
  Style.(
    StyleSheet.create({
      "root":
        style(
          ~flex=1.,
          ~alignItems=`center,
          ~justifyContent=`center,
          ~backgroundColor="whitesmoke",
          (),
        ),
    })
  );

let id = "Login";
[@react.component]
let make = () => {
  <View style={styles##root}>
    <Button
      title="Login"
      color="#710ce3"
      onPress={_ => Navigation.setRootOptions(Stacks.mainRoot)->ignore}
    />
  </View>;
};
