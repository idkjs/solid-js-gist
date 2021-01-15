module Node = {
  type t;
};

module HyperScript = {
  type t;

  [@bs.module "solid-js/h"]
  external make: (string, 'props, array(t)) => t = "default";

  external text: string => t = "%identity";
};

module Document = {
  [@val] [@scope "document"] [@return nullable]
  external getElementById: string => option(Node.t) = "getElementById";
};

module Solid = {
  [@module "solid-js/dom"]
  external render: (unit => HyperScript.t, Node.t) => unit = "render";

  [@module "solid-js"]
  external createSignal: 'a => ((. unit) => 'a, (. 'a) => unit) =
    "createSignal";

  [@module "solid-js"]
  external onCleanup: (unit => unit) => unit = "onCleanup";
};

let div = (~children, ()) =>
  HyperScript.make("div", (), children->Belt.List.toArray);

module App = {
  let createElement = (~name, ~children as _, ()) => {
    let (count, setCount) = Solid.createSignal(10);

    let timer =
      Js.Global.setInterval(
        () => {
          Js.log2("Hello!", count(.)); // Display the proper value 10, 11, 12, etc...
          setCount(. count(.) + 1);
        },
        1000,
      );

    Solid.onCleanup(() => Js.Global.clearInterval(timer));

    // The count value is not updated
    <div>
      {("Hello " ++ name ++ ": " ++ Belt.Int.toString(count(.)))
       ->HyperScript.text}
    </div>;
  };
};

Document.getElementById("app")
->Belt.Option.forEach(root => {
    Solid.render(() => <App name="Taylor" />, root)
  });
