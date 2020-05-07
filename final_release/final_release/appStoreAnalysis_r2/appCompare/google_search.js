var gplay = require('google-play-scraper');

const args = process.argv;

var i;
var text = "";
for (i = 3; i < args.length - 1; i++) {
  text += args[i] + " ";
}

text += args[i];

gplay.search({
    term: text,
    num: 1,
    country: args[2],
    fullDetail: true
  }).then(console.log, console.log);