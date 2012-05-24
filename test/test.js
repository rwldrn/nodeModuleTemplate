var moduleName = require('../build/Release/moduleName.node');
var moduleLib = require('../lib/ModuleName')

var world = "World";
console.log("c binding interface "+moduleName.hello(world));

console.log("lib interface "+moduleLib.hello(world));
  
