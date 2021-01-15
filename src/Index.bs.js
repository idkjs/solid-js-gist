'use strict';

var SolidJs = require("solid-js");
var Belt_List = require("bs-platform/lib/js/belt_List.js");
var H = require("solid-js/h").default;
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var Dom = require("solid-js/dom");

var $$Node = {};

var HyperScript = {};

var $$Document = {};

var Solid = {};

function div(children, param) {
  return H("div", undefined, Belt_List.toArray(children));
}

function createElement(name, param, param$1) {
  var match = SolidJs.createSignal(10);
  var setCount = match[1];
  var count = match[0];
  var timer = setInterval((function (param) {
          console.log("Hello!", count());
          return setCount(count() + 1 | 0);
        }), 1000);
  SolidJs.onCleanup(function (param) {
        clearInterval(timer);
        
      });
  return div({
              hd: "Hello " + (name + (": " + String(count()))),
              tl: /* [] */0
            }, undefined);
}

var App = {
  createElement: createElement
};

Belt_Option.forEach(Caml_option.nullable_to_opt(document.getElementById("app")), (function (root) {
        Dom.render((function (param) {
                return createElement("Taylor", /* [] */0, undefined);
              }), root);
        
      }));

exports.$$Node = $$Node;
exports.HyperScript = HyperScript;
exports.$$Document = $$Document;
exports.Solid = Solid;
exports.div = div;
exports.App = App;
/*  Not a pure module */
