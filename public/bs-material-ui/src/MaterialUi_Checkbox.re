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

module Edge: {
  type t;
  let start: t;
  let _end: t;
  let _false: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let start = Any("start");
  let _end = Any("end");
  let _false = Any(false);
};

module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "checked": option(option(string)),
    "disabled": option(option(string)),
    "indeterminate": option(option(string)),
    "colorPrimary": option(option(string)),
    "colorSecondary": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~checked: string=?,
      ~disabled: string=?,
      ~indeterminate: string=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      unit
    ) =>
    t;
};

type color = [ | `Default | `Primary | `Secondary];

type size = [ | `Medium | `Small];

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
    ~onClick: option(ReactEvent.Mouse.t => unit)=?,
    ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
    ~onFocus: option(ReactEvent.Focus.t => unit)=?,
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
    ~style: option(ReactDOMRe.Style.t)=?,
    ~children: option('children)=?,
    ~className: option(string)=?,
    ~disableFocusRipple: option(bool)=?,
    ~edge: option(Edge.t)=?,
    ~checked: option(bool)=?,
    ~checkedIcon: option(React.element)=?,
    ~classes: option(Classes.t)=?,
    ~color: option(
              [@bs.string] [
                | [@bs.as "default"] `Default
                | [@bs.as "primary"] `Primary
                | [@bs.as "secondary"] `Secondary
              ],
            )
              =?,
    ~disabled: option(bool)=?,
    ~disableRipple: option(bool)=?,
    ~icon: option(React.element)=?,
    ~id: option(string)=?,
    ~indeterminate: option(bool)=?,
    ~indeterminateIcon: option(React.element)=?,
    ~inputProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~onChange: option(ReactEvent.Form.t => unit)=?,
    ~required: option(bool)=?,
    ~size: option(
             [@bs.string] [
               | [@bs.as "medium"] `Medium
               | [@bs.as "small"] `Small
             ],
           )
             =?,
    ~value: option(MaterialUi_Types.any)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Checkbox";
