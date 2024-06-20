const fs = require("fs");
var n = parseInt(fs.readFileSync("/dev/stdin").toString().trim().split("\n"));
for (i = 1; i <= n; i++) {
  for (j = 0; j < i; j++) process.stdout.write("*");
  for (j = (n - i) * 2; j > 0; j--) process.stdout.write(" ");
  for (j = 0; j < i; j++) process.stdout.write("*");
  console.log();
}
for (i = n - 1; i >= 1; i--) {
  for (j = 0; j < i; j++) process.stdout.write("*");
  for (j = (n - i) * 2; j > 0; j--) process.stdout.write(" ");
  for (j = 0; j < i; j++) process.stdout.write("*");
  console.log();
}
