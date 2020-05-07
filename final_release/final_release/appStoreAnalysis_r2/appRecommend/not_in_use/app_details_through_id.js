var gplay = require('google-play-scraper');
const args = process.argv; 
gplay.app({appId: args[2] })
  .then(console.log, console.log);