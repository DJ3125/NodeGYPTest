//import {hello} from "./../build/Release/hello.node";
//const {getAbsolutePath} = require("./..");
require("module-alias/register");
const {hello} = require("@nodeBinaries/hello.node");

console.log(hello());