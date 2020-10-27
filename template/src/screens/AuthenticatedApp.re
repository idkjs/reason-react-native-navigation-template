open ReactNative;
let styles =
  Style.(
    StyleSheet.create({
      "home":
        style(
          ~flex=1.,
          ~alignItems=`center,
          ~justifyContent=`center,
          ~backgroundColor="whitesmoke",
          (),
        ),
    })
  );
let id = "Home";

[@react.component]
let make = () => {
  <View style={styles##home}>
    <Text> "Hello React Native Navigation 👋"->React.string </Text>
    <Text> "AuthenticatedApp"->React.string </Text>
  </View>;
};
