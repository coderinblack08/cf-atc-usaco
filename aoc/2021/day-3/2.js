// read file input.txt and split on newline
const { join } = require("path");
let oxygen = 0,
  co2 = 0;
const input = require("fs")
  .readFileSync(join(__dirname, "./input.txt"), "utf8")
  .split("\n");
let copy = [...input];
for (let i = 0; i < input[0].length; i++) {
  let ones = 0,
    zeros = 0;
  for (const line of copy) {
    if (line[i] === "1") ones++;
    else zeros++;
  }
  copy = copy.filter((x) => (ones >= zeros ? x[i] === "1" : x[i] === "0"));
  if (copy.length === 1) {
    oxygen = parseInt(copy[0], 2);
    break;
  }
}

copy = [...input];
for (let i = 0; i < input[0].length; i++) {
  let ones = 0,
    zeros = 0;
  for (const line of copy) {
    if (line[i] === "1") ones++;
    else zeros++;
  }
  copy = copy.filter((x) => (ones >= zeros ? x[i] === "0" : x[i] === "1"));
  if (copy.length === 1) {
    co2 = parseInt(copy[0], 2);
    break;
  }
}

console.log(oxygen * co2);
