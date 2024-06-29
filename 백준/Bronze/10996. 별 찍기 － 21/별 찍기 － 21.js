const fs = require("fs");
var n = parseInt(fs.readFileSync("/dev/stdin").toString().trim().split("\n"));
for (i = 0; i < n * 2; i++) {
  if (i % 2 == 0) {
    for (j = 0; j < n; j++) {
      if (j % 2 == 0) process.stdout.write("*");
      else process.stdout.write(" ");
    }
  } else {
    for (j = 0; j < n; j++) {
      if (j % 2 == 0) process.stdout.write(" ");
      else process.stdout.write("*");
    }
  }
  console.log();
}
