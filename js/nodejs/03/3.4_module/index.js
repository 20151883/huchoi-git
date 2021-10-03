const { odd, even } = require("./var.js");
const checknum = require("./func.js");

function checkStringOddOrEven(str) {
    if (str.length % 2) {
        return odd;
    } else {
        return even;
    }
}

console.log(checknum(10));
console.log(checkStringOddOrEven("eve"));