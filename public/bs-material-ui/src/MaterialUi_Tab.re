module Component: {
  type t;
  let string: string => t;
  let callback: (unit => React.element) => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let callback = (v: unit => React.element) => Any(v);
  let element = (v: React.element) => Any(v);
};

module TabIndex: {
  type t;
  let int: int => t;
  let float: float => t;
  let string: string => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let string = (v: string) => Any(v);
};

module Type_enum: {
  type t;
  let button: t;
  let reset: t;
  let submit: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let button = Any("button");
  let reset = Any("reset");
  let submit = Any("submit");
};

module Type: {
  type t;
  let enum: Type_enum.t => t;
  let string: string => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let enum = (v: Type_enum.t) => Any(v);
  let string = (v: string) => Any(v);
};

module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "labelIcon": option(option(string)),
    "textColorInherit": option(option(string)),
    "textColorPrimary": option(option(string)),
    "textColorSecondary": option(option(string)),
    "selected": option(option(string)),
    "disabled": option(option(string)),
    "fullWidth": option(option(string)),
    "wrapped": option(option(string)),
    "wrapper": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~labelIcon: string=?,
      ~textColorInherit: string=?,
      ~textColorPrimary: string=?,
      ~textColorSecondary: string=?,
      ~selected: string=?,
      ~disabled: string=?,
      ~fullWidth: string=?,
      ~wrapped: string=?,
      ~wrapper: string=?,
      unit
    ) =>
    t;
};

type textColor = [ | `Secondary | `Primary | `Inherit];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~centerRipple: option(bool)=?,
    ~component: option(Component.t)=?,
    ~disableTouchRipple: option(bool)=?,
    ~focusRipple: option(bool)=?,
    ~focusVisibleClassName: option(string)=?,
    ~href: option(string)=?,
    ~onBlur: option(ReactEvent.Focus.t => unit)=?,
    ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
    ~onFocusVisible: option(MaterialUi_Types.any)=?,
    ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
    ~onKeyUp: option(ReactEvent.Keyboard.t => unit)=?,
    ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
    ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
    ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
    ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
    ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
    ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
    ~tabIndex: option(TabIndex.t)=?,
    ~_TouchRippleProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~_type: option(Type.t)=?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~disabled: option(bool)=?,
    ~disableFocusRipple: option(bool)=?,
    ~disableRipple: option(bool)=?,
    ~fullWidth: option(bool)=?,
    ~icon: option(React.element)=?,
    ~indicator: option(React.element)=?,
    ~label: option(React.element)=?,
    ~onChange: option(ReactEvent.Form.t => unit)=?,
    ~onClick: option(ReactEvent.Mouse.t => unit)=?,
    ~onFocus: option(ReactEvent.Focus.t => unit)=?,
    ~selected: option(bool)=?,
    ~selectionFollowsFocus: option(bool)=?,
    ~textColor: option(
                  [@bs.string] [
                    | [@bs.as "secondary"] `Secondary
                    | [@bs.as "primary"] `Primary
                    | [@bs.as "inherit"] `Inherit
                  ],
                )
                  =?,
    ~value: option(MaterialUi_Types.any)=?,
    ~wrapped: option(bool)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Tab";
