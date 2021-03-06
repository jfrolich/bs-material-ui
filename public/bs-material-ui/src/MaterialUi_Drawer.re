type anchor = [ | `Bottom | `Left | `Right | `Top];

module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "docked": option(option(string)),
    "paper": option(option(string)),
    "paperAnchorLeft": option(option(string)),
    "paperAnchorRight": option(option(string)),
    "paperAnchorTop": option(option(string)),
    "paperAnchorBottom": option(option(string)),
    "paperAnchorDockedLeft": option(option(string)),
    "paperAnchorDockedTop": option(option(string)),
    "paperAnchorDockedRight": option(option(string)),
    "paperAnchorDockedBottom": option(option(string)),
    "modal": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~docked: string=?,
      ~paper: string=?,
      ~paperAnchorLeft: string=?,
      ~paperAnchorRight: string=?,
      ~paperAnchorTop: string=?,
      ~paperAnchorBottom: string=?,
      ~paperAnchorDockedLeft: string=?,
      ~paperAnchorDockedTop: string=?,
      ~paperAnchorDockedRight: string=?,
      ~paperAnchorDockedBottom: string=?,
      ~modal: string=?,
      unit
    ) =>
    t;
};

module TransitionDuration_shape = {
  type t = {
    .
    "appear": option(option(MaterialUi_Types.Number.t)),
    "enter": option(option(MaterialUi_Types.Number.t)),
    "exit": option(option(MaterialUi_Types.Number.t)),
  };
  [@bs.obj]
  external make:
    (
      ~appear: MaterialUi_Types.Number.t=?,
      ~enter: MaterialUi_Types.Number.t=?,
      ~exit: MaterialUi_Types.Number.t=?,
      unit
    ) =>
    t;
};

module TransitionDuration: {
  type t;
  let int: int => t;
  let float: float => t;
  let shape: TransitionDuration_shape.t => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let shape = (v: TransitionDuration_shape.t) => Any(v);
};

type variant = [ | `Permanent | `Persistent | `Temporary];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~anchor: option(
               [@bs.string] [
                 | [@bs.as "bottom"] `Bottom
                 | [@bs.as "left"] `Left
                 | [@bs.as "right"] `Right
                 | [@bs.as "top"] `Top
               ],
             )
               =?,
    ~_BackdropProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~elevation: option(MaterialUi_Types.Number.t)=?,
    ~_ModalProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~onClose: option(ReactEvent.Synthetic.t => unit)=?,
    ~_open: option(bool)=?,
    ~_PaperProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~_SlideProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~transitionDuration: option(TransitionDuration.t)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "permanent"] `Permanent
                  | [@bs.as "persistent"] `Persistent
                  | [@bs.as "temporary"] `Temporary
                ],
              )
                =?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Drawer";
