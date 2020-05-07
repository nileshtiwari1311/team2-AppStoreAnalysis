var store = require('app-store-scraper');
const args = process.argv; 
store.reviews({
  id: args[2],
  page: 1
})
.then(console.log)
.catch(console.log);