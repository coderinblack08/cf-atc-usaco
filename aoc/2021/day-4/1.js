const { join } = require("path");
const input = require("fs")
  .readFileSync(join(__dirname, "./input.txt"), "utf8")
  .split("\n");

const numbers = input.shift().split(",").map(Number);

function chunk(arr) {
  let chunks = [],
    new_chunk = [];
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === "") {
      chunks.push(new_chunk);
      new_chunk = [];
      continue;
    }
    new_chunk.push(
      arr[i]
        .split(" ")
        .map((x) => parseInt(x.trim()))
        .filter((x) => Number.isNaN(x) === false)
    );
  }
  return [...chunks, new_chunk];
}

const boards = chunk(input.slice(1));
const claimed = boards.map(() => new Set());
const contents = boards.map((x) => {
  const s = {};
  x.forEach((y, i) => y.forEach((z, j) => (s[z] = [i, j])));
  return s;
});

function check_board(idx) {
  // checks rows
  for (let i = 0; i < 5; i++) {
    const row = boards[idx][i];
    let count = 0;
    for (const x of row) {
      if (claimed[idx].has(x)) {
        count++;
      }
    }
    if (count === row.length) {
      return true;
    }
  }
  // check columns
  for (let i = 0; i < 5; i++) {
    const col = boards[idx].map((x) => x[i]);
    let count = 0;
    for (const x of col) {
      if (claimed[idx].has(x)) {
        count++;
      }
    }
    if (count === col.length) {
      return true;
    }
  }
}

function sum_board(i) {
  let sum = 0;
  for (const x of boards[i]) {
    for (const y of x) {
      if (!claimed[i].has(y)) {
        sum += y;
      }
    }
  }
  return sum;
}

outerloop: for (const number of numbers) {
  for (let i = 0; i < boards.length; i++) {
    if (number in contents[i]) {
      claimed[i].add(number);
      if (check_board(i)) {
        console.log(sum_board(i) * number);
        break outerloop;
      }
    }
  }
}
