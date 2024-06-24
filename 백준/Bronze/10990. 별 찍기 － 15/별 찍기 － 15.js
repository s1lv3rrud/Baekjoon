const fs = require("fs");
var n = parseInt(
  fs.readFileSync("/dev/stdin").toString().trim().split("\n")
);
for (i = 0; i < n; i++) {
  for (j = 0; j < n - i - 1; j++) process.stdout.write(" ");
  process.stdout.write("*");
  for (j = 0; j < 2 * (i -1) + 1; j++) process.stdout.write(" ");
  if (i != 0) process.stdout.write("*");
  console.log();
}
