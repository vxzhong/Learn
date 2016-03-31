webpackJsonp([2],{

/***/ 7:
/***/ function(module, exports, __webpack_require__) {

	eval("'use strict';\n\nObject.defineProperty(exports, \"__esModule\", {\n  value: true\n});\n\nvar _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if (\"value\" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();\n\nvar _jquery = __webpack_require__(3);\n\nvar _jquery2 = _interopRequireDefault(_jquery);\n\nvar _mustache = __webpack_require__(5);\n\nvar _mustache2 = _interopRequireDefault(_mustache);\n\nvar _Header = __webpack_require__(8);\n\nvar _Header2 = _interopRequireDefault(_Header);\n\n__webpack_require__(9);\n\nfunction _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }\n\nfunction _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError(\"Cannot call a class as a function\"); } }\n\nvar Header = function () {\n  function Header() {\n    _classCallCheck(this, Header);\n  }\n\n  _createClass(Header, [{\n    key: 'render',\n    value: function render(node) {\n      var text = (0, _jquery2.default)(node).text();\n\n      (0, _jquery2.default)(node).html(_mustache2.default.render(_Header2.default, {\n        text: text\n      }));\n    }\n  }]);\n\n  return Header;\n}();\n\nexports.default = Header;\n\n/*****************\n ** WEBPACK FOOTER\n ** ./src/Components/Header.js\n ** module id = 7\n ** module chunks = 2\n **/\n//# sourceURL=webpack:///./src/Components/Header.js?");

/***/ },

/***/ 8:
/***/ function(module, exports) {

	eval("module.exports = \"<header class=\\\"header\\\">{{text}}</header>\\n\";\n\n/*****************\n ** WEBPACK FOOTER\n ** ./src/Components/Header.html\n ** module id = 8\n ** module chunks = 2\n **/\n//# sourceURL=webpack:///./src/Components/Header.html?");

/***/ },

/***/ 9:
/***/ function(module, exports) {

	eval("// removed by extract-text-webpack-plugin\n\n/*****************\n ** WEBPACK FOOTER\n ** ./src/Components/Header.scss\n ** module id = 9\n ** module chunks = 2\n **/\n//# sourceURL=webpack:///./src/Components/Header.scss?");

/***/ }

});