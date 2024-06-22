const fs = require("fs");
var n = parseInt(
  fs.readFileSync("/dev/stdin").toString().trim().split("\n")
);
for (i = 1; i <= n; i++) {
  for (j = 0; j < n - i; j++) process.stdout.write(" ");
  for (j = 1; j <= i; j++) process.stdout.write("*");
  console.log();
}
for (i = 1; i < n; i++) {
  for (j = 0; j < i; j++) process.stdout.write(" ");
  for (j = 1; j <= n - i; j++) process.stdout.write("*");
  console.log();
}
