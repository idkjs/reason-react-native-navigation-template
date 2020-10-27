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
[@react.component]
let make = () => {
  <View style=styles##root> <Text> "Home"->React.string </Text> </View>;
};
