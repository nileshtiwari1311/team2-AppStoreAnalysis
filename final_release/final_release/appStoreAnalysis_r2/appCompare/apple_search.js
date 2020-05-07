var store = require('app-store-scraper');
 
const args = process.argv;

var i;
var text = "";
for (i = 3; i < args.length - 1; i++) {
  text += args[i] + " ";
}

text += args[i];

store.search({
  term: text,
  num: 1,
  country : args[2]
})
.then(console.log)
.catch(console.log);