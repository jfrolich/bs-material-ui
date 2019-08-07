[@bs.deriving jsConverter]
type alignItems = [
  | [@bs.as "flex-start"] `Flex_Start
  | [@bs.as "center"] `Center
];

module Classes = {
  type classesType =
    | Root(string)
    | Gutters(string)
    | Selected(string)
    | Dense(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Gutters(_) => "gutters"
    | Selected(_) => "selected"
    | Dense(_) => "dense";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Gutters(className)
                         | Selected(className)
                         | Dense(className) =>
                           Js.Dict.set(obj, to_string(classType), className)
                         };
                         obj;
                       },
                     )
                   );
};

[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~className: string=?,
    ~dense: bool=?,
    ~disabled: bool=?,
    ~disableGutters: bool=?,
    ~role: string=?,
    ~selected: bool=?,
    ~tabIndex: 'number_f=?,
    ~value: 'union_r6tb=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~key: string=?,
    ~_ref: React.Ref.t(option(Dom.element))=?,
    ~alignItems: string=?,
    ~autoFocus: bool=?,
    ~button: bool=?,
    ~_ContainerProps: Js.t({..})=?,
    ~divider: bool=?,
    ~focusVisibleClassName: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~dense: option(bool)=?,
      ~disabled: option(bool)=?,
      ~disableGutters: option(bool)=?,
      ~role: option(string)=?,
      ~selected: option(bool)=?,
      ~tabIndex: option([ | `Int(int) | `Float(float)])=?,
      ~value:
         option(
           [
             | `String(string)
             | `Int(int)
             | `Float(float)
             | `Array(array(string))
           ],
         )=?,
      ~onFocus: option(ReactEvent.Focus.t => unit)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(option(Dom.element)))=?,
      ~alignItems: option(alignItems)=?,
      ~autoFocus: option(bool)=?,
      ~button: option(bool)=?,
      ~_ContainerProps: option(Js.t({..}))=?,
      ~divider: option(bool)=?,
      ~focusVisibleClassName: option(string)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~className?,
    ~dense?,
    ~disabled?,
    ~disableGutters?,
    ~role?,
    ~selected?,
    ~tabIndex=?
      tabIndex->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~value=?value->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~onFocus?,
    ~onClick?,
    ~key?,
    ~_ref=?ref_,
    ~alignItems=?alignItems->(Belt.Option.map(v => alignItemsToJs(v))),
    ~autoFocus?,
    ~button?,
    ~_ContainerProps?,
    ~divider?,
    ~focusVisibleClassName?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "MenuItem";
