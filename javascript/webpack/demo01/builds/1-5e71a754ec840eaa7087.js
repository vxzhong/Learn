webpackJsonp([1],[
/* 0 */,
/* 1 */,
/* 2 */
/***/ function(module, exports, __webpack_require__) {

	eval("'use strict';\n\nObject.defineProperty(exports, \"__esModule\", {\n  value: true\n});\n\nvar _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if (\"value\" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();\n\nvar _jquery = __webpack_require__(3);\n\nvar _jquery2 = _interopRequireDefault(_jquery);\n\nvar _Button = __webpack_require__(4);\n\nvar _Button2 = _interopRequireDefault(_Button);\n\nvar _mustache = __webpack_require__(5);\n\nvar _mustache2 = _interopRequireDefault(_mustache);\n\n__webpack_require__(6);\n\nfunction _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }\n\nfunction _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError(\"Cannot call a class as a function\"); } }\n\nvar Button = function () {\n  function Button(link) {\n    _classCallCheck(this, Button);\n\n    this.link = link;\n  }\n\n  _createClass(Button, [{\n    key: 'onClick',\n    value: function onClick(event) {\n      event.preventDefault();\n      alert(this.link);\n    }\n  }, {\n    key: 'render',\n    value: function render(node) {\n      var text = (0, _jquery2.default)(node).text();\n\n      // Render our button\n      (0, _jquery2.default)(node).html(_mustache2.default.render(_Button2.default, {\n        text: text,\n        link: this.link\n      }));\n\n      // Attach our listeners\n      (0, _jquery2.default)('.button').click(this.onClick.bind(this));\n    }\n  }]);\n\n  return Button;\n}();\n\nexports.default = Button;\n\n/*****************\n ** WEBPACK FOOTER\n ** ./src/Components/Button.js\n ** module id = 2\n ** module chunks = 1\n **/\n//# sourceURL=webpack:///./src/Components/Button.js?");

/***/ },
/* 3 */,
/* 4 */
/***/ function(module, exports) {

	eval("module.exports = \"<a class=\\\"button\\\" href=\\\"{{link}}\\\">{{text}}</a>\\n\";\n\n/*****************\n ** WEBPACK FOOTER\n ** ./src/Components/Button.html\n ** module id = 4\n ** module chunks = 1\n **/\n//# sourceURL=webpack:///./src/Components/Button.html?");

/***/ },
/* 5 */,
/* 6 */
/***/ function(module, exports) {

	eval("// removed by extract-text-webpack-plugin\n\n/*****************\n ** WEBPACK FOOTER\n ** ./src/Components/Button.scss\n ** module id = 6\n ** module chunks = 1\n **/\n//# sourceURL=webpack:///./src/Components/Button.scss?");

/***/ }
]);