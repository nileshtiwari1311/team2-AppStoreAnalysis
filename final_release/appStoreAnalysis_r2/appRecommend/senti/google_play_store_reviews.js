var gplay = require('google-play-scraper');
const args = process.argv;
gplay.reviews({
  appId: args[2],
  sort: gplay.sort.NEWEST,
  num: 500
})
.then(console.log)
.catch(console.log);